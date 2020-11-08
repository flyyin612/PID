/*****************************************************************************
*@file:key.c
*@brief:PID学习之key.c文件
*@author:小兵
*@version:V1.0
*@date:2018.01.26
*******************************************************************************/
#include "key.h"

u8 user_state,k1_state,k2_state,k3_state,k4_state;
uint8_t Switch_Timer_Base_1ms = 0;				//按键检测时基

/*
*@Description:key按键GPIO初始化配置
*@param:None
*@return:None
*/
void Key_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(KEY_RCC_PORT,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = KEY_PIN | KEY1_PIN | KEY2_PIN | KEY3_PIN | KEY4_PIN;
	GPIO_InitStructure.GPIO_Mode = KEY_MODE;
	GPIO_Init(KEY_PORT,&GPIO_InitStructure);
}

/*
*@Description:key检测，20ms的检测周期
*@param:None
*@return:None
*/
void Key_Check(void)
{
	static u8 user_key[4]={1};
	static u8 k1_buf[4]={1};
	static u8 k2_buf[4]={1};
	static u8 k3_buf[4]={1};
	static u8 k4_buf[4]={1};
	
	//user key
	user_key[3] = user_key[2];
	user_key[2] = user_key[1];
	user_key[1] = user_key[0]; 
	user_key[0] = KEY_VALUE;
	
	if((user_key[0]==SET)&&(user_key[1]+user_key[2])==RESET)	//短按
	{
		user_state=1;
	}
	if((user_key[0]+user_key[1]+user_key[2])==RESET)				//长按
	{
		user_state=2;
	}
	
	//key1 
	k1_buf[3] = k1_buf[2];
	k1_buf[2] = k1_buf[1];
	k1_buf[1] = k1_buf[0]; 
	k1_buf[0] = KEY1_VALUE;
	
	if((k1_buf[0]==SET)&&(k1_buf[1]+k1_buf[2])==RESET)	  //短按
	{
		k1_state=1;
	}
	if((k1_buf[0]+k1_buf[1]+k1_buf[2])==RESET)				   //长按
	{
		k1_state=2;
	}
	
	//key2 
	k2_buf[3] = k2_buf[2];
	k2_buf[2] = k2_buf[1];
	k2_buf[1] = k2_buf[0]; 
	k2_buf[0] = KEY2_VALUE;
	
	if((k2_buf[0]==SET)&&(k2_buf[1]+k2_buf[2])==RESET)	//短按
	{
		k2_state=1;
	}
	if((k2_buf[0]+k2_buf[1]+k2_buf[2])==RESET)			  	//长按
	{
		k2_state=2;
	}
	
	//key3
	k3_buf[3] = k3_buf[2];
	k3_buf[2] = k3_buf[1];
	k3_buf[1] = k3_buf[0]; 
	k3_buf[0] = KEY3_VALUE;
	
	if((k3_buf[0]==RESET)&&(k3_buf[1])==SET)						//短按
	{
		k3_state=1;
	}
	if((k3_buf[0]+k3_buf[1]+k3_buf[2])==RESET)			  	//长按
	{
		k3_state=2;
	}
	
	//key4
	k4_buf[3] = k4_buf[2];
	k4_buf[2] = k4_buf[1];
	k4_buf[1] = k4_buf[0]; 
	k4_buf[0] = KEY4_VALUE;
	
	if((k4_buf[0]==RESET)&&(k4_buf[1])==SET)				  		//短按
	{
		k4_state=1;
	}
	if((k4_buf[0]+k4_buf[1]+k4_buf[2])==RESET)			  	//长按
	{
		k4_state=2;
	}
}
