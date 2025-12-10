// Sensor: DHT11 https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf?srsltid=AfmBOoppbMfYYjFHGoVID6cEWIIbpBsEvgxdaUCFnPbmN43EMg3cWW_v

#include "DHT.h"

#define DHTPIN 2 // pin
#define DHTTYPE DHT11 // sensor type

DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float tempC = dht.readTemperature();   // Celsius
  float humidity = dht.readHumidity(); 

  // for debugging pin(0, mis-wiring; 1 sensor is live):
  // Serial.print("DEBUG - Reading raw pin: ");
  // Serial.println(digitalRead(DHTPIN));
  
  if (isnan(tempC) || isnan(humidity)) {
    Serial.println("Failed to read from DHT11!");
    delay(2000);
    return;
  }

  Serial.print("Temp (C): ");
  Serial.print(tempC);
  Serial.print("    Humidity (%): ");
  Serial.println(humidity);

  // every 1s
  delay(1000);
}
