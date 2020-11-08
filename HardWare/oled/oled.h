#ifndef __OLED_H_
#define __OLED_H_

#include "stm32f10x.h"
#include "sys.h"

//#define OLED_RST_Clr() GPIO_ResetBits(GPIOB,GPIO_Pin_3)   //RST
//#define OLED_RST_Set() GPIO_SetBits(GPIOB,GPIO_Pin_3)   //RST

//#define OLED_RS_Clr() GPIO_ResetBits(GPIOA,GPIO_Pin_15)    //DC
//#define OLED_RS_Set() GPIO_SetBits(GPIOA,GPIO_Pin_15)    //DC

//#define OLED_SCLK_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_5)  //SCL
//#define OLED_SCLK_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_5)   //SCL

//#define OLED_SDIN_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_4)  //SDA
//#define OLED_SDIN_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_4)   //SDA

#define OLED_RST_Clr() PBout(3)=0   //RST
#define OLED_RST_Set() PBout(3)=1   //RST

#define OLED_RS_Clr() PAout(15)=0    //DC
#define OLED_RS_Set() PAout(15)=1    //DC

#define OLED_SCLK_Clr()  PBout(5)=0  //SCL
#define OLED_SCLK_Set()  PBout(5)=1   //SCL

#define OLED_SDIN_Clr()  PBout(4)=0   //SDA
#define OLED_SDIN_Set()  PBout(4)=1   //SDA


#define OLED_CMD  0	//Ð´ÃüÁî
#define OLED_DATA 1	//Ð´Êý¾Ý

void delay(int i);
void OLED_Refresh_Gram(void);
void OLED_WR_Byte(u8 dat,u8 cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
u32 oled_pow(u8 m,u8 n);
void OLED_ShowNumber(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p);
void OLED_Init(void);

#endif
 

