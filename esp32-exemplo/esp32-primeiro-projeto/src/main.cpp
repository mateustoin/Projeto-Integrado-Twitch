#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

// Pino que o sensor de distância está conectado
#define sensor_dist 34

// Variáveis que armazenarão os dados do sensor de distância
int sensorValue = 0;
int cmValue = 0;


// Informações do sleep da placa
#define uS_TO_S_FACTOR 1000000  /* Fator de conversão de Micro Segundos para Segundos */
#define TIME_TO_SLEEP  30        /* Tempo que a ESP32 irá dormir (em segundos) */

// Contador de reinícios da ESP32
RTC_DATA_ATTR int bootCount = 0;

/*
Função printa o motivo da ESP32 ter sido acordada
*/

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 : Serial.println("Wakeup caused by external signal using RTC_IO"); break;
    case ESP_SLEEP_WAKEUP_EXT1 : Serial.println("Wakeup caused by external signal using RTC_CNTL"); break;
    case ESP_SLEEP_WAKEUP_TIMER : Serial.println("Wakeup caused by timer"); break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD : Serial.println("Wakeup caused by touchpad"); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
}


// URL da API QUE ESTAMOS UTILIZANDO
//String url = "http://192.168.0.108:8000/distancia/";
String url = "https://projeto-integrado-bittoin.herokuapp.com/distancia";
String sensor = "";

// Dados de conexão do WiFi
const char *ssid = "Wil_Wifi";
const char *password = "PlsChangeMe@senhas0";

void setup(){
	// Inicializa porta serial
	Serial.begin(115200);

	// Inicializa conexão WiFi e tenta conectar
	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.println("Connecting to WiFi..");
	}

	Serial.println("Conectou no WiFi!");

	//Printa razão da ESP32 ter acordado
	print_wakeup_reason();

	 /*
		First we configure the wake up source
		We set our ESP32 to wake up every 5 seconds
	*/
	esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
	Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) +
	" Seconds");

	// Altera resolução da leitura analógica para 10 bits (0-1023)
	analogReadResolution(10);
}

void loop(){
	HTTPClient http;
	
	sensorValue = analogRead(sensor_dist);
  	cmValue = (6762/(sensorValue-9))+2;
	sensor = String(cmValue);

	http.begin(url + sensor);
	int httpCode = http.GET();

	if (httpCode > 0) { //Check for the returning code
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }

    else {
      Serial.println("Error on HTTP request");
    }

	http.end();

	Serial.flush(); 
  	esp_deep_sleep_start();
}