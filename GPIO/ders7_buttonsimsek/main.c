#include "stm32f10x.h"                  // Device header

uint32_t buttonstate=0;
void gpioConfig(){
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	
	





}
void delay(uint32_t time){

while(time--);
}

int main(){
	
	gpioConfig();
	int ledarray[3]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2};

	while(1){
			buttonstate=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
	if(buttonstate==1){
		
		
		for(int i=0;i<3;i++)
		{
		GPIO_SetBits(GPIOB,ledarray[i]);
		delay(360000);
		GPIO_ResetBits(GPIOB,ledarray[i]);
		delay(360000);
		
		}
		

		for(int i=1;i>0;i--){
		
		GPIO_SetBits(GPIOB,ledarray[i]);
		delay(360000);
		GPIO_ResetBits(GPIOB,ledarray[i]);
		delay(360000);
		
		
		}
	
	}else{
		for(int i=0;i<3;i++)
		{
		
	  GPIO_SetBits(GPIOB,ledarray[i]);
		delay(3600000);
		GPIO_ResetBits(GPIOB,ledarray[i]);
		delay(3600000);
		
		}
		

		for(int i=1;i>0;i--){
		
		GPIO_SetBits(GPIOB,ledarray[i]);
		delay(3600000);
		GPIO_ResetBits(GPIOB,ledarray[i]);
		delay(3600000);
		
		
		}
	
	}
		
	
	}




}
