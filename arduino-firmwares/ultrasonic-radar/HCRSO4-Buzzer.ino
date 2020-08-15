#include"Servo.h"
int y=A0;
int z=A1;
Servo a;
int buzz=10;
int distancefm,d,i,e;
int k=178;
bool g=0; //can be excluded

void setup() 
{
Serial.begin(9600);
pinMode(y,OUTPUT);  //Trigger pin
pinMode(z,INPUT);  //Echo pin
a.attach(9);
pinMode(buzz,OUTPUT);
}
int ultrasonic()
{
int durradfm;
digitalWrite(y,LOW);
delayMicroseconds(2);
digitalWrite(y,HIGH);
delayMicroseconds(10);
durradfm=pulseIn(z,HIGH);
distancefm=0.034*durradfm/2;
return distancefm;
}
void buzzer()
{
  tone(buzz,100); 
  delay(100);        
  noTone(buzz);     
  delay(100);
}

void loop() 
{
 for(i>0; i <= 180; i += 1 && g==0)
 {
     d=ultrasonic();
    if(d>10)
     {
      a.write(i);
      delay(30);
      Serial.println(d);
     }
    else
     {
      Serial.println(d);
      delay(60);
      buzzer();
      i--;
     }
 }
for(i< 180; i>=0; i-=1 && g==0)
 {
  d=ultrasonic();
  if(d>10)
     {
      a.write(i);
      delay(30);
      Serial.println(d);
     }
  else
     {
      Serial.println(d);
      delay(60);
      buzzer();
      i--;
     }
  }
  //Can be excluded
 if(g==1)
 {
   Serial.println(d);
    delay(60);
    buzzer();
 }
 }
