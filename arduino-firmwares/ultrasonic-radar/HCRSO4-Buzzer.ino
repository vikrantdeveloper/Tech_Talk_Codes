#include "Servo.h"
#include "stdint.h"

// Pin configuration //
#define SERVOPIN 9
#define TRIGGERPIN A0
#define ECHOPIN A1
#define BUZZPIN 10

Servo a;
int distancefm;
uint8_t g = 0; //can be excluded
uint8_t i = 0; //rotation

void setup()
{
   Serial.begin(9600);
   pinMode(TRIGGERPIN, OUTPUT); //Trigger pin
   pinMode(ECHOPIN, INPUT);     //Echo pin
   a.attach(SERVOPIN);        // attach servo motor
   pinMode(BUZZPIN, OUTPUT);   // buzzer output
}
int ultrasonic()
{
   digitalWrite(TRIGGERPIN, LOW);
   delayMicroseconds(2);
   digitalWrite(TRIGGERPIN, HIGH);
   delayMicroseconds(10);
   int durradfm = pulseIn(ECHOPIN, HIGH);
   int distancefm = 0.034 * durradfm / 2;
   return distancefm;
}
void buzzer()
{
   tone(BUZZPIN, 100);
   delay(100);
   noTone(BUZZPIN);
   delay(100);
}

void loop()
{
   for (i = 0; i <= 180; i += 1 && g == 0)
   {
      distancefm = ultrasonic();
      if (distancefm > 10)
      {
         a.write(i);
         delay(30);
         Serial.println(distancefm);
      }
      else
      {
         Serial.println(distancefm);
         delay(60);
         buzzer();
         i--;
      }
   }
   for (i = 180; i >= 0; i -= 1 && g == 0)
   {
      distancefm = ultrasonic();
      if (distancefm > 10)
      {
         a.write(i);
         delay(30);
         Serial.println(distancefm);
      }
      else
      {
         Serial.println(distancefm);
         delay(60);
         buzzer();
         i--;
      }
   }
   //Can be excluded
   if (g == 1)
   {
      Serial.println(distancefm);
      delay(60);
      buzzer();
   }
}
