#ifndef __ENCODER_H_
#define __ENCODER_H_

#include "sys.h"

#define ENCODER_PORT	GPIOA
#define ENCODER_RCC_CLK		RCC_APB2Periph_GPIOA
#define ENCODER_PIN_A			GPIO_Pin_0
#define ENCODER_PIN_B			GPIO_Pin_1
//#define ENCODER_MODE			GPIO_Mode_Out_PP
#define ENCODER_MODE			GPIO_Mode_IN_FLOATING
#define ENCODER_SPEED			GPIO_Speed_50MHz

#define ENCODER_TIM_PERIOD (u16)(65535)   //不可大于65535 因为F103的定时器是16位的。

void Encoder_GPIO_Init(void);

void Encoder_TIM2_Init(void);

int Read_Encoder(void);

#endif /* __ENCODER_H_ */

