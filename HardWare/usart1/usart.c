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
#include "usart.h"
	
	/*
	*USARTx	GPIO���ã�����ģʽ���á�15200 8-N-1
	*/
void USART1_Config(u32 nBaudRate)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	USART_InitTypeDef	USART_InitStructure;
	
	//����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	
	//USART GPIO CONFIG
	//���÷��Ͷ�
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//���ý��ն�
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
*�ض���⺯��printf��USART1
*/
int fputc(int ch,FILE *f)
{
	//����һ���ֽڵ�USART1
	USART_SendData(USART1,(uint8_t) ch);
	
	//�ȴ��������
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	
	return (ch);
}

/*
*�ض���⺯��scanf��USART1
*/
int fgetc(FILE *f)
{
	//�ȴ�����1��������
	while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);
	
	return (int)USART_ReceiveData(USART1);
}

