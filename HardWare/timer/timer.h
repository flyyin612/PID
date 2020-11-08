/*****************************************************************************
*@file:timer.h
*@brief:PID学习之timer.h文件
*@author:小兵
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#ifndef __TIMER_H_
#define __TIMER_H_

#include "stm32f10x.h"

#define TIM_RCC_APBPERIPH_PORT			RCC_APB1Periph_TIM4
#define TIM_PORT										TIM4
	
//define time base prescaler ,period
#define TIMER_BASE_PRESCALER					71
#define TIMER_BASE_PERIOD							999

void TIM4_Config(u32 psl, u32 per);


#endif /*__TIMER_H_*/

