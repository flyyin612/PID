/*****************************************************************************
*@file:nvic.c
*@brief:PIDѧϰ֮nvic.c�ļ�,���ļ���Ҫ���������ж�
*@author:С��
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#include "nvic.h"

/*
*@Description:NVIC��ʼ������
*@param:None
*@return:None
*/
void NVIC_Config(void)
{
	NVIC_InitTypeDef	NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
//	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
}

