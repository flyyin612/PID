/**
	****************************************************
	*@file			usart.h
	*@author		С��Demo
	*@date			2015.12.02
	*@version		v3.0
	*@brief			USART�����շ�����
	****************************************************
	*@attention
	*
	*@ʵ��ƽ̨��Ұ�� ISO STM32 ������
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


