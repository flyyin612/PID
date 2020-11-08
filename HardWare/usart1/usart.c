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
#include "usart.h"
	
	/*
	*USARTx	GPIO配置，工作模式配置。15200 8-N-1
	*/
void USART1_Config(u32 nBaudRate)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	USART_InitTypeDef	USART_InitStructure;
	
	//配置时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	
	//USART GPIO CONFIG
	//配置发送端
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//配置接收端
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//USART1 MODE CONFIG
	USART_InitStructure.USART_BaudRate=nBaudRate;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure);
	
	USART_Cmd(USART1,ENABLE);
}

/*
*重定向库函数printf到USART1
*/
int fputc(int ch,FILE *f)
{
	//发送一个字节到USART1
	USART_SendData(USART1,(uint8_t) ch);
	
	//等待发送完毕
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	
	return (ch);
}

/*
*重定向库函数scanf到USART1
*/
int fgetc(FILE *f)
{
	//等待串口1输入数据
	while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);
	
	return (int)USART_ReceiveData(USART1);
}

