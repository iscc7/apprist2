#include "config.h"

void delay(uint16 i)
{
    int j;
    for(;i>0;i--)
        for(j=114;j>0;j--);
}
//time0 initial function
void InitTimer0(void)
{
    TMOD = 0x01;
    TH0 = 0x0FF;
    TL0 = 0x09C;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
