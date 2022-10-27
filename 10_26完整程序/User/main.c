#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_exti.h" 
#include "Show.h"

uint32_t time = 0; // ms 计时变量 
int key_flag = 0;
int alarm = 0;
void Delay(__IO u32 nCount); 

int main(void)
{	
	LED_GPIO_Config();	 	//LED初始化
	GPIO_Tube_Config();		//数码管显示0-9
	GPIO_TTube_Config();	//选择1-4数码管显示
	GENERAL_TIM_Init();		//定时器初始化
	EXTI_Key_Config(); 		//按键初始化	
	BEEP_GPIO_Config();		/* BEEP GPIO 初始化 */

	while (1)
	{
		if (alarm == 1)
		{
			LED1(ON);
			SOFT_DELAY;
			LED1(OFF);
			BEEP(ON);
			SOFT_DELAY;
			BEEP(OFF);
		}
		else
			LED1(OFF);
			BEEP(OFF);
		// key_flag = 1;
	 	// if(key_flag) 
		// {
		// 	Display_HELP();
		// }
	}
}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
	{

	}
}
/*********************************************END OF FILE**********************/
