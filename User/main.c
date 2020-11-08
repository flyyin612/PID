/***********************************************************************************
*@Copyright (C):yxb
*@Author	     :yxb
*@Version      :V1.0
*@Date         :2019-08-10
*@E-mail       :xiaobing_yin@163.com
*@Attention    :Copyright ownership, violators must be investigated. Please indicate 
*               the source for reprinting. For business, please contact the author by 
*               e-mail
************************************************************************************                                                                                
*                                   _oo8oo_                                
*                                  o8888888o                               
*                                  88" . "88                               
*                                  (| -_- |)                               
*                                  0\  =  /0                               
*                                ___/'==='\___                             
*                              .' \\|     |// '.                           
*                             / \\|||  :  |||// \                          
*                            / _||||| -:- |||||_ \                         
*                           |   | \\\  -  /// |   |                        
*                           | \_|  ''\---/''  |_/ |                        
*                           \  .-\__  '-'  __/-.  /                        
*                         ___'. .'  /--.--\  '. .'___                      
*                      ."" '<  '.___\_<|>_/___.'  >' "".                   
*                     | | :  `- \`.:`\ _ /`:.`/ -`  : | |                  
*                     \  \ `-.   \_ __\ /__ _/   .-` /  /                  
*                 =====`-.____`.___ \_____/ ___.`____.-`=====              
*                                   `=---=`  
*
*					              ������¥                  BUG����                              
*
* **********************************************************************************
*                   ��Ի:
*                       д��¥��д�ּ䣬д�ּ������Ա��
*                       ������Աд�������ó��򻻾�Ǯ��
*                       ����ֻ���������������������ߣ�
*                       ��������ո��գ����������긴�ꡣ
*                       ��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
*                       ���۱������Ȥ���������г���Ա��
*                       ����Ц��߯��񲣬��Ц�Լ���̫����
*                       ��������Ư���ã��ĸ���ó���Ա��
*************************************************************************************/
#include "stm32f10x.h"
#include "sys.h"

extern uint8_t Switch_Timer_Base_1ms;
extern uint8_t Update_OLED_Timer_Base_1ms;
extern uint8_t Motor_Timer_Base_1ms;
extern uint8_t Encoder_Timer_Base_1ms;

int main(void)
{
	System_Init();
	
	OLED_Show();
	
	TIM_SetCompare4(PWM_TIM_PORT, DEFAULT_FOREWARD_DUTY);					
	
	while(1)
	{
		if(Switch_Timer_Base_1ms > 19)				//20msˢ��һ�ΰ���״̬
		{
			Switch_Timer_Base_1ms = 0;
			Key_Check();
		}
		if(Update_OLED_Timer_Base_1ms > 29)				//30msˢ��һ��Һ��״̬
		{
			Update_OLED_Timer_Base_1ms = 0;
			Motor_Run_Direction();
			Work_Mode();
		}
		if(Motor_Timer_Base_1ms > 39)		//40msˢ��һ�ε������״̬
		{
			Motor_Timer_Base_1ms = 0;
			Control_Motor();
		}
		
		if(Encoder_Timer_Base_1ms > 49)		
		{
			Encoder_Timer_Base_1ms = 0;
			Read_Encoder();
		}

	}
}

