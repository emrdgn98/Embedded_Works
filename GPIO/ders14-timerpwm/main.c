#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

void gpioConfig(){
	
	GPIO_InitTypeDef GpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_1;
	GpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GpioInitStructure);




}
void timConfig(){
	
	TIM_TimeBaseInitTypeDef TimInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TimInitStructure.TIM_ClockDivision=1;// OR TIM_CKD_DIV1
	TimInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TimInitStructure.TIM_Prescaler=10;
	TimInitStructure.TIM_Period=2399;
	TimInitStructure.TIM_RepetitionCounter=0;
	
	TIM_TimeBaseInit(TIM2,&TimInitStructure);
	TIM_Cmd(TIM2,ENABLE);


}
void pwmConfig(uint32_t timpulse){
	
	TIM_OCInitTypeDef TimOCInitStructure;
	
	TimOCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TimOCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TimOCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TimOCInitStructure.TIM_Pulse=timpulse;
	
	
	TIM_OC2Init(TIM2,&TimOCInitStructure);
	TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);
	


}
void delay(uint32_t time){
	
	while(time--);



}
	
int main()
{
	 gpioConfig();
	 timConfig();
	
	while(1){
		
		pwmConfig(599);
		delay(3600000000);
		pwmConfig(1199);
		delay(3600000000);
		pwmConfig(1799);
		delay(3600000000);
		pwmConfig(2399);
		delay(3600000000);
	
	
	
	}


}
