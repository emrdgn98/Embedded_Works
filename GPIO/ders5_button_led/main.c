#include "stm32f10x.h"                  // Device header

void gpioConfig(){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0 |GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;

	
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	



}
uint16_t counter=0;
	uint16_t buttonstate=0;
void delay(uint32_t time){
	
	while(time--);


}
int main(){
	
	
	gpioConfig();
	while(1){
		buttonstate=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		if(buttonstate==1){
			
			counter++;
			delay(3600000);
			
			if(counter%3==1){
			
			GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		  GPIO_SetBits(GPIOB,GPIO_Pin_1|GPIO_Pin_2);
			
		}
		  else if(counter%3==2){
			
			GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1);
		  GPIO_SetBits(GPIOB,GPIO_Pin_2);
			
		}
			else if(counter%3==0){
			
			GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);

			
		}
			
		else{
				  GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
				  
			}
		}
		
	
			
	
	
	}






}

