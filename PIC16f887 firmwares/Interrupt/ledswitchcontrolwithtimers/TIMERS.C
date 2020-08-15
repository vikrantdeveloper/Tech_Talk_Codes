#include <pic.h>

void delay(unsigned int);
int i, b, h, m = 0;
int a[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0XED, 0X7C, 0X07, 0X7F, 0X67};
void interrupt isr();

int main()
{
  TRISC = 0X00;
  PORTC = 0X00;
  OPTION = 0X07;
  TMR0 = 1;
  T0IF = 0;
  GIE = 1;
  T0IE = 1;

  while (1)
  {
    PORTC = 0XF0;
    delay(60000);
    PORTC = 0X00;
    delay(60000);
    return PORTC;
  }
}

void interrupt isr()
{
  if (T0IF == 1)
  {
    TMR0 = 0;
    T0IF = 0;
    b = PORTC;
    h = 0x0f;
    PORTC = b | h;
  }
}

void delay(unsigned int d)
{
  while(d--);
}