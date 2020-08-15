/* The RFID reader EM18 communicates via UART */
/*
 * The program display the Slot available in the parking lot system , Whenever someone taps the card stored with specific ID then he will be granted access , LCD display the list of slots available.
 * IR sensors records the Input and output car coming in, going out
 */
#include <string.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);                  // Initilise LCD with SPI Interface pins
#define x 6
#define y 7
#define a 8
#define e 9

uint8_t b,h = 0;                                            // count slot in different places
char input[13]; 
char arr[13]= "270012F14783";                               // character array of size 12 
boolean flag = 0;                                           // flag =0

static void lcd_initialise(void)
{
  lcd.begin(16,2);
    
  lcd.setCursor(0,0);
  lcd.print("INFORMATION");
  lcd.setCursor(0,1);
  lcd.print("BROADCAST SYSTEM");
  
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("USING");
  lcd.setCursor(0,1);
  lcd.print("IOT");
  
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SLOTS:");
  lcd.setCursor(0,1);
  lcd.print("SPEED:");
  
  lcd.setCursor(6,0);
  lcd.print(b);
  lcd.setCursor(6,1);
  lcd.print(0);
}
static void sensors_initialise()
{
  pinMode(x,INPUT);
  pinMode(y,INPUT);
  pinMode(a,INPUT);
  pinMode(e,INPUT);
}
void setup()
{
   Serial.begin(9600);                                  // begin serial port with baud rate 9600bps
   lcd_initialise();
   sensors_initialise();
}
void loop()
{
   if(Serial.available())
   {
      uint8_t count = 0;
      while(Serial.available() && count < 12)          // Read 12 characters and store them in input array
      {
         input[count] = Serial.read();
         count++;
         delay(5);
      }
      Serial.print(input);                             // Print RFID tag number 
      
      if(strcmp(input,arr)== 0)
      {
            Serial.println("Match Found");
            flag  = 1;
      }
      else
      {
            Serial.println("Match Not Found");
            flag = 0;
      }
   }
   if(flag == 1)
   {
        if(b == 10)
        {
            Serial.println("<A> is full");
            flag = 0;
            
        }
        else if(b == 15)
        {
            Serial.println("<B> is full");
            flag = 0;     
        }
        else if(b == 20)
        {
            Serial.println("<C> is full");
            flag = 0;
        }
        else if(h == 10)
        {
            Serial.println("<D> is full");
            flag = 0;
           
        }
        else if(h == 15)
        {
            Serial.println("<E> is full");
            flag = 0;
        }    
   
  if(digitalRead(x) == LOW && b < 20)
  {
     b = b + 1;
     Serial.print("Slot value:");
     Serial.println(b);
     Serial.println("Park car in A or B Slot");
     lcd.setCursor(6,0);
     lcd.print(b);
     lcd.print(" ");
  }
  else if(digitalRead(y) == HIGH && b > 0)
  {
     b = b - 1;
     Serial.print("Slot value:");
     Serial.println(b);
     lcd.setCursor(6,0);
     lcd.print(b);
     Serial.println("Park car in A or B Slot");
     lcd.print(" ");
  }
  if(digitalRead(a) == LOW && h < 15)
  {
     h = h + 1;
     Serial.print("Slot value:");
     Serial.println(h);
     lcd.setCursor(6,1);
     lcd.print(h);
     Serial.println("Park car in C or D Slot");
     lcd.print("  ");
  }
  else if(digitalRead(e) == HIGH && h > 0)
  {
     h = h - 1;
     Serial.print("Slot value:");
     Serial.println(h);
     lcd.setCursor(6,1);
     Serial.println("Park car in C or D Slot");
     lcd.print(h);
     lcd.print("  ");
  }
 }
 else
 {
    Serial.println("Welcome to parking Slot system");
    lcd_initialise();
 }
}
