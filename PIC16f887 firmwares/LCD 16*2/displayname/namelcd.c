#include <pic.h>

#define LCD PORTC
#define RS RD0
#define EN RD1

void delay(unsigned int);
void cmd();
void dat();
void latch();
int i = 0;
char a[23] = "VIKRANT THAKUR";

int b[10] = {0X80, 0X81, 0X82, 0X83, 0X84, 0X85, 0X86};
void main()
{
	TRISC = 0X00;
	TRISD = 0x00;
	LCD = 0X38; // SET 8-BIT 2 LINE 5*7	
	cmd();
	LCD = 0X0E;  // CURSOR ON
	cmd();
	LCD = 0X01;  // CLEAR DISPLAY
	cmd();

	while (a[i] != '\0')
	{
		LCD = b[i];
		cmd();
		LCD = a[i];
		dat();
		i++;
	}

	while (1)
		;
}
void delay(unsigned int d)
{
	while (d--)
		;
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