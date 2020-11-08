#include "encoder.h"
#include "stdio.h"

uint8_t Encoder_Timer_Base_1ms = 0;				//������ʱ��

/*
*@brief:������GPIO���� 
*@param:None
*@retval:None
*/
void Encoder_GPIO_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(ENCODER_RCC_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = ENCODER_PIN_A | ENCODER_PIN_B;
	GPIO_InitStructure.GPIO_Mode = ENCODER_MODE;
//	GPIO_InitStructure.GPIO_Speed = ENCODER_SPEED;
	GPIO_Init(ENCODER_PORT,&GPIO_InitStructure);
}

/*
*@brief:�趨TIM2Ϊ�������ӿ�
*@param:None
*@retval:None
*/
void Encoder_TIM2_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;  
  TIM_ICInitTypeDef TIM_ICInitStructure;  
	
	Encoder_GPIO_Init();
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//ʹ�ܶ�ʱ��2��ʱ��
	
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0; // Ԥ��Ƶ�� 
  TIM_TimeBaseStructure.TIM_Period = ENCODER_TIM_PERIOD; //�趨�������Զ���װֵ
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//ѡ��ʱ�ӷ�Ƶ������Ƶ
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;////TIM���ϼ���  
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
  TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);//ʹ�ñ�����ģʽ3
  TIM_ICStructInit(&TIM_ICInitStructure);
  TIM_ICInitStructure.TIM_ICFilter = 10;
  TIM_ICInit(TIM2, &TIM_ICInitStructure);
  TIM_ClearFlag(TIM2, TIM_FLAG_Update);//���TIM�ĸ��±�־λ
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  //Reset counter
  TIM_SetCounter(TIM2,0);
  TIM_Cmd(TIM2, ENABLE); 
}

/*
*@brief:��λʱ���ȡ����������
*@param:
*@retval:None
*/
int Read_Encoder(void)
{
	int encoder_tim;
	char buf[]={0};
	
	encoder_tim=(short)TIM2->CNT;
	TIM2->CNT = 0;
	
	printf("%d\r\n",encoder_tim);
	
	sprintf(buf,"%d  ",encoder_tim);
	OLED_ShowString(50,30,buf);
	OLED_Refresh_Gram();
	
	return encoder_tim;
}

