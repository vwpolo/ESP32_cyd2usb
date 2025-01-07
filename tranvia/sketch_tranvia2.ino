
#include <WiFiManager.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <lvgl.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <vector>
#include <set>
#include <algorithm>



#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS



//TFT_eSPI tft = TFT_eSPI(); // Inicializa el objeto de la pantalla

SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// Touchscreen coordinates: (x, y) and pressure (z)
int x, y, z;



struct Parada {
  String nombre;
  int id[3] = {0, 0, 0}; // Inicializa cada elemento a 0
};


// Array de paradas
Parada * listado = nullptr;
size_t numParadas = 0;  // Contador de paradas


String paradaActual ="PASEO DE LOS OLVIDADOS";
//tiempo de llegada. 6 maximo. suelen ser 4, 2 en cada direccion
String tiempos[6]={"","","","","",""};

String lastUpdate="";


//pantallas.
lv_obj_t * info;
lv_obj_t * ajustes;

//etiquetas de texto
lv_obj_t * titulo;
lv_obj_t * horarios;
lv_obj_t * timestamp;

lv_obj_t * etiquetas[6];






// Get the Touchscreen data
void touchscreen_read(lv_indev_t * indev, lv_indev_data_t * data) {
  // Checks if Touchscreen was touched, and prints X, Y and Pressure (Z)
  if(touchscreen.tirqTouched() && touchscreen.touched()) {
    // Get Touchscreen points
    TS_Point p = touchscreen.getPoint();
    // Calibrate Touchscreen points with map function to the correct width and height
    x = map(p.x, 200, 3700, 1, SCREEN_WIDTH);
    y = map(p.y, 240, 3800,  SCREEN_HEIGHT,1);
    z = p.z;

    data->state = LV_INDEV_STATE_PRESSED;

    // Set the coordinates
    data->point.x = x;
    data->point.y = y;

    // Print Touchscreen info about X, Y and Pressure (Z) on the Serial Monitor
    Serial.print("X = ");
    Serial.print(x);
    Serial.print(" | Y = ");
    Serial.print(y);
    //Serial.print(" | Pressure = ");
    //Serial.print(z);
    Serial.println();
  }
  else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}













void create_lv_screen_info(){

  info = lv_obj_create(NULL);
  
  titulo = lv_label_create(info);
  lv_label_set_text(titulo, paradaActual.c_str());
  lv_obj_set_size(titulo, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_align(titulo, LV_ALIGN_TOP_LEFT, 4, 3);
  lv_obj_set_style_text_font((lv_obj_t*) titulo, &lv_font_montserrat_18, 0);
  lv_obj_set_style_text_color((lv_obj_t*) titulo, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);

  horarios = lv_list_create(info);
  lv_obj_set_style_bg_color(horarios, lv_color_hex(0x3b0b0b0), LV_PART_MAIN);
  lv_obj_set_style_pad_row(horarios, 5, 0);
  lv_obj_set_size(horarios, lv_pct(90), 180);
  lv_obj_align_to(horarios, titulo, LV_ALIGN_OUT_BOTTOM_LEFT, 5, 5);

  lv_obj_t * blanco= lv_label_create(horarios);
  lv_label_set_text(blanco, "");
  lv_obj_set_style_bg_color(blanco, lv_color_hex(0x3b0b0b0), LV_PART_MAIN);

  for (int i = 0; i < 6; i++) {
        etiquetas[i] = lv_label_create(horarios);
        lv_label_set_text(etiquetas[i], "");
        lv_obj_set_style_bg_color(etiquetas[i], lv_color_hex(0x3b0b0b0), LV_PART_MAIN);
  }

  timestamp = lv_label_create(info);
  lv_label_set_text(timestamp, "");
  lv_obj_align(timestamp, LV_ALIGN_BOTTOM_LEFT, 3, -3);

  lv_obj_t * btn1 = lv_button_create(info);
  lv_obj_add_event_cb(btn1, event_handler_btn1, LV_EVENT_CLICKED, NULL);
  lv_obj_align(btn1, LV_ALIGN_BOTTOM_MID, 0, -4);
  lv_obj_t * label1 = lv_label_create(btn1);
  lv_label_set_text(label1, LV_SYMBOL_SETTINGS);
  lv_obj_center(label1);


  
}




void create_lv_screen_ajustes(){

  ajustes = lv_obj_create(NULL);

  lv_obj_t * list2 = lv_list_create(ajustes);
  lv_obj_set_size(list2, lv_pct(95), 220);
  lv_obj_set_style_pad_row(list2, 5, 0);
  lv_obj_align(list2, LV_ALIGN_TOP_MID, 2, 2);

  for (size_t i = 0; i < numParadas; i++) {
        if (!listado[i].nombre.isEmpty()) {  // Verificar que el nombre no esté vacío
            // Crear un botón en la lista y establecer su texto
            lv_obj_t *btn2 = lv_btn_create(list2);
            lv_obj_set_width(btn2, lv_pct(98));
            lv_obj_add_event_cb(btn2, event_handler_btn2, LV_EVENT_CLICKED, NULL);
            
            lv_obj_t *label3 = lv_label_create(btn2);
            lv_label_set_text(label3, listado[i].nombre.c_str());
            lv_obj_align(label3, LV_ALIGN_CENTER, 0, 0);
        }
  }


}


void setup() {

   Serial.begin(115200);
   
   WiFiManager wm;

   bool res;
   res = wm.autoConnect("AutoConnectAP","password");

   if(!res) {
      Serial.println("Failed to connect");
  

      wm.startConfigPortal("AutoConnectAP");
  } 
  else {
      //if you get here you have connected to the WiFi    
      Serial.println("connected...: ");
      Serial.println(WiFi.localIP());
   //   current_ip= WiFi.localIP().toString();
      

  }

  get_listado_paradas();
  get_info_parada(paradaActual);
  

  //init display
  lv_init();
  // Register print function for debugging
  lv_log_register_print_cb(log_print);
  // Create a display object
  lv_display_t * disp;
  // Initialize the TFT display using the TFT_eSPI library
  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);

  
  // Start the SPI for the touchscreen and init the touchscreen
  touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
  touchscreen.begin(touchscreenSPI);
  // Set the Touchscreen rotation in landscape mode
  // Note: in some displays, the touchscreen might be upside down, so you might need to set the rotation to 0: touchscreen.setRotation(0);
  touchscreen.setRotation(2);
  //touchscreen.setRotation(3);

  // Initialize an LVGL input device object (Touchscreen)
  lv_indev_t * indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  // Set the callback function to read Touchscreen input
  lv_indev_set_read_cb(indev, touchscreen_read);




  create_lv_screen_info();

  create_lv_screen_ajustes();
  
  actualizarLista();
  lv_screen_load(info);
  
  lv_timer_t * timer1 = lv_timer_create(info_parada,1000*60,NULL); //60 segundos
}

void loop() {
  // put your main code here, to run repeatedly:
  lv_task_handler();  // let the GUI do its work
  lv_tick_inc(5);     // tell LVGL how much time has passed
  
  delay(5);           // let this time pass

}




void event_handler_btn1(lv_event_t * e){
  //evento click
   lv_event_code_t code = lv_event_get_code(e);


      lv_screen_load(ajustes);
    }



void event_handler_btn2(lv_event_t * e){
  //evento click
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * btn =  (lv_obj_t *)lv_event_get_target(e);
  lv_obj_t * label = lv_obj_get_child(btn, NULL);
  const char * texto = lv_label_get_text(label);
  paradaActual=texto;
  get_info_parada(paradaActual);
  actualizarLista();
  lv_screen_load(info);
}

  




void info_parada(lv_timer_t * timer){

  get_info_parada(paradaActual);
  actualizarLista();
  
}


void actualizarLista() {
  // Limpia la lista actual
  //lv_obj_clean(horarios);
  
  // Vuelve a agregar los elementos del array tiempos
  for (int i = 0; i < 6; i++) {
    if (tiempos[i] != "") {
      lv_label_set_text(etiquetas[i], tiempos[i].c_str());   
    }
    else {
       lv_label_set_text(etiquetas[i], "");
    }
  }

  lv_label_set_text(timestamp, lastUpdate.c_str());
  lv_label_set_text(titulo, paradaActual.c_str());
}


int buscaVacio(String myArray[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (myArray[i] == "") {
            return i; // Devuelve el índice del primer nullptr encontrado
        }
    }
    return -1; // Devuelve -1 si no se encontró ningún nullptr
}


void carga_tiempos(int id){


  char buffer[256];

  snprintf(buffer,sizeof(buffer),"https://www.zaragoza.es/sede/servicio/urbanismo-infraestructuras/transporte-urbano/parada-tranvia/%d.json",id);

  Serial.println(buffer);

  char* url= buffer;

  int vacio;

  HTTPClient http;
  http.begin(url);
  http.setAcceptEncoding("identity");
  int httpCode = http.GET();
  if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("Respuesta:");
      Serial.println(payload);


    // Parsear el JSON
    DynamicJsonDocument doc(2048);
    DeserializationError error =deserializeJson(doc, payload);

    if (error) {
        Serial.print("Error al parsear JSON: ");
        Serial.println(error.c_str());
        return;
      }

  String timestamp = doc["lastUpdated"].as<String>(); // Obtener el valor completo de doc["lastUpdated"]
  lastUpdate = timestamp.substring(timestamp.indexOf('T') + 1);
  


    // Acceder a los datos
    JsonArray destinos = doc["destinos"];
    for (JsonObject destino : destinos) {
      const char* destinoNombre = destino["destino"];
      int minutos = destino["minutos"];
      Serial.print("Destino: ");
      Serial.print(destinoNombre);
      Serial.print(", Minutos: ");
      Serial.println(minutos);

      vacio=buscaVacio(tiempos,6);  //array y longitud.

      if ( vacio != -1) {
            sprintf(buffer, "%3d  %s",minutos,destinoNombre);
      
            tiempos[vacio]=String(buffer);
      }

      
    }
 
    }

  
}



void get_info_parada(String nombre) {

  // Reinicializar el array de tiempo de llegada
    for (int i = 0; i < 6; i++) {
        tiempos[i] = ""; // Asignar cadena vacía
    }

  
  // Recorre el listado para buscar la parada con el nombre dado
  for (size_t i = 0; i < numParadas; i++) {
    if (listado[i].nombre == nombre) {
      // Llama a carga_tiempos para cada ID válido (que no sea cero)
      for (int j = 0; j < 3; j++) {
        if (listado[i].id[j] != 0) {
          carga_tiempos(listado[i].id[j]);
        }
      }
      return; // Termina la función una vez que se encuentra la parada
    }
  }
  // Si no se encuentra la parada
  Serial.println("Parada no encontrada");
}










void get_listado_paradas(){



    HTTPClient http;
    http.begin("https://www.zaragoza.es/sede/servicio/urbanismo-infraestructuras/transporte-urbano/parada-tranvia.json?fl=id%2C%20title&start=0&rows=500");
    http.setAcceptEncoding("identity");
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("Respuesta:");
      Serial.println(payload);

      // Deserializar el JSON
      const size_t capacity = 32000; // Ajusta el tamaño según el tamaño del JSON
      DynamicJsonDocument doc(capacity);
      DeserializationError error = deserializeJson(doc, payload);

      if (error) {
        Serial.print("Error al parsear JSON: ");
        Serial.println(error.c_str());
        return;
      }

      // Extraer los campos "id" y "title" y almacenarlos en el array de paradas
      JsonArray info = doc["result"].as<JsonArray>();

struct Estacion {
  String nombre;
  int id;
};
    
std::vector<Estacion> tablaIntermedia;

 // Llenamos la tabla intermedia con los datos del JSON
  for (JsonObject item : info) {
    Estacion entrada;
    entrada.nombre = item["title"].as<String>();
    entrada.id = item["id"].as<int>();
    tablaIntermedia.push_back(entrada);
  }


// Ordena la tabla intermedia por ID desc
  std::sort(tablaIntermedia.begin(), tablaIntermedia.end(),
            [](const Estacion& a, const Estacion& b) { return a.id > b.id; });

   // Ahora, transferimos los datos agrupados a `listado`
  delete[] listado; // Limpia el array actual
  numParadas = 0;
  listado = new Parada[tablaIntermedia.size()]; // Redimensiona el listado al tamaño necesario

  // Agrupamos las paradas con el mismo nombre en `listado`
  for (const auto& entrada : tablaIntermedia) {
    bool existe = false;
    for (size_t i = 0; i < numParadas; i++) {
      if (listado[i].nombre == entrada.nombre) {
        // Encuentra el primer espacio vacío en el array de IDs que no sea 0
        for (int& id : listado[i].id) {
          if (id == 0) {
            id = entrada.id; // Asigna el ID al primer hueco vacío
            existe = true;
            break;
          }
        }
        break;
      }
    }

    // Si no existe, añade una nueva entrada en `listado`
    if (!existe) {
      listado[numParadas].nombre = entrada.nombre;
      listado[numParadas].id[0] = entrada.id;
      numParadas++;
    }
  }

            



      // Muestra los resultados almacenados
  for (size_t i = 0; i < numParadas; i++) {
    Serial.print("Parada: ");
    Serial.print(listado[i].nombre);
    Serial.print(" - IDs: ");
    for (int j = 0; j < 3; j++) {
      if (listado[i].id[j] != 0) {
        Serial.print(listado[i].id[j]);
        Serial.print(" ");
      }
    }
    Serial.println();
  }


  } else {
      Serial.print("Error en la solicitud HTTP: ");
      Serial.println(http.errorToString(httpCode).c_str());
    }
  
}

// If logging is enabled, it will inform the user about what is happening in the library
void log_print(lv_log_level_t level, const char * buf) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}
