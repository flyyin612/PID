/*****************************************************************************
*@file:nvic.c
*@brief:PID学习之nvic.c文件,该文件主要用来配置中断
*@author:小兵
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#include "nvic.h"

/*
*@Description:NVIC初始化配置
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

