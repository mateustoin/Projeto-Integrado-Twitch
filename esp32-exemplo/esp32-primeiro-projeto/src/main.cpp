#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  15        /* Time ESP32 will go to sleep (in seconds) */

RTC_DATA_ATTR int bootCount = 0;

/*
Method to print the reason by which ESP32
has been awaken from sleep
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

#define LED_PIN 2

String url = "http://192.168.0.108:8000/temperatura/";
String sensor = "";

const char *ssid = "Wil_Wifi";
const char *password = "PlsChangeMe@senhas0";

void setup(){
	Serial.begin(115200);
	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.println("Connecting to WiFi..");
	}

	Serial.println("Conectou no WiFi!");

	//Print the wakeup reason for ESP32
	print_wakeup_reason();

	 /*
		First we configure the wake up source
		We set our ESP32 to wake up every 5 seconds
	*/
	esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
	Serial.println("Setup ESP32 to sleep for every " + String(TIME_TO_SLEEP) +
	" Seconds");

	pinMode(LED_PIN, OUTPUT);
}

void loop(){
	digitalWrite(LED_PIN, HIGH);

	HTTPClient http;
	sensor = String(random(0,40));

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

	delay(50);
	digitalWrite(LED_PIN, LOW);

	Serial.flush(); 
  	esp_deep_sleep_start();
}