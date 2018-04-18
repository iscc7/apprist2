#ifndef CONFIG_H_
#define CONFIG_H_

#define time_delay 10
#define N 5
#include "reg52.h"

typedef unsigned int uint8;
typedef unsigned long int uint16;

void InitTimer0(void);
void delay(uint16 i);

//pwm输出引脚
sbit output1 = P1^0;
sbit output2_1 = P1^1;
sbit output2_2 = P1^2;
sbit output3_1 = P1^3;
sbit output3_2 = P1^4;
sbit output4 = P1^5;

/*
--------------------gpio_instrction---------------------
p0 lcd��Ļ���������


p10 �������������pwm���
p11 �����ϼ��ӵĵ����pwm���
p12 �����ϼ��ӵĵ����pwm���
p13 �����¼��ӵĵ����pwm���
p14 �����¼��ӵĵ����pwm���
p15 ���ƴ��ʹ��ĵ����pwm���
P16 �����ϼ��ӳ�ʼ�������벶��
P17 �����¼��ӳ�ʼ�������벶��


p20 ���߼��������벶��

p25 lcd RS
p26	lcd RW
p27 lcd EN

*/




#endif
