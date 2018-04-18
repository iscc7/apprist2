#ifndef MOTOR_H_
#define MOTOR_H_
#define motor_1_time 20000
#define motor_2_time 65000
#define motor_3_time 20625
#define motor_4_time 20000

extern int pwm_1;
extern int pwm_2_1;
extern int pwm_2_2;
extern int pwm_3_1;
extern int pwm_3_2;
extern int pwm_4;

sbit motor_2_detecter = P1^6;
sbit motor_3_detecter = P1^7;

void motor_1_run(char pwm_control);
void motor_1_stop(); 				
//链传动motor

void motor_2_init();
void motor_2_forward();
void motor_2_backward();
void motor_2_stop();
void motor_2_forward_time(long int time);
void motor_2_backward_time(long int time);
 //上侧夹子
void motor_3_init();
void motor_3_forward();
void motor_3_backward();
void motor_3_stop();
void motor_3_forward_time(long int time);
void motor_3_backward_time(long int time);
//下侧夹子
void motor_4_run_time();





#endif