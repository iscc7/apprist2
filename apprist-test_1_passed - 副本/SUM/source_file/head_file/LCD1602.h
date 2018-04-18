#ifndef __LCD1602_H__
#define __LCD1602_H__


#include <reg52.h>

//LCD1602 IO设置
#define LCD1602_PORT P0
sbit LCD1602_RS = P2^5;
sbit LCD1602_RW = P2^6;
sbit LCD1602_EN = P2^7;

//函数或者变量声明
void LCD1602_delay_ms(unsigned int n);
void LCD1602_write_com(unsigned char com);
void LCD1602_write_data(unsigned char dat);
void LCD1602_write_word(unsigned char *s);
void Init_LCD1602();
char* num2str(int number);
#endif