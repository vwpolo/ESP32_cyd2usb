#include <WiFiManager.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebSrv.h>
#include <AsyncTCP.h>
#include <Preferences.h>
#include <Arduino.h>

// Servidor web
  AsyncWebServer server(80);
// zona persistente
Preferences preferences;  

#include "bg.c"    //240x240 px
#include "dot.c"   //8x8 px; centro en 4x4
#include "sec.c"   //11x139 px; eje del reloj en 5x96
#include "min.c"   //11x115 px; eje del reloj en 9x105
#include "hour.c"  //19x87 px; eje del reloj en 9x78

# include "sec2.c" //15x140 px, eje del reloj en 7x116
# include "arrow.c"  // 26x33 px, eje de giro 13x16


#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS


#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

WiFiUDP ntpUDP;
//servidor, tz, update interval  (2*60*1000=2 minutos)
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 120000);

String currentTime = "";
String lastTime = "";

float lat = 41.65606;
float lon = -0.87734;
//String url="https://api.openweathermap.org/data/2.5/weather?lat=" +String(lat,6) + "&lon=" + String(lon,6) + "&units=metric&lang=es&appid=xxx74";


//pantallas.
lv_obj_t * error1;
lv_obj_t * reloj;

//etiquetas meteo
lv_obj_t * temp;
lv_obj_t * viento;
lv_obj_t * direccion;
lv_obj_t * descripcion;

//imagen manecillas del reloj
lv_obj_t * punto;
lv_obj_t * segundero;
lv_obj_t * minutero;
lv_obj_t * horaria;



void setup() {
  Serial.begin(115200); 
    
  //init display
  lv_init();
  // Register print function for debugging
  //lv_log_register_print_cb(log_print);
  // Create a display object
  lv_display_t * disp;
  // Initialize the TFT display using the TFT_eSPI library
  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);

  
  
  
  WiFiManager wm;
  
  wm.setAPCallback(configModeCallback);
  wm.autoConnect("WIFI_ESP32");


  timeClient.begin();
  timeClient.update();



  // Iniciar Preferences
  preferences.begin("config", false);
  
  
  start_web();

  lv_create_screen_reloj();
  //Serial.println(timeClient.getFormattedTime());
  lv_screen_load(reloj);



  lv_timer_t * timer1 = lv_timer_create(update_ui, 1000,NULL);
  lv_timer_t * timer2 = lv_timer_create(update_meteo, 5*60*1000,NULL);

  update_ui(NULL);
  update_meteo(NULL);



  
}

void loop() {
  // put your main code here, to run repeatedly:
  lv_task_handler();  // let the GUI do its work
  lv_tick_inc(5);     // tell LVGL how much time has passed
  
  delay(5);           // let this time pass

}



void update_meteo( lv_timer_t * timer2){

  lat = preferences.getFloat("lat", 41.65606);  // Valor predeterminado ZGZ
  lon = preferences.getFloat("lon", -0.87734);  // Valor predeterminado ZGZ

  String  url="https://api.openweathermap.org/data/2.5/weather?lat=" +String(lat,6) + "&lon=" + String(lon,6) + "&units=metric&lang=es&appid=8025868f1d9529069516f98fae6e0374";


  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
      Serial.print("Código de respuesta HTTP: ");
      Serial.println(httpResponseCode);
      
      String payload = http.getString();  // Obtener respuesta como String
      Serial.println("Respuesta:");
      Serial.println(payload);
      // Procesar JSON usando ArduinoJson
      StaticJsonDocument<1024> doc;
      DeserializationError error = deserializeJson(doc, payload);
      
            if (!error) {
                // Extraer los valores necesarios
                float temperatura = doc["main"]["temp"];
                float velocidadViento = doc["wind"]["speed"];
                int dirViento = doc["wind"]["deg"];
                const char* descViento = doc["weather"][0]["description"];
                
                // Imprimir los resultados
                
                Serial.print("Temperatura: ");
                Serial.println(temperatura);
                char tempBuffer[16];
                snprintf(tempBuffer, sizeof(tempBuffer), "%.1f°C ", temperatura);
                lv_label_set_text(temp,tempBuffer);
                
                Serial.print("Velocidad del Viento: ");
                Serial.println(velocidadViento);
                velocidadViento *= 3.6;  // Convertir de m/s a km/h
                char vientoBuffer[16];
                snprintf(vientoBuffer, sizeof(vientoBuffer), "%.1f K/h", velocidadViento);
                lv_label_set_text(viento,vientoBuffer);

                Serial.print("Direccion: ");
                Serial.println(dirViento);
                lv_image_set_rotation(direccion, dirViento*10);


                
                Serial.print("Descripción: ");
                Serial.println(descViento);
                lv_label_set_text(descripcion,descViento);

                
            } else {
                Serial.print("Error al deserializar JSON: ");
                Serial.println(error.f_str());
            }
    } else {
      Serial.print("Error en la solicitud HTTP: ");
      Serial.println(httpResponseCode);
     
    } 
   http.end();  // Cerrar conexión HTTP
}





void update_ui( lv_timer_t * timer1){

  
//angulos
float angulo_s; 
float angulo_m; 
float angulo_h; 

float angulo_d;


  timeClient.update();

//lvgl trabaja en decimas de angulo, hay que multiplicar por 10

  //angulo_s = timeClient.getSeconds() * 6 * 10;
  //angulo_m = (timeClient.getMinutes() * 6 + timeClient.getSeconds() * 0.1) * 10;
  //angulo_h = (((timeClient.getHours() % 12) * 30 ) + (timeClient.getMinutes() * 0.5)) * 10 ;  // 30 grados por hora + 0.5 grados por minuto

  angulo_h = ((timeClient.getHours() % 12) * 30.0)*10 + (timeClient.getMinutes() * 0.5)*10 + (timeClient.getSeconds() * 0.0083333)*10;

  angulo_d = ((timeClient.getHours() % 12) * 30.0)*10;

  //lv_image_set_rotation(punto, angulo_s);
  lv_obj_add_flag(segundero, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(minutero, LV_OBJ_FLAG_HIDDEN);
  //lv_image_set_rotation(segundero, angulo_s);
  //lv_image_set_rotation(minutero, angulo_m);
  lv_image_set_rotation(horaria, angulo_h);
  lv_image_set_rotation(punto, angulo_d); 
  
}


void lv_create_screen_reloj(){

  reloj =lv_obj_create(NULL);

//  lv_obj_t *  fondo = lv_img_create(reloj);
//  lv_img_set_src(fondo, &bg);
//  lv_obj_set_pos(fondo,0,0);


lv_obj_t * scale1 = lv_scale_create(reloj);
lv_scale_set_mode(scale1, LV_SCALE_MODE_ROUND_INNER);
lv_obj_set_size(scale1,240,240);
//lv_scale_set_total_tick_count(scale1, 12);
//lv_scale_set_range(scale1, 0, 12);

lv_scale_set_angle_range(scale1, 360);
lv_scale_set_rotation(scale1, 270);

lv_scale_set_total_tick_count(scale1,25);
lv_scale_set_major_tick_every(scale1, 2);

lv_scale_set_label_show(scale1, true);
static const char * hour_ticks[] = {"12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", NULL};
lv_scale_set_text_src(scale1, hour_ticks);


static lv_style_t indicator_style;
lv_style_init(&indicator_style);

/* Major tick properties */
//lv_style_set_line_color(&indicator_style, lv_palette_main(LV_PALETTE_YELLOW));
lv_style_set_length(&indicator_style, 20); /* tick length */
lv_style_set_line_width(&indicator_style, 4); /* tick width */
lv_obj_add_style(scale1, &indicator_style, LV_PART_INDICATOR);

/* Minor tick properties */
static lv_style_t minor_ticks_style;
lv_style_init(&minor_ticks_style);
//lv_style_set_line_color(&minor_ticks_style, lv_palette_main(LV_PALETTE_YELLOW));
lv_style_set_length(&minor_ticks_style, 15); /* tick length */
lv_style_set_line_width(&minor_ticks_style, 2); /* tick width */
lv_obj_add_style(scale1, &minor_ticks_style, LV_PART_ITEMS);


/* Main line properties */
static lv_style_t main_line_style;
lv_style_init(&main_line_style);
lv_style_set_arc_color(&main_line_style, lv_color_black());
lv_style_set_arc_width(&main_line_style, 1);
lv_obj_add_style(scale1, &main_line_style, LV_PART_MAIN);




lv_obj_t * scale2 = lv_scale_create(reloj);
lv_scale_set_mode(scale2, LV_SCALE_MODE_ROUND_INNER);
lv_obj_set_size(scale2,240,240);
lv_scale_set_angle_range(scale2, 360);
lv_scale_set_rotation(scale2, 270);

lv_scale_set_total_tick_count(scale2,145);
lv_scale_set_major_tick_every(scale2, 3);
lv_scale_set_label_show(scale2, false);

static lv_style_t indicator_style2;
lv_style_init(&indicator_style2);


/* Major tick properties */
//lv_style_set_line_color(&indicator_style, lv_palette_main(LV_PALETTE_YELLOW));
lv_style_set_length(&indicator_style2, 8); /* tick length */
lv_style_set_line_width(&indicator_style2, 2); /* tick width */
lv_obj_add_style(scale2, &indicator_style2, LV_PART_INDICATOR);

static lv_style_t minor_ticks_style2;
lv_style_init(&minor_ticks_style2);

/* Minor tick properties */

//lv_style_set_line_color(&minor_ticks_style, lv_palette_main(LV_PALETTE_YELLOW));
lv_style_set_length(&minor_ticks_style2, 4); /* tick length */
lv_style_set_line_width(&minor_ticks_style2, 2); /* tick width */
lv_obj_add_style(scale2, &minor_ticks_style2, LV_PART_ITEMS);






//etiquetas meteo

  lv_color_t c = lv_color_make(0, 0, 0);

  temp=lv_label_create(reloj);
  lv_obj_set_style_text_font((lv_obj_t*) temp, &lv_font_montserrat_20, 0);
  lv_obj_set_style_text_color((lv_obj_t*) temp, c, LV_PART_MAIN);
  lv_label_set_text(temp, "");
  lv_obj_set_align(temp, LV_ALIGN_TOP_RIGHT);

  viento=lv_label_create(reloj);
  lv_obj_set_style_text_font((lv_obj_t*) viento, &lv_font_montserrat_20, 0);
  lv_obj_set_style_text_color((lv_obj_t*) viento, c, LV_PART_MAIN);
  lv_label_set_text(viento, "");
  lv_obj_align(viento, LV_ALIGN_TOP_RIGHT, 0, 25);

  descripcion=lv_label_create(reloj);
  lv_obj_set_style_text_font((lv_obj_t*) descripcion, &lv_font_montserrat_20, 0);
  lv_obj_set_style_text_color((lv_obj_t*) descripcion, c, LV_PART_MAIN);
  lv_label_set_text(descripcion, "");
  lv_obj_align(descripcion, LV_ALIGN_BOTTOM_RIGHT, 0, 0); 

  direccion=lv_img_create(reloj);
  lv_img_set_src(direccion, &arrow); 
  lv_obj_set_pos(direccion,320-30,55);
  
/// agujas

  punto = lv_img_create(reloj);
  lv_img_set_src(punto, &dot);
  

  // Obtener las dimensiones de la imagen
  //const lv_image_dsc_t *img_bg = (const lv_image_dsc_t *)lv_img_get_src(fondo);
  //const lv_image_dsc_t *img_punto = (const lv_image_dsc_t *)lv_img_get_src(punto);
  
  //lv_obj_set_pos(punto,40+(img_bg->header.w/2)-(img_punto->header.w/2),0);
  //lv_image_set_pivot(punto, 40+img_punto->header.w/2, img_bg->header.h/2);

  lv_obj_set_pos(punto,120-4,0);
  lv_image_set_pivot(punto, 4, 120);

  segundero = lv_img_create(reloj);
  lv_img_set_src(segundero, &sec);
  lv_obj_set_pos(segundero,120-5,120-96);
  lv_image_set_pivot(segundero,5,96);


  minutero = lv_img_create(reloj);
  lv_img_set_src(minutero, &minu);
  lv_obj_set_pos(minutero,120-9,120-105);
  lv_image_set_pivot(minutero,9,105);
  
//  horaria = lv_img_create(reloj);
//  lv_img_set_src(horaria, &hour);
//  lv_obj_set_pos(horaria,120-9,120-78);
//  lv_image_set_pivot(horaria,9,78);

  horaria = lv_img_create(reloj);
  lv_img_set_src(horaria, &sec2);
  lv_obj_set_pos(horaria,120-7,120-116);
  lv_image_set_pivot(horaria,7,116);

  
}


void start_web(){


  // Página principal para configurar latitud y longitud
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){

    
    String html = "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><title>Configurar Lat y Lon</title></head><body>";
    html += "<h1>Configurar Latitud y Longitud</h1>";
    html += "<form action='/set' method='GET'>";
    html += "Latitud: <input type='text' name='lat' value='" + String(lat, 6) + "'><br>";
    html += "Longitud: <input type='text' name='lon' value='" + String(lon, 6) + "'><br>";
    html += "<input type='submit' value='Guardar'>";
    html += "</form>";
    html += "</body></html>";


    
    request->send(200, "text/html", html);
  });

// Ruta para guardar los valores enviados por el usuario
  server.on("/set", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("lat") && request->hasParam("lon")) {
      String latParam = request->getParam("lat")->value();
      String lonParam = request->getParam("lon")->value();

      // Actualizar las variables globales
      lat = latParam.toFloat();
      lon = lonParam.toFloat();

      // Confirmar cambios al usuario
      String mensaje = "Latitud y longitud actualizadas:<br>";
      mensaje += "Latitud: " + String(lat, 6) + "<br>";
      mensaje += "Longitud: " + String(lon, 6) + "<br>";
      mensaje += "<a href='/'>Volver</a>";
      request->send(200, "text/html", mensaje);

      // Debug en el monitor serie
      Serial.println("Nueva latitud: " + String(lat, 6));
      Serial.println("Nueva longitud: " + String(lon, 6));

       // Guardar nuevos valores en NVS
       preferences.putFloat("lat", lat);
       preferences.putFloat("lon", lon);

       ESP.restart();
       
    } else {
      request->send(400, "text/html", "Faltan parámetros. <a href='/'>Volver</a>");
    }
  });

  // Iniciar servidor
  server.begin();
   
}





void configModeCallback (WiFiManager *myWiFiManager) {
 
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());

  Serial.println(myWiFiManager->getConfigPortalSSID());
  create_lv_screen_error1();
  lv_screen_load(error1);
  update_lvgl();
}

void update_lvgl() {
  unsigned long startTime = millis();  // Marca el tiempo inicial
  
  while (millis() - startTime < 1000) {  // Ejecuta durante 1 segundo
    lv_timer_handler();  // Actualiza LVGL
    lv_tick_inc(5);
    delay(5);            // Ajusta la frecuencia de actualización
  }
}

void create_lv_screen_error1() {
  error1 = lv_obj_create(NULL);

  lv_obj_t * texto1 = lv_label_create(error1);
  //lv_obj_align(texto1, LV_ALIGN_TOP_LEFT, 4, 3);
  lv_obj_set_style_text_font((lv_obj_t*) texto1, &lv_font_montserrat_18, 0);
  lv_obj_set_style_text_color((lv_obj_t*) texto1, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
  lv_obj_set_size(texto1, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_pos(texto1, 5, 10); 
  lv_label_set_text(texto1, "Error Conectando WIFI");

  lv_obj_t * texto2 = lv_label_create(error1);
  //lv_obj_align(texto2, LV_ALIGN_TOP_LEFT, 4, 3);
  lv_obj_set_style_text_font((lv_obj_t*) texto2, &lv_font_montserrat_18, 0);
  lv_obj_set_style_text_color((lv_obj_t*) texto2, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
  lv_obj_set_size(texto2, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_pos(texto2, 5, 40); 
  lv_label_set_text(texto2, "Creando AP: WIFI_ESP32");

  lv_obj_t * texto3 = lv_label_create(error1);
  //lv_obj_align(texto3, LV_ALIGN_TOP_LEFT, 4, 3);
  lv_obj_set_style_text_font((lv_obj_t*) texto3, &lv_font_montserrat_18, 0);
  lv_obj_set_style_text_color((lv_obj_t*) texto3, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
  lv_obj_set_size(texto3, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
  lv_obj_set_pos(texto3, 5, 70); 
  lv_label_set_text(texto3, "192.168.4.1");

  



}
