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
	InitTimer0();	   								//��ʼ��pwm�źż�ʱ��
	motor_1_stop();
	motor_2_stop();
	motor_3_stop();
	//motor_4_stop();

	Init_LCD1602();									//��ʼ��LCD1602
	LCD1602_write_com(0x80);						//ָ�����õ���һ��
	LCD1602_write_word("counter number:");			//��ʾ����
	LCD1602_write_com(0x80+0x40+5);					//ָ�����õ��ڶ���
	LCD1602_write_word(num2str(00));				//��ʾ����

//	motor_2_init();									//��������
//	motor_3_init();
	while(1)
	{

		counter_num = counter(counter_num);
		LCD1602_write_com(0x80+0x40+5);					//ָ�����õ��ڶ���
		LCD1602_write_word(num2str(counter_num));
		if(counter_num >= N)							//�ڼ�������Ŀ�괥��
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


	//pwm1 ���
	if(t>pwm_1)
	{
		output1 = 0;
	}
	else
	{
		output1 = 1;
	}
	//pwm2 ���
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
	//pwm3 ���
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

	//pwm4 ���
	if(t>pwm_4)
	{
		output4 = 0;
	}
	else
	{
		output4 = 1;
	}
	

	//���Ʊ���++ 
	t++;
	if(t == 100)
	{
		t = 0;
	}
}


