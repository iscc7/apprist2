#include "config.h"

int pwm_c = 50;
int t = 0 ;

void main()
{
	InitTimer0();
	while(1)
	{
		
	}

}




void Timer0Interrupt(void) interrupt 1
{
    TH0 = 0x0FF;
    TL0 = 0x9C;



	if(t>pwm_c)
	{
		output = 1;
	}
	else
	{
		output = 0;
	}
	if(t==100)
	{
		t = 0;
	}
	t++;

}


