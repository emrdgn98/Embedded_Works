#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

void gpioConfig()
{

	GPIO_InitTypeDef GpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
  GpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GpioInitStructure);


}


void timConfig(){
    
	TIM_TimeBaseInitTypeDef  TimInitStructure;
	NVIC_InitTypeDef NvicInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	TimInitStructure.TIM_ClockDivision=1;

	TimInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
  TimInitStructure.TIM_Period=5999;
	TimInitStructure.TIM_Prescaler=7999;
	TimInitStructure.TIM_RepetitionCounter=0;
	
	TIM_TimeBaseInit(TIM2,&TimInitStructure);
	TIM_Cmd(TIM2,ENABLE);
	
	NvicInitStructure.NVIC_IRQChannel=TIM2_IRQn;
	NvicInitStructure.NVIC_IRQChannelCmd=ENABLE;
	NvicInitStructure.NVIC_IRQChannelPreemptionPriority=0;
  NvicInitStructure.NVIC_IRQChannelSubPriority=0;
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	NVIC_Init(&NvicInitStructure);
	


}
void toogle_led(){
 
	uint16_t readled=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
	
	if(readled==(uint16_t)Bit_SET){
		
		GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
		
	
	}

	else{
	
	GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
	
	
	}

}


void TIM2_IRQHandler(){

toogle_led();
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);



}










int main()
	
{
	gpioConfig();
	timConfig();
	
	while(1){
	
	
	}






}

	
