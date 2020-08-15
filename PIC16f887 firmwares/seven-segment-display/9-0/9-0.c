#include <pic.h>
void delay(unsigned int);
void main()
{
	TRISC = 0X00;
	PORTC = 0X00;
	int a[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0XED, 0X7C, 0X07, 0X7F, 0X67};
	int i;
	while (1)
	{
		for (i = 9; i >= 0; i--)
		{
			PORTC = a[i];
			delay(50000);
		}
		for (i = 0; i < 10; i++)
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
