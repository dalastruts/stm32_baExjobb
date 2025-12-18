#include "bsp_key.h"

void KEY_GPIO_Config(void)
{		
		RCC_AHB1PeriphClockCmd(KEY1_GPIO_CLK|
												   KEY2_GPIO_CLK|
													 KEY3_GPIO_CLK|
													 KEY4_GPIO_CLK,ENABLE); 
	
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;
		/*选择要控制的GPIO引脚*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;	

		/*设置引脚模式为输出模式*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;   

			GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
		/*调用库函数，使用上面配置的GPIO_InitStructure初始化GPIO*/
		  GPIO_Init(GPIOC, &GPIO_InitStructure);	
			
		 /****KEY2****/
		  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;	
			GPIO_Init(GPIOC, &GPIO_InitStructure);
			
		/****KEY3****/
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	
			GPIO_Init(GPIOA, &GPIO_InitStructure);
			
		/****KEY4****/	
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	
			GPIO_Init(GPIOA, &GPIO_InitStructure);
			
    
}

uint8_t KEY_Scan(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
		{
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);//按下是1，程序一直停留在该语句，直到松开
			return KEY_ON;
		}
		else return KEY_OFF;
}
