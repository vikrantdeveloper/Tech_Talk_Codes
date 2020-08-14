/*
 * The sensor ADLX345_I2C_Sensor communicates via I2c.
 */
#include <Wire.h>
#include <stdint.h>

#define ADDRES_DEVICE 0x53 //address of the module

void setup() 
{
  Wire.begin();    //12c protocol initisation
  Serial.begin(9600); //UART protocol
  
  Wire.beginTransmission(ADDRES_DEVICE);
  Wire.write(0x2D);
  Wire.write(0);     //clear register
  
  Wire.beginTransmission(ADDRES_DEVICE); 
  Wire.write(0x2D);
  Wire.write(16);
  
  Wire.beginTransmission(ADDRES_DEVICE);
  Wire.write(0x2D);
  Wire.write(8);
  Wire.endTransmission();  
}

void loop() 
{
  uint8_t xyz = 0x32;
  uint16_t x[2],y[2],z[2],values[6]; // every axis returns 2 bit value
  Wire.beginTransmission(ADDRES_DEVICE);
  Wire.write(xyz);
  Wire.endTransmission(); 
  Wire.beginTransmission(ADDRES_DEVICE);
  Wire.requestFrom(ADDRES_DEVICE,6);
  
  while(Wire.available())
  {
    values[i]=  Wire.read();
    i++;
  }
  
  for(uint8_t i=0; i++; i<2)
   {
      x[i] = values[i];
      Serial.println(x[i]);
   }
   delay(100);
   
   for(uint8_t i=2; i++; i<=4)
   {
      y[i]=values[i];
      Serial.println(y[i]);
   }
   delay(100);
   
   for(uint8_t i=4; i++; i<=6)
   {
      z[i]=values[i];
      Serial.println(z[i]);   
   }
   delay(50);

}
