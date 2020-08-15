#include <pic.h>


void delay(unsigned int);
int i = 0;
int a[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0XED, 0X7C, 0X07, 0X7F, 0X67};
void interrupt isr()
{
	if (T0IF == 1)
	{
		TMR0 = 0;
		T0IF = 0;

		if (i <= 9)
		{
			PORTD = a[i];  // LED LIGHTS
			i++;
		}
	}
}
void main()
{
	TRISC = 0X00;
	PORTC = 0XFF;
	TRISD = 0X00;
	OPTION = 0X07; //TO timer set
	TMR0 = 0;	   //start bit
	T0IF = 0;	   //calculate till 255
	GIE = 1;
	T0IE = 1;

	while (1)
	{
		PORTC = ~PORTC;
		delay(20000);
	}
}
void delay(unsigned int d)
{
	while (d--);
}