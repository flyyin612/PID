#include "show.h"

/*
*@brief:OLED液晶显示函数
*@param:None
*@retval:None
*/
void OLED_Show(void)
{

	OLED_ShowString(25,0,"PID Control");
	OLED_ShowString(0,10,"Mode:--");					//Kp,Ki,Kd三种模式
	OLED_ShowString(0,20,"Direction:--");
	
	OLED_Refresh_Gram();
}

