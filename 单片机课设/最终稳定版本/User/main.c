/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
	
#include "stm32f10x.h"
#include "bsp_led.h"
#include "Show.h"
#include "bsp_exti.h"
#include "bsp_GeneralTim.h"

uint32_t time = 0; // ms ��ʱ���� 
int key_flag = 0;
int alarm = 0;

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	 
	GPIO_Tube_Config();		//�������ʾ0-9
	GPIO_TTube_Config();	//ѡ��1-4�������ʾ
	GENERAL_TIM_Init();		//��ʱ����ʼ��
	EXTI_Key_Config(); 		//������ʼ��	

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
