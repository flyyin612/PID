#include "work.h"

uint8_t Update_OLED_Timer_Base_1ms = 0;					//ˢ��Һ��״̬ʱ��
uint8_t Motor_Timer_Base_1ms = 0;								//ˢ�µ��״̬ʱ��
uint16_t Motor_Duty_Add = 250;									//���ռ�ձ�  ����
uint16_t Motor_Duty_Cut = 250;									//���ռ�ձ� ����

extern u8 user_state,k1_state,k2_state,k3_state,k4_state;
static u8 user_press=0;

/*
*@brief:����ģʽѡ���û�������һ�Σ�ģʽ�л�һ��
*@param:None
*@retval:None
*/
void Work_Mode(void)
{
	if(user_state==1)
	{
		user_state=0;
		user_press++;
	}
	if(user_press==1)
	{
		OLED_ShowString(40,10,"Kp");
		OLED_Refresh_Gram();		
	}
	else if(user_press==2)
	{
		OLED_ShowString(40,10,"Ki");
		OLED_Refresh_Gram();	
	}
	else if(user_press==3)
	{
		user_press=0;
		OLED_ShowString(40,10,"Kd");
		OLED_Refresh_Gram();	
	}
}

/*
*@brief:������з���ѡ�񣬰���k1(x)����ת������k2(M)��ת
*@param:None
*@retval:None
*/
void Motor_Run_Direction(void)
{
	if(k1_state==1)													//ˢ��Һ����ʾmotor mode
	{
		OLED_ShowString(80,20,"Left ");
		OLED_Refresh_Gram();
											
	}
	else if(k2_state==1)										//ˢ��Һ����ʾmotor mode
	{
		OLED_ShowString(80,20,"Right");
		OLED_Refresh_Gram();
	}
}

/*
*@brief:�������
*@param:None
*@retval:None
*/
void Control_Motor(void)
{
	if(k1_state == 1)								//motor��ת
	{
		k1_state = 0;
		Motor_Default_Foreward();		
	}
	else if(k2_state == 1)					//motor��ת
	{
		k2_state = 0;
		Motor_Default_Rollback();
	}
	
	if(k3_state == 1)								//����Duty��Duty Increase
	{
		k3_state = 0;
		
		Motor_Duty_Add += 10;
		
		TIM_SetCompare4(PWM_TIM_PORT, Motor_Duty_Add);					
	}
	
	if(k4_state == 1)								//����Duty��Duty Increase
	{
		k4_state = 0;
		
		Motor_Duty_Cut -= 10;
		
		TIM_SetCompare4(PWM_TIM_PORT, Motor_Duty_Cut);					
	}
}

