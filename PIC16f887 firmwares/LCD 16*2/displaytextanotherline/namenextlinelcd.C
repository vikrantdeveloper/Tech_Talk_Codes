#include <pic.h>

#define LCD PORTC
#define RS RD0
#define EN RD1

void delay(unsigned int);
void cmd();
void dat();
void latch();
int j, i = 0;
char a[10] = "VIKRANT";
char c[20] = "THAKUR";
void main()
{
	ANSEL = 0X00;
	TRISC = 0X00;
	TRISD = 0x00;
	LCD = 0X38;
	cmd();
	LCD = 0X0E;
	cmd();
	LCD = 0X01;
	cmd();
	LCD = 0X8F;
	cmd();

	for (i = 0; i < 8; i++)
	{

		LCD = a[i];
		dat();
		delay(200);
	}
	LCD = 0xCF;  // NEXT LINE
	cmd();

	for (j = 0; j < 14; j++)
	{

		LCD = c[j];
		dat();
		delay(200);
	}
	while (1)
	{
		LCD = 0X1C;  // RIGHT SHIFT
		cmd();
		delay(2000);
	}
}
void delay(unsigned int d)
{
	while (d > 0)
		d--;
}
void latch()
{
	EN = 1;
	delay(50);
	EN = 0;
	delay(100);
}
void cmd()
{
	RS = 0;
	latch();
}
void dat()
{
	RS = 1;
	latch();
}