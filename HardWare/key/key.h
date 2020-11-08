/*****************************************************************************
*@file:key.h
*@brief:PID学习之key.h文件
*@author:小兵
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#ifndef __KEY_H_
#define __KEY_H_

#include "stm32f10x.h"

#define KEY_RCC_PORT			RCC_APB2Periph_GPIOA					//user
#define KEY_PORT					GPIOA
#define KEY_PIN						GPIO_Pin_5
#define KEY_MODE					GPIO_Mode_IPU

//#define KEY1_RCC_PORT			RCC_APB2Periph_GPIOA
//#define KEY1_PORT					GPIOA
#define KEY1_PIN					GPIO_Pin_3								//k1
//#define KEY1_MODE					GPIO_Mode_IPU

//#define KEY2_RCC_PORT			RCC_APB2Periph_GPIOA
//#define KEY2_PORT					GPIOA
#define KEY2_PIN					GPIO_Pin_2								//k2
//#define KEY2_MODE					GPIO_Mode_IPU

//#define KEY3_RCC_PORT			RCC_APB2Periph_GPIOA
//#define KEY3_PORT					GPIOA
#define KEY3_PIN					GPIO_Pin_11							//k3
//#define KEY3_MODE					GPIO_Mode_IPU

//#define KEY4_RCC_PORT			RCC_APB2Periph_GPIOA
//#define KEY4_PORT					GPIOA
#define KEY4_PIN					GPIO_Pin_12							//k4
//#define KEY4_MODE					GPIO_Mode_IPU

#define KEY_VALUE					GPIO_ReadInputDataBit(KEY_PORT,KEY_PIN)
#define KEY1_VALUE			  GPIO_ReadInputDataBit(KEY_PORT,KEY1_PIN)
#define KEY2_VALUE			  GPIO_ReadInputDataBit(KEY_PORT,KEY2_PIN)
#define KEY3_VALUE				GPIO_ReadInputDataBit(KEY_PORT,KEY3_PIN)
#define KEY4_VALUE				GPIO_ReadInputDataBit(KEY_PORT,KEY4_PIN)

void Key_Init(void);
void Key_Check(void);

#endif /*__KEY_H_*/
