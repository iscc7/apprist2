#include "config.h"
#include "motor.h"


// 链传动 motor driver


void motor_1_run(char pwm_control)
{
//	if(pwm_control > 100)
//	{
//		pwm_control = 20;
//	}
//	else
//	{
		pwm_1 = pwm_control;
//	}
}
void motor_1_stop()
{
	pwm_1 = 0;
}


//上侧夹子 driver
void motor_2_init()
{
	//motor_2_detecter = 1;
	while(motor_2_detecter)
	{
		delay(2);
		while(motor_2_detecter)
		{
			motor_2_backward();
			
		}
	}
	motor_2_stop();
	motor_2_forward_time(65000);
		
}


void motor_2_forward()
{
	pwm_2_1 = 80;
	pwm_2_2 = 0;	
}
void motor_2_backward()
{
	pwm_2_1 = 0;
	pwm_2_2 = 80; 	
}
void motor_2_stop()
{
	pwm_2_1 = 0;
	pwm_2_2 = 0;
}
void motor_2_forward_time(long int time)
{
	
	motor_2_forward();
	delay(time);
	motor_2_stop();
	

}
void motor_2_backward_time(long int time)
{
	motor_2_backward();
	delay(time);
	motor_2_stop();
}


// motor 3
void motor_3_init()
{
	//motor_3_detecter = 1;
	while(motor_3_detecter)
	{
		delay(2);
		while(motor_3_detecter)
		{
			motor_3_backward();
		
		}
	}
	motor_3_stop();
	motor_3_forward_time(20625);
		
}

void motor_3_forward()
{
	pwm_3_1 = 80;
	pwm_3_2 = 0;	
}
void motor_3_backward()
{
	pwm_3_1 = 0;
	pwm_3_2 = 80;	
}
void motor_3_stop()
{
	pwm_3_1 = 0;
	pwm_3_2 = 0;
}
void motor_3_forward_time(long int time)
{
	
	motor_3_forward();
	delay(time);
	motor_3_stop();

}
void motor_3_backward_time(long int time)
{
	motor_3_backward();
	delay(time);
	motor_3_stop();
}


void motor_4_run_time()
{
	pwm_4 = 80;
	delay(motor_4_time);
	pwm_4 = 0;
}



