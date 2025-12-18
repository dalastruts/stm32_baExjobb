#ifndef __EXTI_H
#define	__EXTI_H

#include "stm32f4xx.h"

//引脚定义
/*******************************************************/
#define KEY1_INT_GPIO_PORT                GPIOC
#define KEY1_INT_GPIO_CLK                 RCC_AHB1Periph_GPIOC
#define KEY1_INT_GPIO_PIN                 GPIO_Pin_14
#define KEY1_INT_EXTI_PORTSOURCE          EXTI_PortSourceGPIOC
#define KEY1_INT_EXTI_PINSOURCE           EXTI_PinSource14 // original - 0
#define KEY1_INT_EXTI_LINE                EXTI_Line14// original - 0
#define KEY1_INT_EXTI_IRQ                 EXTI15_10_IRQn // original - EXTI0_IRQn
#define KEY1_IRQHandler                   EXTI15_10_IRQHandler // original - EXTI0_IRQHandler


/*******************************************************/


void EXTI_Key_Config(void);

#endif /* __EXTI_H */
