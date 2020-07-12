/*
 * Download DHT library from the adfruit to Interface DHT11 sensor
 */
#include "dht.h"
#define dht_apin A2 
 
dht DHT;
 
void setup()
{
  Serial.begin(9600);
  delay(50);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
}
 
void loop()
{
    DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    delay(5000);
 }
