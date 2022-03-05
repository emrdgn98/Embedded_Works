#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

uint16_t counter = 0;
void gpioConfig(){
	
	GPIO_InitTypeDef GpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_0;
	GpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GpioInitStructure);
	





}
void SysTic_Handler(void){
	
	if(counter > 0)
	counter--;
	





}
void delay_ms(uint32_t time)
{

  counter = time;
	while(counter);


}



int main(){
	gpioConfig();
	
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000);
	
	
	while(1){
		
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
		delay_ms(10);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		delay_ms(10);
	
	
	
	
	}



}
