/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTI
  
  AL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

#include "bsp_GeneralTim.h" 
#include "Show.h"
#include "bsp_exti.h"

extern volatile uint32_t time;
extern int key_flag;
extern  int alarm;

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}


int display_flag = 0;
void  GENERAL_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( GENERAL_TIM, TIM_IT_Update) != RESET && alarm == 1 ) 
	{	
		CLEAR1;CLEAR2;
    switch (display_flag)
    {
    case 0:
      TUBEH;TTUBE1;
      display_flag = 1;
      break;
    
    case 1:
      TUBEE;TTUBE2;
      display_flag = 2;
      break;
    
    case 2:
      TUBEL;TTUBE3;
      display_flag = 3;
      break;

    case 3:
      TUBEP;TTUBE4;
      display_flag = 0;
      break;    

    default:
      break;
    } 		 
	}			
	TIM_ClearITPendingBit(GENERAL_TIM , TIM_FLAG_Update);
}

void KEY_IRQHandler(void)
{
  //??????????????EXTI Line????
	if(EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET) 
	{		
		if(alarm == 1)
		{
			key_flag++;
			if(key_flag == 3)
			{
				alarm = 0;
			}
		}
		
    CLEAR1;CLEAR2;
    //??????????????
		EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);     
	}  
  //??????????????EXTI Line????
	if(EXTI_GetITStatus(KEY2_INT_EXTI_LINE) != RESET) 
	{	
		if(alarm == 1)
		{
			key_flag++;
			if(key_flag == 3)
			{
				alarm = 0;
			}
		}
    CLEAR1;CLEAR2;
    //??????????????
		EXTI_ClearITPendingBit(KEY2_INT_EXTI_LINE);     
	}  
      //??????????????EXTI Line????
	if(EXTI_GetITStatus(KEY3_INT_EXTI_LINE) != RESET) 
	{	
    alarm = 1;
    //??????????????
		EXTI_ClearITPendingBit(KEY3_INT_EXTI_LINE);     
	}  
  //??????????????EXTI Line????
	if(EXTI_GetITStatus(KEY4_INT_EXTI_LINE) != RESET) 
	{		
    alarm = 1;
    //??????????????
		EXTI_ClearITPendingBit(KEY4_INT_EXTI_LINE);     
	}  
}


/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
