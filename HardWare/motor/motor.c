/*****************************************************************************
*@file:motor.c
*@brief:���ļ���Ҫ�������motor�����صĲ���
*@author:С��
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#include "motor.h"

/*
*@Description:����ӿ�GPIO����
*@param:None
*@return:None
*/
void Motor_GPIO_Config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(MOTOR_GPIO_RCC_PORT,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = MOTOR_GPIO_PIN1 | MOTOR_GPIO_PIN2;
	GPIO_InitStructure.GPIO_Mode = MOTOR_GPIO_MODE;
	GPIO_InitStructure.GPIO_Speed = MOTOR_GPIO_SPEED;
	GPIO_Init(MOTOR_GPIO_PORT,&GPIO_InitStructure);
}

/*
*@Description:timer1ʱ����ʼ������,����PWM�������������
*@param:psl-Ԥ��Ƶϵ��
*				per-��������
*@return:None
*/
void Motor_PWM_Config(u16 psl,u16 per)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef	TIM_OCInitStructure;
	
	Motor_GPIO_Config();
	
	RCC_APB2PeriphClockCmd(MOTOR_TIM_GPIO_PORT2,ENABLE);
	RCC_APB1PeriphClockCmd(MOTOR_TIM_RCC_PORT1,ENABLE);

		GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); 			//PB5������ӳ��

	
	GPIO_InitStructure.GPIO_Pin = PWM_GPIO_PIN2;
	GPIO_InitStructure.GPIO_Mode = PWM_GPIO_MODE;
	GPIO_InitStructure.GPIO_Speed = PWM_GPIO_SPEED;
	GPIO_Init(PWM_GPIO_PORT,&GPIO_InitStructure);
	
	TIM_TimeBaseInitStructure.TIM_Prescaler = psl;
	TIM_TimeBaseInitStructure.TIM_Period = per;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(PWM_TIM_PORT,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(PWM_TIM_PORT,&TIM_OCInitStructure);
	
	TIM_CtrlPWMOutputs(PWM_TIM_PORT,ENABLE);	//MOE �����ʹ��	
	
	TIM_OC4PreloadConfig(PWM_TIM_PORT,TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(PWM_TIM_PORT, ENABLE); //ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	
	TIM_Cmd(PWM_TIM_PORT,ENABLE);
}

/*
*@Description:�����ת
*@param:None
*@retval:None
*/
void Motor_Default_Foreward(void)
{
//	TIM_SetCompare4(PWM_TIM_PORT, DEFAULT_FOREWARD_DUTY);					//duty = 50%
	AIN1=0;
	AIN2=1;
}

/*
*@brief:�����ת
*@param:None
*@retval:None
*/
void Motor_Default_Rollback(void)
{
//	TIM_SetCompare4(PWM_TIM_PORT, DEFAULT_ROLLBACK_DUTY);					//duty = 50%
	AIN1=1;
	AIN2=0;
}
