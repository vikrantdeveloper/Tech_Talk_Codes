#include <pic.h>

#define LCD PORTC
#define RS RD0
#define EN RD1
void delay(unsigned int);
void cmd();
void dat();
void latch();
int j, i, h = 0;
char a[30] = " VIKRANTS PROJECTS";
char c[20] = " PROJECTS";
void main()
{
	TRISC = 0X00;
	TRISD = 0x00;
	LCD = 0X38;
	cmd();
	LCD = 0X0E;
	cmd();
	LCD = 0X01;
	cmd();
	LCD = 0X80;
	cmd();

	for (i = 0; i < 14; i++)
	{

		LCD = a[i];
		dat();
		delay(2000);
	}
	LCD = 0xC1;
	cmd();
	for (j = 0; j < 8; j++)
	{
		LCD = c[j];
		dat();
		delay(2000);
	}
	for (h = 0; h < 1; h++)
	{
		LCD = 0X1C;
		cmd();
		delay(20000);
	}
		LCD = 0X8F;
		cmd();
		for (i = 0; i < 14; i++)
		{

			LCD = a[i];
			dat();
			delay(2000);
		}
		LCD = 0xcF;
		cmd();
		for (j = 0; j < 13; j++)
		{
			LCD = c[j];
			dat();
			delay(2000);
		}
		while (1)
		{
			LCD = 0X1C;
			cmd();
			delay(20000);
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