//Authors: Kaylie Capurro, Kyle Johnson, Mason Smith

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test"));
  dht.begin();

}

void loop() {
  float h = dht.readHumidity();
  float f = dht.readTempature(true);
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor."));
      return;
    }
 float hif = dht.computeHeatIndex(f,h);
 Serial.print(F(" Humidity: "));
 Serial.print(h);
 Serial.print("% Temperature "));
 Serial.print(f);
 Serial.print(F("degrees F  Heat Index:"));
 Serial.print(hif);
 Serial.print(F(" degrees F"));
}