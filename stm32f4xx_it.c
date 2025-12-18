#include "stm32f4xx_it.h"
#include "./led/bsp_led.h"
#include "./tim/bsp_advance_tim.h"

unsigned char tim_flag = 0;
int count = 0;

void  ADVANCE_TIM_IRQHandler (void)
{
		count++;
	if(count == 20)
	{
		count = 0;
		if(tim_flag == 0)
		{
			tim_flag = 1;
		}
		else
		{
			tim_flag = 0;
		}
	}
	TIM_ClearITPendingBit(ADVANCE_TIM , TIM_IT_Update);
}


void EXTI15_10_IRQHandler(void)
{	
	 if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)==0)
		{
			count++;
			while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)==0); 
		}
		if(count == 5)
		{
	   	LED_Red_TOGGLE;	
		}			
  
   //清除中断标志位
		EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE);     
}

