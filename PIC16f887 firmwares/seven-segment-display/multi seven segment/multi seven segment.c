#include <pic.h>
void delay(unsigned int);
void main()
{
    TRISC = 0X00;
    PORTC = 0X00;
    TRISD = 0X00;
    PORTD = 0X00;
    int a[10] = {0X06, 0X5B, 0X4F, 0X66};
    int b[10] = {0x01, 0x02, 0x04, 0x08};

    while (1)
    {
        int i = 0;
        while (i <= 4)
        {
            PORTD = b[i];
            PORTC = a[i];
            delay(50);
            i++;
        }
    }
}

void delay(unsigned int d)
{
    while (d)
        d--;
}