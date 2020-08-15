#include <pic.h>
void delay(unsigned int);
void main()
{
  TRISC = 0X00;
  PORTC = 0X00;
  TRISD = 0XFF;
  int a[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7C, 0X07, 0X7F, 0X6F};
  int b[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7C, 0X07, 0X7F, 0X6F};
  int i = 0;
  while (1)
  {
    PORTC = a[i];
    while (RD1 == 1 && i < 9)

    {
      i++;
      delay(20000);
    }

    while (RD0 == 1 && i > 0)
    {
      i = i--;
      delay(20000);
    }
  }
}
void delay(unsigned int d)
{
  while (d)
    d--;
}
