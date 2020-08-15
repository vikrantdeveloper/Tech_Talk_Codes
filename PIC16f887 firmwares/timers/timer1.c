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
    PORTC=~PORTC;
}
}
void delay()
{ 
   T1CON=0X01;
   TMR1H=0XB1;
   TMR1L=0XDF;
   TMR1IF=0;
   while(TMR1IF==0);
}