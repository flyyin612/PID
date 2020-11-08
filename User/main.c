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
*					              佛祖镇楼                  BUG辟易                              
*
* **********************************************************************************
*                   佛曰:
*                       写字楼里写字间，写字间里程序员；
*                       程序人员写程序，又拿程序换酒钱。
*                       酒醒只在网上坐，酒醉还来网下眠；
*                       酒醉酒醒日复日，网上网下年复年。
*                       但愿老死电脑间，不愿鞠躬老板前；
*                       奔驰宝马贵者趣，公交自行程序员。
*                       别人笑我忒疯癫，我笑自己命太贱；
*                       不见满街漂亮妹，哪个归得程序员？
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
		if(Switch_Timer_Base_1ms > 19)				//20ms刷新一次按键状态
		{
			Switch_Timer_Base_1ms = 0;
			Key_Check();
		}
		if(Update_OLED_Timer_Base_1ms > 29)				//30ms刷新一次液晶状态
		{
			Update_OLED_Timer_Base_1ms = 0;
			Motor_Run_Direction();
			Work_Mode();
		}
		if(Motor_Timer_Base_1ms > 39)		//40ms刷新一次电机运行状态
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

