/*****************************************************************************
*@file:motor.c
*@brief:该文件主要用来存放motor电机相关的操作
*@author:小兵
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#include "motor.h"

/*
*@Description:电机接口GPIO配置
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
*@Description:timer1时基初始化配置,配置PWM，用来驱动电机
*@param:psl-预分频系数
*				per-计数周期
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

		GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); 			//PB5引脚重映射

	
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
	
	TIM_CtrlPWMOutputs(PWM_TIM_PORT,ENABLE);	//MOE 主输出使能	
	
	TIM_OC4PreloadConfig(PWM_TIM_PORT,TIM_OCPreload_Enable);
	
	TIM_ARRPreloadConfig(PWM_TIM_PORT, ENABLE); //使能TIMx在ARR上的预装载寄存器
	
	TIM_Cmd(PWM_TIM_PORT,ENABLE);
}

/*
*@Description:电机正转
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
*@brief:电机反转
*@param:None
*@retval:None
*/
void Motor_Default_Rollback(void)
{
//	TIM_SetCompare4(PWM_TIM_PORT, DEFAULT_ROLLBACK_DUTY);					//duty = 50%
	AIN1=1;
	AIN2=0;
}
