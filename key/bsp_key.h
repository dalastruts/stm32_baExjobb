#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "stm32f4xx.h"

#define KEY_ON 0
#define KEY_OFF 1


#define KEY1_GPIO_CLK             RCC_AHB1Periph_GPIOC
#define KEY2_GPIO_CLK             RCC_AHB1Periph_GPIOC
#define KEY3_GPIO_CLK             RCC_AHB1Periph_GPIOA
#define KEY4_GPIO_CLK             RCC_AHB1Periph_GPIOA



void KEY_GPIO_Config(void);
uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

#endif /* _BSP_KEY_H */
