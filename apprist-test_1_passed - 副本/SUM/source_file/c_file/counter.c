#include "config.h"
#include "counter.h"


char counter(int counter_num)
{
    //static int counter_num =0 ;
    uint8 i;
    if(detect)
    {
        i = 0;
        while(detect)
        {
            delay(10); 
            i++;
        }
        if(i>boundary)
        {
            counter_num++;
        }
    }
	

	if(counter_num > N ) //重新计数，从一开始
	{
		counter_num = 1;
	}
   	return counter_num;
}
