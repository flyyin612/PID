/*****************************************************************************
*@file:timer.c
*@brief:PIDѧϰ֮timer.c�ļ�,timer��Ҫ��������ʱ��������ʱʹ��
*@author:С��
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#include "timer.h"

/*
*@Description:timer3ʱ����ʼ������,��������ʱ
*@param:psl-Ԥ��Ƶϵ��
*				per-��������
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

