#ifndef __LED_H
#define	__LED_H

#include "stm32f4xx.h"

#define ON  0
#define OFF 1

#define LED_Yellow_GPIO_CLK          RCC_AHB1Periph_GPIOA
#define LED_Red_GPIO_CLK             RCC_AHB1Periph_GPIOA

#define LED_Yellow(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_3);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_3)
					
#define LED_Red(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_2);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_2)

/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)			 {p->BSRRL=i;}		//设置为高电平
#define digitalLo(p,i)			 {p->BSRRH=i;}		//输出低电平
#define digitalToggle(p,i)	 {p->ODR ^=i;}		//输出反转状态

/* 定义控制IO的宏 */
#define LED_Yellow_TOGGLE		digitalToggle(GPIOA,GPIO_Pin_3)
#define LED_Yellow_OFF			digitalHi(GPIOA,GPIO_Pin_3)
#define LED_Yellow_ON				digitalLo(GPIOA,GPIO_Pin_3)

#define LED_Red_TOGGLE		digitalToggle(GPIOA,GPIO_Pin_2)
#define LED_Red_OFF			digitalHi(GPIOA,GPIO_Pin_2)
#define LED_Red_ON				digitalLo(GPIOA,GPIO_Pin_2)

void LED_GPIO_Config(void);

#endif /* __LED_H */
