#include "./led/bsp_led.h"   

void LED_GPIO_Config(void)
{		
		RCC_AHB1PeriphClockCmd(LED_Yellow_GPIO_CLK|
													 LED_Red_GPIO_CLK,ENABLE); 
	
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;
		/*选择要控制的GPIO引脚*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 ;	

		/*设置引脚模式为输出模式*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
    
    /*设置引脚的输出类型为推挽输出*/
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

		/*设置引脚速率为2MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 

		/*调用库函数，使用上面配置的GPIO_InitStructure初始化GPIO*/
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
}

