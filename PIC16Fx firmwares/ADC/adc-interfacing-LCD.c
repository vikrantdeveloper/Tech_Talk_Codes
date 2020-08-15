#include <pic.h>

// Interface ADC with LCD16*2 //
#define LCD PORTC
#define RS RD0
#define EN RD1

void delay(unsigned int);
int adc_value();
int adc_value1();
void cmd();
void dat();
void latch();
void display2();
int i = 7;
int b, c, h, one, k, h1 = 0;
float temp, temp1;
char a[] = "0123456789";
void display();
int n[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87};
int v[] = {0x90, 0x91, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7};
void main()
{
    ANSEL = 0X01;
    TRISC = 0X00;
    TRISD = 0X00;
    LCD = 0X38;
    cmd();
    LCD = 0X0E;
    cmd();
    LCD = 0X01;
    cmd();
    b = adc_value();
    k = adc_value1();
    while (b)
    {
        one = b % 10;
        display();
        b = b / 10;
    }
    delay(60000);
    one = 0;
    LCD = 0XC0;
    cmd();
    while (k)
    {
        one = k % 10;
        display2();
        k = k / 10;
    }
    delay(50000);
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
void display()
{
    LCD = n[i];
    cmd();
    LCD = a[one];
    dat();
    i--;
}
void display2()
{
    LCD = n[i];
    cmd();
    LCD = a[one];
    dat();
    i--;
}

int adc_value()
{
    ADCON1 = 0X80;
    ADCON0 = 0X03;
    while (GODONE == 1)
        h = (ADRESH << 8) + ADRESL;
    temp = h / 2.02;
    return temp;
}
int adc_value1()
{
    ADCON1 = 0Xc0;
    ADCON0 = 0X02;
    while (GODONE == 1)
        h1 = (ADRESH << 8) + ADRESL;
    temp1 = h1 / 2.02;
    return temp1;
}
