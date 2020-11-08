/*****************************************************************************
*@file:motor.h
*@brief:该文件主要用来存放motor电机的头文件
*@author:小兵
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "stm32f10x.h"
#include "sys.h"

#define MOTOR_TIM_RCC_PORT1					RCC_APB1Periph_TIM3
#define MOTOR_TIM_GPIO_PORT2				RCC_APB2Periph_GPIOB

#define PWM_GPIO_PORT								GPIOB
//#define PWM_GPIO_PIN1								GPIO_Pin_0
#define PWM_GPIO_PIN2								GPIO_Pin_1
#define PWM_GPIO_MODE								GPIO_Mode_AF_PP
#define PWM_GPIO_SPEED							GPIO_Speed_50MHz

#define MOTOR_GPIO_RCC_PORT					RCC_APB2Periph_GPIOB
#define MOTOR_GPIO_PORT							GPIOB
#define MOTOR_GPIO_PIN1							GPIO_Pin_12
#define MOTOR_GPIO_PIN2							GPIO_Pin_13
//#define MOTOR_GPIO_PIN3							GPIO_Pin_14
//#define MOTOR_GPIO_PIN4							GPIO_Pin_15
#define MOTOR_GPIO_MODE							GPIO_Mode_Out_PP
#define MOTOR_GPIO_SPEED						GPIO_Speed_50MHz

#define PWM_TIM_PORT								TIM3

#define PWMA  		  TIM3->CCR4    //倒立摆仅使用一路驱动 使用的A路
#define AIN1				PBout(13)
#define AIN2				PBout(12)
//#define BIN1				PBout(14)
//#define BIN2				PBout(15)

//Default Frequency = 10KHz,Timer prescaler ,Timer period
#define DEFAULT_TIMER_PRESCALER					9
#define DEFAULT_TIMER_PERIOD						499

//Default Duty
#define DEFAULT_FOREWARD_DUTY						250					//50%
#define DEFAULT_ROLLBACK_DUTY						250					//50%

//Bool 
//#define TRUE			1
//#define FALSE     0

void Motor_GPIO_Config(void);

void Motor_PWM_Config(u16 psl,u16 per);

void Motor_Default_Foreward(void);

void Motor_Default_Rollback(void);

#endif /*__MOTOR_H_*/

