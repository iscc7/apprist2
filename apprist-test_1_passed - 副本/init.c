#include "config.h"



void InitTimer0(void)
{
    TMOD = 0x01;
    TH0 = 0x0FF;
    TL0 = 0x9C;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
