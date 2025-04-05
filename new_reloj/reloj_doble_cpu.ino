
#include <lvgl.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WiFiManager.h>
#include <ArduinoJson.h>
#include <esp_sleep.h>
#include "driver/rtc_io.h"
#include <Preferences.h>
#include <ESPAsyncWebSrv.h>

#include <HTTPClient.h>
// Servidor web
AsyncWebServer server(80);
// zona persistente
Preferences preferences;


String api_code="xxxx";

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
//servidor, tz, 
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org");


  

#include "bg.c"    // fondo del reloj 200x200 px en 5,5
#include "min.c"   // aguja minutos 14x90 centro en 7x82
#include "hour.c"  // aguja horas  13x64  centro en 6x56
#include "sec.c"   // aguja segundo 3x24   centro en 1x21
#include "arrow.c"  // 26x33 px, eje de giro 13x16




//imagenes weather code
#include "0.c"
#include "1.c"
#include "2.c"
#include "3.c"
#include "45.c"
#include "66.c"
#include "73.c"
#include "81.c"
#include "82.c"
#include "96.c"





//pantallas.
lv_obj_t * error1;
lv_obj_t * reloj;
lv_obj_t * forecast;
//lv_obj_t * welcome;

//imagen manecillas del reloj
lv_obj_t * face;
//lv_obj_t * punto;
lv_obj_t * segundero;
lv_obj_t * minutero;
lv_obj_t * horaria;

//etiquetas meteo
lv_obj_t * temp;
lv_obj_t * viento;
lv_obj_t * direccion;
lv_obj_t * descripcion;
lv_obj_t * weather_icon;

lv_obj_t * ciudad;

//iconos forecast
lv_obj_t * icon1;
lv_obj_t * icon2;
lv_obj_t * icon3;
lv_obj_t * icon4;

//etiquetas dia 
lv_obj_t * dia1;
lv_obj_t * dia2;
lv_obj_t * dia3;
lv_obj_t * dia4;

//etiquetas max_min
lv_obj_t * max_min1;
lv_obj_t * max_min2;
lv_obj_t * max_min3;
lv_obj_t * max_min4;

//etiquetas viento
lv_obj_t * viento1;
lv_obj_t * viento2;
lv_obj_t * viento3;
lv_obj_t * viento4;




struct Clima {
    int codigo;
    const char* descripcion;
    const lv_image_dsc_t * icono;  // Puntero a la estructura de la imagen
};

Clima condicionesClimaticas[] = {
//    // Tormentas eléctricas
    {200, "Tormenta con lluvia ligera", &img_96},
    {95, "Tormenta con lluvia ligera", &img_96},
    {96, "Tormenta con lluvia ligera", &img_96},
    {99, "Tormenta con lluvia ligera", &img_96},
    {201, "Tormenta con lluvia", &img_96},
    {202, "Tormenta con lluvia intensa", &img_96},
    {210, "Tormenta ligera", &img_96},
    {211, "Tormenta", &img_96},
    {212, "Tormenta fuerte", &img_96},
    {221, "Tormenta irregular", &img_96},
    {230, "Tormenta con llovizna ligera", &img_96},
    {231, "Tormenta con llovizna", &img_96},
    {232, "Tormenta con llovizna intensa", &img_96},
//
//    // Llovizna
    {300, "Llovizna de intensidad ligera", &img_81},
    {301, "Llovizna", &img_81},
    {51, "Llovizna", &img_81},
    {53, "Llovizna", &img_81},
    {55, "Llovizna", &img_81},
    {56, "Llovizna", &img_81},
    {57, "Llovizna", &img_81},
    {80, "Lluvia ligera", &img_81},
    {81, "Lluvia ligera", &img_81},
    {302, "Llovizna de intensidad fuerte", &img_81},
    {310, "Llovizna ligera con lluvia", &img_81},
    {311, "Lluvia con llovizna", &img_81},
    {312, "Llovizna con lluvia intensa", &img_81},
    {313, "Chubascos y llovizna", &img_81},
    {314, "Chubascos fuertes con llovizna", &img_81},
    {321, "Llovizna en chubascos", &img_81},
//
//    // Lluvia
    {500, "Lluvia ligera", &img_82},
    {61, "Lluvia ligera", &img_82},
    {63, "Lluvia ligera", &img_82},
    {65, "Lluvia ligera", &img_82},
    {82, "Lluvia ligera", &img_82},
    {65, "Lluvia ligera", &img_82},
    {501, "Lluvia moderada", &img_82},
    {502, "Lluvia intensa", &img_82},
    {503, "Lluvia muy intensa", &img_82},
    {504, "Lluvia extrema", &img_82},
    {511, "Lluvia helada", &img_66},
    {520, "Lluvia en chubascos ligeros", &img_82},
    {521, "Chubascos de lluvia", &img_82},
    {522, "Chubascos de lluvia intensa", &img_82},
    {531, "Chubascos irregulares", &img_82},
//
//    // Nieve
    {600, "Nieve ligera", &img_73},
    {66, "Nieve ligera", &img_73},
    {67, "Nieve ligera", &img_73},
    {71, "Nieve ligera", &img_73},
    {73, "Nieve ligera", &img_73},
    {75, "Nieve ligera", &img_73},
    {77, "Nieve ligera", &img_73},
    {601, "Nieve", &img_73},
    {602, "Nieve intensa", &img_73},
    {611, "Aguanieve", &img_73},
    {612, "Aguanieve ligera en chubascos", &img_73},
    {613, "Aguanieve en chubascos", &img_73},
    {615, "Lluvia ligera con nieve", &img_73},
    {616, "Lluvia con nieve", &img_73},
    {620, "Nieve ligera en chubascos", &img_73},
    {621, "Nieve en chubascos", &img_73},
    {622, "Nieve intensa en chubascos", &img_73},
//
//    // Atmósfera
    {701, "Niebla ligera", &img_45},
    {45, "Niebla ligera", &img_45},
    {48, "Niebla ligera", &img_45},
    {711, "Humo", &img_45},
    {721, "Bruma", &img_45},
    {731, "Remolinos de arena/polvo", &img_45},
    {741, "Niebla", &img_45},
    {751, "Arena", &img_45},
    {761, "Polvo", &img_45},
    {762, "Ceniza volcánica", &img_45},
    {771, "Chubascos de viento", &img_45},
    {781, "Tornado", &img_45},

//    // Cielo despejado
    {800, "Cielo despejado", &img_0},
    {0, "Cielo despejado", &img_0},

    // Nubes
    {801, "Pocas nubes (11-25%)", &img_1},
    {1, "Pocas nubes (11-25%)", &img_1},
    {802, "Nubes dispersas (25-50%)", &img_1},
    {2, "Nubes dispersas (25-50%)", &img_1},
    {803, "Nubes fragmentadas (51-84%)", &img_2},
    {804, "Cielo cubierto (85-100%)", &img_3},
    {3, "Cielo cubierto (85-100%)", &img_2}
};

// Número de elementos en el array
const int numCondiciones = sizeof(condicionesClimaticas) / sizeof(condicionesClimaticas[0]);






unsigned long tiempoInicio;
unsigned long button_time;
unsigned long last_button_time;

#define SW_PIN GPIO_NUM_27 //pin interruptor pulsador a GND
#define SW_PIN_BITMASK (1ULL << SW_PIN)  // Máscara de bits para GPIO27

#define BUTTON_PIN 27


void IRAM_ATTR handleInterrupt_27() {
  // Código a ejecutar cuando se detecta la interrupción
  button_time = millis();
  if (button_time - last_button_time > 500) 
    {
      Serial.println("Interrupción detectada en GPIO27");
      last_button_time = button_time;

      lv_scr_load(forecast);
      lv_timer_t *timer3 = lv_timer_create(return_to_reloj, 20000, NULL); // 20000 ms = 20 segundos
      lv_timer_set_repeat_count(timer3, 1); // Ejecutar una sola vez
//reiniciamos contador de apagado deep-sleep
      tiempoInicio = millis();
    }
}


 
void tareaForecast(void * parameter) {
  carga_datos_forecast();
  vTaskDelete(NULL); // Mata la tarea cuando termine
}


void setup() {

  Serial.begin(115200); 

  delay(100);

  //deep-sleep
  tiempoInicio = millis(); // Guarda el tiempo de inicio

    
  //init display
  lv_init();
  // Create a display object
  lv_display_t * disp;
  // Initialize the TFT display using the TFT_eSPI library
  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);
 

  WiFiManager wm;
  
  wm.setAPCallback(configModeCallback);
  wm.autoConnect("WIFI_ESP32");

//  lv_create_screen_welcome();
//  lv_scr_load(welcome);


   preferences.begin("config", true); // Modo solo lectura
   boolean horarioVerano = preferences.getBool("horarioVerano", false);
   preferences.end(); 

   
  timeClient.begin();
  
  if(horarioVerano){
    timeClient.setTimeOffset(7200);
  }
  else {
    timeClient.setTimeOffset(3600);
  }
  //update interval  (2*60*1000=2 minutos)
  timeClient.setUpdateInterval(120000);
  
  timeClient.update();

  
  start_web();

  lv_create_screen_reloj();
  lv_create_screen_forecast();

  

  lv_timer_t * timer1 = lv_timer_create(update_ui, 5000,NULL); //cada 5 segundos
  update_ui(NULL);

  lv_timer_t * timer_sec = lv_timer_create(update_sec, 1000,NULL); //cada  segundo
  update_sec(NULL);

  
  lv_timer_t * meteo = lv_timer_create(update_meteo, 10*60*1000,NULL);  //cada 10 minutos
  update_meteo(NULL);

  //carga_datos_forecast();
  //ahora en CPU1
  xTaskCreatePinnedToCore(
    tareaForecast,    // Función
    "Forecast",       // Nombre
    4096,             // Stack size
    NULL,             // Parámetros
    1,                // Prioridad
    NULL,             // Handle
    1                 // CPU1
  );

  lv_scr_load(reloj);

  
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Configura el pin como entrada con resistencia pull-up interna
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleInterrupt_27, FALLING); // Configura la interrupción en flanco descendente
  

}

void loop() {
  lv_task_handler();  // let the GUI do its work
  lv_tick_inc(5);     // tell LVGL how much time has passed

  unsigned long tiempoTranscurrido = millis() - tiempoInicio;

   preferences.begin("config", true); // Modo solo lectura 
   int t_sleep = preferences.getInt("t_sleep", 10);
   preferences.end();  // Cerrar después de leer
  

  
  if (tiempoTranscurrido >= t_sleep*60*1000) {
    lv_obj_clean(lv_scr_act());  // Limpia la pantalla
    lv_refr_now(NULL);           // Fuerza un refresh inmediato
    delay(100);                  // Espera para que se refleje en pantalla
    detachInterrupt(BUTTON_PIN);
    pinMode(SW_PIN, INPUT_PULLUP);
    rtc_gpio_pullup_en(SW_PIN);
    // Despertar con botón pulsador de  SW_PIN
    esp_sleep_enable_ext1_wakeup(SW_PIN_BITMASK, ESP_EXT1_WAKEUP_ALL_LOW);
    esp_deep_sleep_start();
  }

  delay(5);           // let this time pass


}






void carga_datos_forecast() {

   preferences.begin("config", true); // Modo solo lectura
   float lat = preferences.getFloat("lat", 41.656);  // Si no existe, devuelve Zaragoza
   float lon = preferences.getFloat("lon", -0.877);
   preferences.end();  // Cerrar después de leer

  String url="https://api.open-meteo.com/v1/forecast?latitude="+ String(lat,6) +"&longitude=" + String(lon,6) + "&daily=weather_code,temperature_2m_max,temperature_2m_min,wind_speed_10m_max,wind_direction_10m_dominant&timezone=Europe%2FBerlin";

  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET(); 


 if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
        
        StaticJsonDocument<1024> doc;
        DeserializationError error = deserializeJson(doc, payload);

        if (!error) {
            JsonArray time = doc["daily"]["time"];
            JsonArray w_code = doc["daily"]["weather_code"];
            JsonArray temp_max = doc["daily"]["temperature_2m_max"];
            JsonArray temp_min = doc["daily"]["temperature_2m_min"];
            JsonArray wind_speed = doc["daily"]["wind_speed_10m_max"];
            JsonArray wind_dir = doc["daily"]["wind_direction_10m_dominant"];
            

            // Actualizar etiquetas de los días
            lv_label_set_text_fmt(dia1, "Dia %s", time[0].as<const char*>() + 8); // Extrae el día
            lv_label_set_text_fmt(dia2, "Dia %s", time[1].as<const char*>() + 8);
            lv_label_set_text_fmt(dia3, "Dia %s", time[2].as<const char*>() + 8);
            lv_label_set_text_fmt(dia4, "Dia %s", time[3].as<const char*>() + 8);

            // Actualizar etiquetas de temperaturas
            
            lv_label_set_text_fmt(max_min1, "%.0f/%.0f °C", round(temp_max[0].as<float>()), round(temp_min[0].as<float>()));
            lv_label_set_text_fmt(max_min2, "%.0f/%.0f °C", round(temp_max[1].as<float>()), round(temp_min[0].as<float>()));
            lv_label_set_text_fmt(max_min3, "%.0f/%.0f °C", round(temp_max[2].as<float>()), round(temp_min[0].as<float>()));
            lv_label_set_text_fmt(max_min4, "%.0f/%.0f °C", round(temp_max[3].as<float>()), round(temp_min[0].as<float>()));

            lv_img_set_src(icon1, buscar_icono(w_code[0].as<int>()));
            lv_img_set_src(icon2, buscar_icono(w_code[1]));
            lv_img_set_src(icon3, buscar_icono(w_code[2]));
            lv_img_set_src(icon4, buscar_icono(w_code[3]));

            lv_label_set_text_fmt(viento1, "%.0f Km/h", round(wind_speed[0].as<float>()) );
            lv_label_set_text_fmt(viento2, "%.0f Km/h", round(wind_speed[1].as<float>()) );
            lv_label_set_text_fmt(viento3, "%.0f Km/h", round(wind_speed[2].as<float>()) );
            lv_label_set_text_fmt(viento4, "%.0f Km/h", round(wind_speed[3].as<float>()) );

        } else {
            Serial.println("Error al deserializar el JSON");
        }
    } else {
        Serial.printf("Error en la solicitud HTTP: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();

}



static void return_to_reloj(lv_timer_t *timer3) {
    lv_scr_load(reloj);
}

void update_meteo( lv_timer_t * meteo){

   preferences.begin("config", true); // Modo solo lectura
   float lat = preferences.getFloat("lat", 41.656);  // Si no existe, devuelve Zaragoza
   float lon = preferences.getFloat("lon", -0.877);
   preferences.end();  // Cerrar después de leer

   String  url="https://api.openweathermap.org/data/2.5/weather?lat=" +String(lat,6) + "&lon=" + String(lon,6) + "&units=metric&lang=es&appid=" + api_code;
   Serial.println(url);

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
      char buffer[50];  // Ajusta el tamaño según sea necesario

      if (!error) {

        float temperatura =  doc["main"]["temp"];
        float velocidadViento = doc["wind"]["speed"];
        int dirViento = doc["wind"]["deg"];
        int codigo = doc["weather"][0]["id"];
        const char  * city = doc["name"];
      
        Serial.print("Temperatura: ");
        Serial.println(temperatura);
        char tempBuffer[16];
        snprintf(tempBuffer, sizeof(tempBuffer), "%.1f °C", temperatura);
        lv_label_set_text(temp,tempBuffer);

        Serial.print("Velocidad del Viento: ");
        Serial.println(velocidadViento);
        velocidadViento *= 3.6;  // Convertir de m/s a km/h
        char  vientoBuffer[16];
        snprintf(vientoBuffer, sizeof(vientoBuffer), "%.1f Km/h", velocidadViento);
        lv_label_set_text(viento,vientoBuffer);

        Serial.print("Direccion: ");
        Serial.println(dirViento);
        lv_image_set_rotation(direccion, dirViento*10);

        Serial.print("Descripción: ");
        Serial.println(codigo);
        
        lv_label_set_text(descripcion,obtenerDescripcionClima(codigo));

        lv_img_set_src(weather_icon, buscar_icono(codigo));

        lv_label_set_text(ciudad,city);

        
      }
      
     }

  
}



const char* obtenerDescripcionClima(int codigo) {
    for (int i = 0; i < numCondiciones; i++) {
        if (condicionesClimaticas[i].codigo == codigo) {
            return condicionesClimaticas[i].descripcion;
        }
    }
    return "Código desconocido";
}

const lv_image_dsc_t * buscar_icono(int codigo) {
    for (int i = 0; i < numCondiciones; i++) {
        if (condicionesClimaticas[i].codigo == codigo) {
            return condicionesClimaticas[i].icono; //  // Devuelve el puntero a la imagen
        }
    }
    return NULL; // Si no se encuentra el código, devuelve NULL
}



void update_sec( lv_timer_t * timer_sec){

  
//angulo

float angulo_s; 

timeClient.update();

//lvgl trabaja en decimas de angulo, hay que multiplicar por 10
// 6 grados por cada segundo

angulo_s = timeClient.getSeconds() * 6 * 10;
lv_image_set_rotation(segundero, angulo_s);
  
}



void update_ui( lv_timer_t * timer1){

  
//angulos

float angulo_m; 
float angulo_h; 

timeClient.update();

//lvgl trabaja en decimas de angulo, hay que multiplicar por 10

angulo_m = (timeClient.getMinutes() * 6 + timeClient.getSeconds() * 0.1) * 10;  // 6 grados por minuto + 0.1 por segundo
angulo_h = (((timeClient.getHours() % 12) * 30 ) + (timeClient.getMinutes() * 0.5)) * 10 ;  // 30 grados por hora + 0.5 grados por minuto

lv_image_set_rotation(minutero, angulo_m);
lv_image_set_rotation(horaria, angulo_h);

  
}
//
//void lv_create_screen_welcome(){
//  welcome = lv_obj_create(NULL);
//  lv_obj_set_style_bg_color(welcome,lv_color_make(225,160,235), 0);
//
//  lv_obj_t * myip = lv_label_create(welcome);
//  lv_obj_align(myip, LV_ALIGN_TOP_MID, 0, +5);
//  
//  IPAddress ip = WiFi.localIP();
//  String ipStr = ip.toString();  // Convertimos la IP a String
//
//  lv_label_set_text(myip, ipStr.c_str()); // Actualizamos la etiqueta
//}

void lv_create_screen_forecast(){

  forecast = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(forecast,lv_color_make(225,160,235), 0);

  lv_color_t c = lv_color_make(0, 0, 0);

  ciudad=lv_label_create(forecast);
  lv_obj_set_style_text_font((lv_obj_t*) ciudad, &lv_font_montserrat_20, 0);
  lv_obj_set_style_text_color((lv_obj_t*) ciudad, c, LV_PART_MAIN);
  lv_obj_set_align(ciudad, LV_ALIGN_TOP_MID);
  lv_label_set_text(ciudad, "");

//  lv_obj_t * contenedor1 = lv_obj_create(forecast);
//  lv_obj_set_size(contenedor1, 80,150);
//  lv_obj_set_pos(contenedor1,0,32);
//  lv_obj_set_scrollbar_mode(contenedor1, LV_SCROLLBAR_MODE_OFF);
//  lv_obj_set_style_pad_all(contenedor1, 1, LV_PART_MAIN);
//
// 
//
//  dia1 = lv_label_create(contenedor1);
//  lv_obj_align(dia1,LV_ALIGN_TOP_MID,0,0);
//  icon1=lv_image_create(contenedor1);
//  lv_obj_set_size(icon1,64,64);
//  lv_obj_align_to(icon1, dia1, LV_ALIGN_OUT_BOTTOM_MID, 0,2);
//  max_min1 = lv_label_create(contenedor1);
//  lv_obj_align_to(max_min1,icon1, LV_ALIGN_OUT_BOTTOM_MID,0,2);


lv_obj_t * contenedor1 = lv_obj_create(forecast);
lv_obj_set_size(contenedor1, 80, 150);
lv_obj_set_pos(contenedor1, 0, 32);
lv_obj_set_scrollbar_mode(contenedor1, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_pad_all(contenedor1, 1, LV_PART_MAIN);

// Activar layout Flex
lv_obj_set_layout(contenedor1, LV_LAYOUT_FLEX);
lv_obj_set_flex_flow(contenedor1, LV_FLEX_FLOW_COLUMN); // Layout en columna
lv_obj_set_flex_align(contenedor1, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START); // Centrado horizontal, inicio vertical

// Crear y añadir objetos
dia1 = lv_label_create(contenedor1);
icon1 = lv_image_create(contenedor1);
lv_obj_set_size(icon1, 64, 64); // Tamaño fijo para la imagen
max_min1 = lv_label_create(contenedor1);
viento1 = lv_label_create(contenedor1);




  
//  lv_obj_t * contenedor2 = lv_obj_create(forecast);
//  lv_obj_set_size(contenedor2, 80,150);
//  lv_obj_set_pos(contenedor2,80,32);
//  lv_obj_set_scrollbar_mode(contenedor2, LV_SCROLLBAR_MODE_OFF);
//  lv_obj_set_style_pad_all(contenedor2, 1, LV_PART_MAIN);
//
//  icon2=lv_image_create(contenedor2);
//  lv_obj_align(icon2, LV_ALIGN_CENTER, 0,0);
//
//  dia2 = lv_label_create(contenedor2);
//  lv_obj_align(dia2,LV_ALIGN_TOP_MID,0,0);
//  
//  max_min2 = lv_label_create(contenedor2);
//  lv_obj_align(max_min2,LV_ALIGN_BOTTOM_MID,0,0);

lv_obj_t * contenedor2 = lv_obj_create(forecast);
lv_obj_set_size(contenedor2, 80, 150);
lv_obj_set_pos(contenedor2, 80, 32);
lv_obj_set_scrollbar_mode(contenedor2, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_pad_all(contenedor2, 1, LV_PART_MAIN);

// Activar layout Flex
lv_obj_set_layout(contenedor2, LV_LAYOUT_FLEX);
lv_obj_set_flex_flow(contenedor2, LV_FLEX_FLOW_COLUMN); // Layout en columna
lv_obj_set_flex_align(contenedor2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START); // Centrado horizontal, inicio vertical

// Crear y añadir objetos
dia2 = lv_label_create(contenedor2);
icon2 = lv_image_create(contenedor2);
lv_obj_set_size(icon2, 64, 64); // Tamaño fijo para la imagen
max_min2 = lv_label_create(contenedor2);
viento2 = lv_label_create(contenedor2);


  


//  lv_obj_t * contenedor3 = lv_obj_create(forecast);
//  lv_obj_set_size(contenedor3, 80,150);
//  lv_obj_set_pos(contenedor3,160,32);
//  lv_obj_set_scrollbar_mode(contenedor3, LV_SCROLLBAR_MODE_OFF);
//  lv_obj_set_style_pad_all(contenedor3, 1, LV_PART_MAIN);
//
//  icon3=lv_image_create(contenedor3);
//  lv_obj_align(icon3, LV_ALIGN_CENTER, 0,0);
//
//  dia3 = lv_label_create(contenedor3);
//  lv_obj_align(dia3,LV_ALIGN_TOP_MID,0,0);
//  
//  max_min3 = lv_label_create(contenedor3);
//  lv_obj_align(max_min3,LV_ALIGN_BOTTOM_MID,0,0);


lv_obj_t * contenedor3 = lv_obj_create(forecast);
lv_obj_set_size(contenedor3, 80, 150);
lv_obj_set_pos(contenedor3, 160, 32);
lv_obj_set_scrollbar_mode(contenedor3, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_pad_all(contenedor3, 1, LV_PART_MAIN);

// Activar layout Flex
lv_obj_set_layout(contenedor3, LV_LAYOUT_FLEX);
lv_obj_set_flex_flow(contenedor3, LV_FLEX_FLOW_COLUMN); // Layout en columna
lv_obj_set_flex_align(contenedor3, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START); // Centrado horizontal, inicio vertical

// Crear y añadir objetos
dia3 = lv_label_create(contenedor3);
icon3 = lv_image_create(contenedor3);
lv_obj_set_size(icon3, 64, 64); // Tamaño fijo para la imagen
max_min3 = lv_label_create(contenedor3);
viento3 = lv_label_create(contenedor3);







//  lv_obj_t * contenedor4 = lv_obj_create(forecast);
//  lv_obj_set_size(contenedor4, 80,150);
//  lv_obj_set_pos(contenedor4,240,32);
//  lv_obj_set_scrollbar_mode(contenedor4, LV_SCROLLBAR_MODE_OFF);
//  lv_obj_set_style_pad_all(contenedor4, 1, LV_PART_MAIN);
//
//  icon4=lv_image_create(contenedor4);
//  lv_obj_align(icon4, LV_ALIGN_CENTER, 0,0);
//
//  dia4 = lv_label_create(contenedor4);
//  lv_obj_align(dia4,LV_ALIGN_TOP_MID,0,0);
//  
//  max_min4 = lv_label_create(contenedor4);
//  lv_obj_align(max_min4,LV_ALIGN_BOTTOM_MID,0,0);

lv_obj_t * contenedor4= lv_obj_create(forecast);
lv_obj_set_size(contenedor4, 80, 150);
lv_obj_set_pos(contenedor4, 240, 32);
lv_obj_set_scrollbar_mode(contenedor4, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_pad_all(contenedor4, 1, LV_PART_MAIN);

// Activar layout Flex
lv_obj_set_layout(contenedor4, LV_LAYOUT_FLEX);
lv_obj_set_flex_flow(contenedor4, LV_FLEX_FLOW_COLUMN); // Layout en columna
lv_obj_set_flex_align(contenedor4, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START); // Centrado horizontal, inicio vertical

// Crear y añadir objetos
dia4 = lv_label_create(contenedor4);
icon4 = lv_image_create(contenedor4);
lv_obj_set_size(icon4, 64, 64); // Tamaño fijo para la imagen
max_min4 = lv_label_create(contenedor4);
viento4 = lv_label_create(contenedor4);

//  lv_img_set_src(icon1, &img_81);
//  lv_img_set_src(icon2, &img_2);
//  lv_img_set_src(icon3, &img_45);
//  lv_img_set_src(icon4, &img_0);



  
  
}



void lv_create_screen_reloj(){

  reloj = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(reloj,lv_color_make(120,190,255), 0);

  face = lv_img_create(reloj);
  lv_img_set_src(face, &fondo1);
  lv_obj_set_pos(face,5,5);

  segundero = lv_img_create(reloj);
  lv_img_set_src(segundero, &sec1);
  lv_obj_set_pos(segundero,5+100-3,5+153-22);
  lv_image_set_pivot(segundero,1,21);  


  minutero = lv_img_create(reloj);
  lv_img_set_src(minutero, &minu1);
  lv_obj_set_pos(minutero,5+100-7,5+100-82);
  lv_image_set_pivot(minutero,7,82);


  horaria = lv_img_create(reloj);
  lv_img_set_src(horaria, &hour1);
  lv_obj_set_pos(horaria,5+100-6,5+100-56);
  lv_image_set_pivot(horaria,6,56);


  
//etiquetas meteo
  

  lv_color_t c = lv_color_make(0, 0, 0);

  temp=lv_label_create(reloj);
  lv_obj_set_style_text_font((lv_obj_t*) temp, &lv_font_montserrat_20, 0);
  lv_obj_set_style_text_color((lv_obj_t*) temp, c, LV_PART_MAIN);
  lv_obj_align(temp, LV_ALIGN_TOP_RIGHT,-5,3);
  lv_label_set_text(temp, "");

  viento=lv_label_create(reloj);
  lv_obj_set_style_text_font((lv_obj_t*) viento, &lv_font_montserrat_20, 0);
  lv_obj_set_style_text_color((lv_obj_t*) viento, c, LV_PART_MAIN);
  lv_label_set_text(viento, "");
  lv_obj_align(viento, LV_ALIGN_TOP_RIGHT, 0, 30);

  direccion=lv_img_create(reloj);
  lv_img_set_src(direccion, &arrow); 
  lv_obj_set_pos(direccion,320-50,55);
  lv_image_set_pivot(direccion, 13, 16);
  

  descripcion=lv_label_create(reloj);
  lv_obj_set_style_text_font((lv_obj_t*) descripcion, &lv_font_montserrat_20, 0);
  lv_obj_set_style_text_color((lv_obj_t*) descripcion, c, LV_PART_MAIN);
  lv_label_set_text(descripcion, "");
  lv_obj_align(descripcion, LV_ALIGN_BOTTOM_RIGHT, -3, -3); 

  weather_icon = lv_img_create(reloj);
  lv_obj_set_pos(weather_icon,240,100);

  

}





void update_lvgl() {
  unsigned long startTime = millis();  // Marca el tiempo inicial
  
  while (millis() - startTime < 500) {  // Ejecuta durante medio segundo
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





void configModeCallback (WiFiManager *myWiFiManager) {
 
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());

  Serial.println(myWiFiManager->getConfigPortalSSID());
  create_lv_screen_error1();
  lv_scr_load(error1);
  update_lvgl();
 
}





void start_web(){
         
  
  
   preferences.begin("config", true); // Modo solo lectura
   float lat = preferences.getFloat("lat", 41.656);  // Si no existe, devuelve Zaragoza
   float lon = preferences.getFloat("lon", -0.877);
   boolean horarioVerano = preferences.getBool("horarioVerano", false);
   //10 minutos 
   int t_sleep = preferences.getInt("t_sleep", 10);
   preferences.end();  // Cerrar después de leer

 

  // Página principal para configurar latitud y longitud
  server.on("/", HTTP_GET, [=](AsyncWebServerRequest *request){


String html = "<!DOCTYPE html><html lang='en'><head>";
html += "<meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
html += "<title>Configurar Lat y Lon</title>";
html += "<style>";
html += "body { font-family: Arial, sans-serif; background-color: #e0f2ff; margin: 0; padding: 0; }";
html += ".container { position: absolute; top: 20px; left: 20px; background: #ffffff; padding: 20px; border-radius: 8px; box-shadow: 2px 2px 10px rgba(0,0,0,0.1); }";
html += "h1 { color: #0077cc; font-size: 20px; margin-bottom: 10px; }";
html += "label { display: block; margin-top: 10px; font-weight: bold; color: #005599; }";
html += "input[type='text'] { width: 85%; padding: 8px; margin-top: 5px; border: 3px solid #0077cc; border-radius: 4px; }";
html += "input[type='submit'] { margin-top: 15px; background: #0077cc; color: white; border: none; padding: 10px 15px; border-radius: 4px; cursor: pointer; }";
html += "input[type='submit']:hover { background: #005599; }";
html += "</style></head><body>";

html += "<div class='container'>";
html += "<h1>Configurar ESP32 CYD</h1>";
html += "<form action='/set' method='GET'  >";

html += "<label for='lat' >Latitud:</label>&#9;<input type='text' id='lat' name='lat' value='" + String(lat, 6) + "'>";
html += "<label for='lon' >Longitud:</label>&#9;<input type='text' id='lon' name='lon' value='" + String(lon, 6) + "'>";
html += "<label for='minutosSleep' >Minutos para Hibernacion :</label>&#9;<input type='text' id='minutosSleep' name='minutosSleep' value='" + String(t_sleep) + "'>";
html += "<label for='verano'  style='display: inline-block; margin-right: 10px;'>Horario Verano </label><input type='checkbox' id='verano' name='verano' " + String(horarioVerano ? "checked" : "") + ">";


html += "<br><input type='submit' value='Guardar'>";
html += "</form></div>";

html += "</body></html>";

    
    request->send(200, "text/html", html);
  });

// Ruta para guardar los valores enviados por el usuario
  server.on("/set", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("lat") && request->hasParam("lon")  && request->hasParam("minutosSleep")  ) {
      String latParam = request->getParam("lat")->value();
      String lonParam = request->getParam("lon")->value();
      String sleepParam = request->getParam("minutosSleep")->value();
      
      boolean  veranoParam = false; 
      if (request->hasParam("verano")) {
         veranoParam = (request->getParam("verano")->value() == "on");
        }
      


      // Confirmar cambios al usuario
      String mensaje = "Parametros actualizados:<br><br>";
      mensaje += "&emsp; Latitud: " + latParam + "<br>";
      mensaje += "&emsp; Longitud: " + lonParam + "<br>";
      mensaje += "&emsp; Minutos Hibernacion: " + sleepParam + "<br>";
      mensaje += "&emsp; Verano: " + String(veranoParam ? "S&#237;" : "No") + "<br>";
      mensaje += "<br>";
      //mensaje += "<a href='/'>Volver</a>";
      request->send(200, "text/html", mensaje);

      // Debug serie
      Serial.println("Nueva latitud: " + latParam);
      Serial.println("Nueva longitud: " + lonParam);
      Serial.println("Tiempo to Sleep: " + sleepParam);
      Serial.println("Verano: " +  String(veranoParam ? "Sí" : "No"));
    //forzar entero positivo
       int entero =  sleepParam.toInt();
       if (entero < 0)  entero=-entero;

       // Guardar nuevos valores en NVS Preferences
       preferences.begin("config");
       preferences.putFloat("lat", latParam.toFloat());
       preferences.putFloat("lon", lonParam.toFloat());
       preferences.putInt("t_sleep",entero);
       preferences.putBool("horarioVerano", veranoParam);
       preferences.end();


       delay(1500);

       ESP.restart();
       
    }
    else{
      String mensaje = "Error. Campos vacios.";
      request->send(400, "text/html", mensaje);
      
      return;
    }
  });

  // Iniciar servidor
  server.begin();
   
}
