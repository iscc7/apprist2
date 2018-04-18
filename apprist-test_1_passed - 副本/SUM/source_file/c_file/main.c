#include "config.h"
#include "counter.h"
#include "LCD1602.h"
#include "motor.h"

int pwm_1 = 0;
int pwm_2_1 = 0;
int pwm_2_2 = 0;
int pwm_3_1 = 0;
int pwm_3_2 = 0;
int pwm_4 = 0;

int t = 0 ;

void main()
{
	int counter_num;
	InitTimer0();	   								//初始化pwm信号计时器
	motor_1_stop();
	motor_2_stop();
	motor_3_stop();
	//motor_4_stop();

	Init_LCD1602();									//初始化LCD1602
	LCD1602_write_com(0x80);						//指针设置到第一行
	LCD1602_write_word("counter number:");			//显示内容
	LCD1602_write_com(0x80+0x40+5);					//指针设置到第二行
	LCD1602_write_word(num2str(00));				//显示内容

//	motor_2_init();									//卡主程序
//	motor_3_init();
	while(1)
	{

		counter_num = counter(counter_num);
		LCD1602_write_com(0x80+0x40+5);					//指针设置到第二行
		LCD1602_write_word(num2str(counter_num));
		if(counter_num >= N)							//在计数等于目标触发
		{
			motor_1_stop();
			motor_4_run_time();		
			

			motor_2_backward_time(motor_2_time);			
			delay(10000);
			motor_2_forward_time(motor_2_time);
			delay(10000);
			motor_3_backward_time(motor_3_time);
			delay(10000);
			motor_3_forward_time(motor_3_time);
			delay(10000);
			counter_num = 0;
			
		}
		else
		{
			motor_1_run(70);

		}
	}

}


//PWM 
void Timer0Interrupt(void) interrupt 1
{
    TH0 = 0xFF;
    TL0 = 0x9C;


	//pwm1 输出
	if(t>pwm_1)
	{
		output1 = 0;
	}
	else
	{
		output1 = 1;
	}
	//pwm2 输出
	if(t>pwm_2_1)
	{
		output2_1 = 0;
	}
	else
	{
		output2_1 = 1;
	}

	if(t>pwm_2_2)
	{
		output2_2 = 0;
	}
	else
	{
		output2_2 = 1;
	}
	//pwm3 输出
	if(t>pwm_3_1)
	{
		output3_1 = 0;
	}
	else
	{
		output3_1 = 1;
	}
	if(t>pwm_3_2)
	{
		output3_2 = 0;
	}
	else
	{
		output3_2 = 1;
	}

	//pwm4 输出
	if(t>pwm_4)
	{
		output4 = 0;
	}
	else
	{
		output4 = 1;
	}
	

	//控制变量++ 
	t++;
	if(t == 100)
	{
		t = 0;
	}
}


