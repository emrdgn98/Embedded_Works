#include "stm32f10x.h"                  // Device header
void gpioConfig(){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//for led
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//for button
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);






}





int main(){
	
	gpioConfig();
	int buttonstate=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6);
	
	while(1){
		if(buttonstate==1){
			
			GPIO_SetBits(GPIOB,GPIO_Pin_0);
			
		
			
			
			
		
		}
		else{
			
       GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		
		
		
		
		
		}
		
	
	
	
	
	
	}






}

