#include <Arduino.h>
/*
#define LED 2
#define tempo_invervalo 10 // Tempo em segundos

const int sensor_presenca = 27;

// Timer: Auxiliary variables
unsigned long now = millis();
unsigned long lastTrigger = 0;
boolean startTimer = false;

// Checks if motion was detected, sets LED HIGH and starts a timer
void IRAM_ATTR detectsMovement() {
  Serial.println("MOTION DETECTED!!!");
  digitalWrite(LED, HIGH);
  startTimer = true;
  lastTrigger = millis();
}


void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(sensor_presenca, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(sensor_presenca), detectsMovement, RISING);

  // Set LED to LOW
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop(){
    // Current time
    now = millis();
    // Turn off the LED after the number of seconds defined in the timeSeconds variable
    if(startTimer && (now - lastTrigger > (tempo_invervalo*1000))) {
        Serial.println("Motion stopped...");
        digitalWrite(LED, LOW);
        startTimer = false;
    }
}
*/
/*
#define LED 2
#define sensor_dist 13

int sensorValue = 0;
int cmValue = 0;

void setup(){
  Serial.begin(115200);

  analogReadResolution(10);
}

void loop(){
  sensorValue = analogRead(sensor_dist);
  cmValue = (6762/(sensorValue-9))+2;
  Serial.print("Valor lido = ");
  Serial.print(cmValue);
  Serial.println(" cm");
  delay(250);
}
*/