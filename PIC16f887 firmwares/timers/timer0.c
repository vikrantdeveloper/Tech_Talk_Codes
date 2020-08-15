#include<PIC.H>
void delay();
void main()
{
	TRISC=0x00;
	PORTC=0x00;
while(1)
{
	
    delay();
    delay();
    delay();
    delay():
    delay();
    delay();
    delay():
    delay():
    delay():
    delay():
    PORTC=~PORTC;
}
}
void delay()
{ 
   OPTION=0x07;
   TMR0=60;
   T0IF=0;
   while(T0IF==0);
}