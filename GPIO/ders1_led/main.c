#include "stm32f10x.h"                  // Device header


void delay(uint32_t time)
{

time=time*2318;
	while(time)
		time--;

}
void gpioConfig()
	{

  GPIO_InitTypeDef GPIOInitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOB,&GPIOInitStructure);

 
 
 
 
 
}

int main()
	{
gpioConfig();
while(1){
/* its a different way
	GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_SET);
	delay(1000);
	GPIO_WriteBit(GPIOB,GPIO_Pin_0,Bit_RESET);
	delay(1000);
	
	*/
	
	GPIO_SetBits(GPIOB,GPIO_Pin_0);
	delay(1000);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	delay(1000);
}}