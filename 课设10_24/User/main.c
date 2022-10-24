#include "stm32f10x.h"
#include "bsp_led.h"
#include "Show.h"

void Delay(__IO u32 nCount); 

int main(void)
{	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	 
	GPIO_Tube_Config();
	GPIO_TTube_Config();
	GENERAL_TIM_Init();
	

	// Display();
	
	
	while (1)
	{
		Integer_Display(1234);
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
