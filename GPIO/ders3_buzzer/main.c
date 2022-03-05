#include "stm32f10x.h"                  // Device header
void gpioConfig(){

GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	


}


int main(){
gpioConfig();
while(1){
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	for(int i=1;i<720000;i++);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	for(int i=1;i<360000;i++);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	for(int i=1;i<180000;i++);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	for(int i=1;i<360000;i++);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	for(int i=1;i<1080000;i++);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	for(int i=1;i<90000;i++);
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	for(int i=1;i<360000;i++);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	for(int i=1;i<1080000;i++);}}