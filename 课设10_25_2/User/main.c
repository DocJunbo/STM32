#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_exti.h" 
#include "Show.h"

uint32_t time = 0; // ms 计时变量 
void Delay(__IO u32 nCount); 

int main(void)
{	
	LED_GPIO_Config();	 	//LED初始化
	GPIO_Tube_Config();		//数码管显示0-9
	GPIO_TTube_Config();	//选择1-4数码管显示
	GENERAL_TIM_Init();		//定时器初始化
	EXTI_Key_Config(); 		//按键初始化	

	while (1)
	{
		// if ( time == 500 ) /* 1000 * 1 ms = 1s 时间到 */
		// {
		// 	time = 0;
		// 	/* LED1 取反 */      
		// 	LED1_TOGGLE; 
		// }   
		Display_HELP();
	// 	// Integer_Display(1234);
	}
}

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
	{

	}
}
/*********************************************END OF FILE**********************/
