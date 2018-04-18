#include "LCD1602.h"

//****************************************************
//MS延时函数(12M晶振下测试)
//****************************************************
void LCD1602_delay_ms(unsigned int n)
{
	unsigned int  i,j;
	for(i=0;i<n;i++)
		for(j=0;j<123;j++);
}

//****************************************************
//写指令
//****************************************************
void LCD1602_write_com(unsigned char com)
{
	LCD1602_RS = 0;
	LCD1602_delay_ms(1);
	LCD1602_EN = 1;
	LCD1602_PORT = com;
	LCD1602_delay_ms(1);
	LCD1602_EN = 0;
}

//****************************************************
//写数据
//****************************************************
void LCD1602_write_data(unsigned char dat)
{
	LCD1602_RS = 1;
	LCD1602_delay_ms(1);	
	LCD1602_PORT = dat;
	LCD1602_EN = 1;
	LCD1602_delay_ms(1);
	LCD1602_EN = 0;
}

//****************************************************
//连续写字符
//****************************************************
void LCD1602_write_word(unsigned char *s)
{
	while(*s>0)
	{
		LCD1602_write_data(*s);
		s++;
	}
}

void Init_LCD1602()
{
	LCD1602_EN = 0;
	LCD1602_RW = 0;						//设置为写状态
	LCD1602_write_com(0x38);			//显示模式设定
	LCD1602_write_com(0x0c);			//开关显示、光标有无设置、光标闪烁设置
	LCD1602_write_com(0x06);			//写一个字符后指针加一
	LCD1602_write_com(0x01);			//清屏指令
}

char* num2str(int number)
{
	static char str[3];
	if(number<100)
	{
		str[0] = (number/10) + 48;
		str[1] = number%10 + 48;	
		str[2] = '\0';
	}
	else 
	{
		str[0] = 'e';
		str[1] = 'r';
		str[2] = '\0';
	}			  
	return str;
}



