#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_exti.h" 
#include "Show.h"

uint32_t time = 0; // ms ��ʱ���� 
void Delay(__IO u32 nCount); 

int main(void)
{	
	LED_GPIO_Config();	 	//LED��ʼ��
	GPIO_Tube_Config();		//�������ʾ0-9
	GPIO_TTube_Config();	//ѡ��1-4�������ʾ
	GENERAL_TIM_Init();		//��ʱ����ʼ��
	EXTI_Key_Config(); 		//������ʼ��	

	while (1)
	{
		// if ( time == 500 ) /* 1000 * 1 ms = 1s ʱ�䵽 */
		// {
		// 	time = 0;
		// 	/* LED1 ȡ�� */      
		// 	LED1_TOGGLE; 
		// }   
		Display_HELP();
	// 	// Integer_Display(1234);
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
	{

	}
}
/*********************************************END OF FILE**********************/
