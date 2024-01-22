#include <Arduino.h>
#include <DHT.h>

// Define the pins that we will use
#define SENSOR 33
#define LED 26

DHT dht(SENSOR, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(LED, OUTPUT);
}

void loop() {
  // Effectuer une mesure toutes les 5s
 
  delay(5000);
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