#ifndef CONFIG_H_
#define CONFIG_H_
#define time_delay 10


#include "reg52.h"

void InitTimer0(void);
int count(void);


sbit output = P1^0;
sbit detect = P1^1;







#endif
