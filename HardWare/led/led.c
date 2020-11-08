/*****************************************************************************
*@file:led.c
*@brief:PIDѧϰ֮LED���������ļ�
*@author:С��
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#include "led.h"
#include "sys.h"

/*
*@Description:����LED��GPIO��ģʽ
*@param:None
*@return:None
*/
void LED_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(LED_RCC_PORT,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Mode = LED_MODE;
	GPIO_InitStructure.GPIO_Speed = LED_SPEED;
	GPIO_Init(LED_PORT,&GPIO_InitStructure);
}

/*
*@Description:���Դ��룬����LED
*@param:None
*@return:None
*/
void LED_Test(void)
{
	PAout(4)=0;
	Soft_Delay();

	PAout(4)=1;
	Soft_Delay();
}

