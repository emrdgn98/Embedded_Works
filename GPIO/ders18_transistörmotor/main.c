#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO

uint16_t buttonstate=0;
uint16_t flag=0;
void gpioConfig(){
	
	GPIO_InitTypeDef GpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GpioInitStructure);
	
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_6;
	
	GPIO_Init(GPIOC,&GpioInitStructure);
	






}

void delay(uint32_t time){
	
	while(time--);



}



int main()
{
	gpioConfig();
	while(1){
		
		buttonstate=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)!=0);
		if(buttonstate==1){
			
			if(flag==0){
			
			flag=1;
			GPIO_SetBits(GPIOB,GPIO_Pin_0);
			GPIO_SetBits(GPIOB,GPIO_Pin_1);
			GPIO_ResetBits(GPIOB,GPIO_Pin_2);
			

			
			}
			
		
		
		
	
		
		else {
			
			flag=0;
			GPIO_ResetBits(GPIOB,GPIO_Pin_0);
			GPIO_ResetBits(GPIOB,GPIO_Pin_1);
			GPIO_SetBits(GPIOB,GPIO_Pin_2);
			
		
		
		
		}	
		
		
		}
	}
		
		
	
	
	
	
	





}
