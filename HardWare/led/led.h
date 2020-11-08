/*****************************************************************************
*@file:led.c
*@brief:PIDѧϰ֮LED���������ļ�
*@author:С��
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#ifndef __LED_H_
#define __LED_H_

#include "stm32f10x.h"

//LED define
#define LED_RCC_PORT		RCC_APB2Periph_GPIOA
#define LED_PORT				GPIOA
#define LED_PIN					GPIO_Pin_4
#define LED_MODE				GPIO_Mode_Out_PP
#define LED_SPEED				GPIO_Speed_50MHz

void LED_Init(void);
void LED_Test(void);

#endif  /*__LED_H_ */
