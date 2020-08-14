/*
 * This Source code will detech human raditions. Set the potentiometer to set threshold of the pin
 */
#define PIR_PIN 5 
#define LED_PIN 13

void setup() 
{
    pinMode(PIR_PIN, INPUT);// setting pir output as arduino input
    pinMode(LED_PIN, OUTPUT);//setting led as output
    Serial.begin(9600);//serial communication between arduino and pc
}
void loop() 
{
  if(digitalRead(PIR_PIN) == HIGH) // reading the data from the pir sensor
  {
    digitalWrite(LED_PIN, HIGH); // setting led to high
    Serial.println("motion detected");
  }
  else 
  {
    digitalWrite(LED_PIN, LOW); // setting led to low
    Serial.println("scanning");
  }
}
