#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_motor.h"
#include "bsp_key.h"
#include "bsp_beep.h"
#include "bsp_flash.h"

#define FLASH_ADR 0x08008000//最后一页的起始地址
int port_1 = 0; 
int port_2 = 0;
extern  unsigned int data_run;


int open_flag = 0;
int close_flag = 0;

int data_btn = 0; //KEY3按下后自增

int data_check = 0;  //暂存data_test中的数据

void Delay(__IO uint32_t nCount)	 //简单的延时函数
{
	for(; nCount != 0; nCount--);
}


int main(void)
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
  MOTOR_GPIO_Config();
	EXTI_HLP_Config();
  BEEP_GPIO_Config();

	//读
	
	data_check = (*(__IO uint32_t*)0x08008000); 
	
if (data_check==2000)
{
   BEEP_AN();

}
//data_check  =	 *(__IO uint32_t*)0x08008000;   //读FLASH中的数据，直接给出地址就行了。跟从内存中读数据一样。0x08008000;//读一个字
//	
////data_check  =	uint16_t FLASH_ReadHalfWord(0x08008000);
//	
////	data_check = FLASH_ReadHalfWord(addr) ; //data_test的值写入flash的指定地址，赋值给data_check

	while(1)                            
	{
					if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0)
							 {
								 BEEP_AN();
								 
								 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0)
									{
										data_btn++;
										
										FLASH_Unlock(); //解锁
										
										FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
                    FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);
										//清除标志位 - 忙标志位|操作结束标志位|编写错误标志位|页面写保护错误标志位
										
										FLASH_EraseSector(FLASH_Sector_2,VoltageRange_3);
										//FLASH_ErasePage(FLASH_ADR); //擦除页 
										FLASH_ProgramWord(FLASH_ADR,5000);//写数据 起始地址，数据
										
										FLASH_Lock(); 
//										
//									//----写
//										FLASH_Unlock();
//									  FLASH_ProgramHalfWord(0x08008000,2000);
//										FLASH_Lock();
//										
//									//-------	
//										
										while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0); 
									}
								}
							 
						
					if(data_run > 2000)
					{
						port_1 = 0;
						port_2 = 0;
						data_run =0;
						BEEP_AN();
						BEEP_OFF;
						Delay(240000);//100ms
						BEEP_AN();
						
					}
		/*****KEY1 -- OPEN*****/
					if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)==0)
			   {
					 BEEP_AN();
					 
					 if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)==0)
			      {
					    data_run ++ ;
						 if(port_1 == 0 && port_2 == 0)
					   {
							port_1 = 1;
						  port_2 = 0;
						 } 
						 else 
						 {
						  port_1 = 0;
							port_2 = 0;
						 }	
							while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)==0); 
						}
					}
		/*****KEY2 -- CLOSE*****/
					
					if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)==0)
			   {
					   BEEP_AN();
					 if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)==0)
			      {
							
						
						 if(port_2 == 0&& port_1 == 0)
						 {
							port_2 = 1;
							port_1 = 0;
						 } 
						 else 
						 {
						 port_2 = 0;	
						 port_1 = 0;
						 }
						 
						 	if(data_run >0)
							{ 
					
								data_run --;
							}
							else
							{
								port_1 = 0;
								port_2 = 0;
								data_run = 0;
								BEEP_OK();
							}
							
							while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)==0); 
						}
					}
		/*** port_1 = 1  port_2 = 0  红灯，关窗，电机反转
				 port_1 = 0  port_2 = 1  绿灯，开窗，电机正转
				 都为0或1的时候电机停转
		***/
				if(port_2 == 0&&port_1 == 1)
					{
						LED_Red_ON;
						MOTOR1_OFF;
						MOTOR2_ON;
					}
				else if(port_2 == 1&& port_1 == 0)
					{
						LED_Yellow_ON;
						MOTOR2_OFF;
						MOTOR1_ON;
					}		
				else{
					LED_Red_OFF;
					LED_Yellow_OFF;
					MOTOR1_OFF;
					MOTOR2_OFF;
					
				}
		
		}

}

