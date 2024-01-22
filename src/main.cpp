#include <Arduino.h>
#include <DHT.h>

// Define the pins that we will use
#define SENSOR 33
#define LED 26
#define SLEEP_TIME 5000000 // 5 seconds in microseconds

DHT dht(SENSOR, DHT11);

// Function prototypes
void takeReading();
void goToDeepSleep();


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(LED, OUTPUT);

  takeReading();
  goToDeepSleep();
}

void loop() {
  
}

void takeReading(){
  // Effectuer une mesure toutes les 5s
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Afficher l'humidité relative avec un peu de formatage
  Serial.print("Humidite : ");
  Serial.print(h);
  Serial.println(" %");

  // Afficher la température avec un peu de formatage
  Serial.print("Temperature : ");
  Serial.print(t);
  Serial.println(" ºC");
}

void goToDeepSleep() {
  // Go to deep sleep for 5 seconds
  
  esp_sleep_enable_timer_wakeup(SLEEP_TIME);
  Serial.flush();
  delay(20);
  esp_deep_sleep_start();
}