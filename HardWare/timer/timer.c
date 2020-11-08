/*****************************************************************************
*@file:timer.c
*@brief:PID学习之timer.c文件,timer主要用来配置时基，做延时使用
*@author:小兵
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#include "timer.h"

/*
*@Description:timer3时基初始化配置,用来做延时
*@param:psl-预分频系数
*				per-计数周期
*@return:None
*/
void TIM4_Config(u32 psl, u32 per)
{
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseInitStructure;
	
	RCC_APB1PeriphClockCmd(TIM_RCC_APBPERIPH_PORT,ENABLE);
	
	TIM_TimeBaseInitStructure.TIM_Prescaler = psl;
	TIM_TimeBaseInitStructure.TIM_Period = per;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM_PORT,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM_PORT,TIM_IT_Update,ENABLE);
	
	TIM_Cmd(TIM_PORT,ENABLE);
}

