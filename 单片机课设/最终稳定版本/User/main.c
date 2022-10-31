/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   测试led
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "Show.h"
#include "bsp_exti.h"
#include "bsp_GeneralTim.h"

uint32_t time = 0; // ms 计时变量 
int key_flag = 0;
int alarm = 0;

/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	
	/* LED 端口初始化 */
	LED_GPIO_Config();	 
	GPIO_Tube_Config();		//数码管显示0-9
	GPIO_TTube_Config();	//选择1-4数码管显示
	GENERAL_TIM_Init();		//定时器初始化
	EXTI_Key_Config(); 		//按键初始化	

	while (1)
	{
		if(alarm)
		{
			LED1(ON);
			SOFT_DELAY;
			LED1(OFF);
			LED2(ON);
			SOFT_DELAY;
			LED2(OFF);
		}
		else
		{
			LED1(OFF);
			LED2(OFF);
			key_flag = 0;
			Display_SAFE();
		}
		
	}
}
/*********************************************END OF FILE**********************/
