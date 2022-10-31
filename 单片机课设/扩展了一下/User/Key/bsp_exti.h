#ifndef __EXTI_H
#define	__EXTI_H


#include "stm32f10x.h"

#define KEY_IRQHandler            EXTI15_10_IRQHandler

#define KEY1_INT_GPIO_PORT         GPIOB
#define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)
#define KEY1_INT_GPIO_PIN          GPIO_Pin_12
#define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB
#define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource12
#define KEY1_INT_EXTI_LINE         EXTI_Line12
#define KEY1_INT_EXTI_IRQ          EXTI15_10_IRQn

#define KEY2_INT_GPIO_PORT         GPIOB
#define KEY2_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)
#define KEY2_INT_GPIO_PIN          GPIO_Pin_13
#define KEY2_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB
#define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource13
#define KEY2_INT_EXTI_LINE         EXTI_Line13
#define KEY2_INT_EXTI_IRQ          EXTI15_10_IRQn

#define KEY3_INT_GPIO_PORT         GPIOB
#define KEY3_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)
#define KEY3_INT_GPIO_PIN          GPIO_Pin_14
#define KEY3_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB
#define KEY3_INT_EXTI_PINSOURCE    GPIO_PinSource14
#define KEY3_INT_EXTI_LINE         EXTI_Line14
#define KEY3_INT_EXTI_IRQ          EXTI15_10_IRQn

#define KEY4_INT_GPIO_PORT         GPIOB
#define KEY4_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)
#define KEY4_INT_GPIO_PIN          GPIO_Pin_15
#define KEY4_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB
#define KEY4_INT_EXTI_PINSOURCE    GPIO_PinSource15
#define KEY4_INT_EXTI_LINE         EXTI_Line15
#define KEY4_INT_EXTI_IRQ          EXTI15_10_IRQn


// #define KEY2_INT_GPIO_PORT         GPIOC
// #define KEY2_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
// #define KEY2_INT_GPIO_PIN          GPIO_Pin_1
// #define KEY2_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
// #define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource1
// #define KEY2_INT_EXTI_LINE         EXTI_Line1
// #define KEY2_INT_EXTI_ IRQ          EXTI1_IRQn

// #define KEY2_IRQHandler            EXTI1_IRQHandler

void EXTI_Key_Config(void);


#endif /* __EXTI_H */
