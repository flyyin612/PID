/**
	****************************************************
	*@file			usart.h
	*@author		小兵Demo
	*@date			2015.12.02
	*@version		v3.0
	*@brief			USART串口收发程序
	****************************************************
	*@attention
	*
	*@实验平台：野火 ISO STM32 开发板
	*
	****************************************************
	*/
	#ifndef __USART_H_
	#define __USART_H_
	
	#include "stm32f10x.h"
	#include <stdio.h>
	
	void USART1_Config(u32 nBaudRate);
	int fputc(int ch,FILE *f);
	int fgetc(FILE *f);
	
	#endif


