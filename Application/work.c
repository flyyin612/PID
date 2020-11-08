#include "work.h"

uint8_t Update_OLED_Timer_Base_1ms = 0;					//刷新液晶状态时基
uint8_t Motor_Timer_Base_1ms = 0;								//刷新电机状态时基
uint16_t Motor_Duty_Add = 250;									//电机占空比  增加
uint16_t Motor_Duty_Cut = 250;									//电机占空比 减少

extern u8 user_state,k1_state,k2_state,k3_state,k4_state;
static u8 user_press=0;

/*
*@brief:工作模式选择，用户键单击一次，模式切换一次
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
*@brief:电机运行方向选择，按下k1(x)，右转。按下k2(M)左转
*@param:None
*@retval:None
*/
void Motor_Run_Direction(void)
{
	if(k1_state==1)													//刷新液晶显示motor mode
	{
		OLED_ShowString(80,20,"Left ");
		OLED_Refresh_Gram();
											
	}
	else if(k2_state==1)										//刷新液晶显示motor mode
	{
		OLED_ShowString(80,20,"Right");
		OLED_Refresh_Gram();
	}
}

/*
*@brief:电机控制
*@param:None
*@retval:None
*/
void Control_Motor(void)
{
	if(k1_state == 1)								//motor正转
	{
		k1_state = 0;
		Motor_Default_Foreward();		
	}
	else if(k2_state == 1)					//motor反转
	{
		k2_state = 0;
		Motor_Default_Rollback();
	}
	
	if(k3_state == 1)								//调节Duty，Duty Increase
	{
		k3_state = 0;
		
		Motor_Duty_Add += 10;
		
		TIM_SetCompare4(PWM_TIM_PORT, Motor_Duty_Add);					
	}
	
	if(k4_state == 1)								//调节Duty，Duty Increase
	{
		k4_state = 0;
		
		Motor_Duty_Cut -= 10;
		
		TIM_SetCompare4(PWM_TIM_PORT, Motor_Duty_Cut);					
	}
}

