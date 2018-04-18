#ifndef CONFIG_H_
#define CONFIG_H_

#define time_delay 10
#define N 5
#include "reg52.h"

typedef unsigned int uint8;
typedef unsigned long int uint16;

void InitTimer0(void);
void delay(uint16 i);

//pwm杈撳嚭寮曡剼
sbit output1 = P1^0;
sbit output2_1 = P1^1;
sbit output2_2 = P1^2;
sbit output3_1 = P1^3;
sbit output3_2 = P1^4;
sbit output4 = P1^5;

/*
--------------------gpio_instrction---------------------
p0 lcd屏幕的数据输出


p10 控制链条电机的pwm输出
p11 控制上夹子的电机的pwm输出
p12 控制上夹子的电机的pwm输出
p13 控制下夹子的电机的pwm输出
p14 控制下夹子的电机的pwm输出
p15 控制传送带的电机的pwm输出
P16 控制上架子初始化的输入捕获
P17 控制下夹子初始化的输入捕获


p20 障线计数的输入捕获

p25 lcd RS
p26	lcd RW
p27 lcd EN

*/




#endif
