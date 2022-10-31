#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_exti.h" 
#include "Show.h"

uint32_t time = 0; // ms ��ʱ���� 
int key_flag = 0;
int alarm = 0;
void Delay(__IO u32 nCount); 

int main(void)
{	
	LED_GPIO_Config();	 	//LED��ʼ��
	GPIO_Tube_Config();		//�������ʾ0-9
	GPIO_TTube_Config();	//ѡ��1-4�������ʾ
	GENERAL_TIM_Init();		//��ʱ����ʼ��
	EXTI_Key_Config(); 		//������ʼ��	
	BEEP_GPIO_Config();		/* BEEP GPIO ��ʼ�� */

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

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
	{

	}
}
/*********************************************END OF FILE**********************/
