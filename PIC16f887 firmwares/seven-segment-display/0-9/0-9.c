#include <pic.h>
void delay(unsigned int);
void main()
{
	TRISC = 0X00;
	PORTC = 0X00;
	int a[23] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X67, 0X77, 0x7c, 0x39, 0x5E, 0X79, 0X71, 0X76, 0X38, 0X06, 0X3F, 0X5C, 0X73, 0X6A};
	int i;
	while (1)
	{
		for (i = 0; i < 23; i++)
		{
			PORTC = a[i];
			delay(60000);
		}
	}
}
void delay(unsigned int d)
{
	while (d)
		d--;
}