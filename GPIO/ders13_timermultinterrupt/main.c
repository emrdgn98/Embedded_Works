#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM


void gpioConfig(){
	
GPIO_InitTypeDef GpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GpioInitStructure);
	






}

void timConfig(){
	
	TIM_TimeBaseInitTypeDef TIMInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIMInitStructure.TIM_ClockDivision=1;
	TIMInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIMInitStructure.TIM_Period=3999;
	TIMInitStructure.TIM_Prescaler=5999;
	TIMInitStructure.TIM_RepetitionCounter=0;
	
	TIM_TimeBaseInit(TIM2,&TIMInitStructure);
	TIM_Cmd(TIM2,ENABLE);
	
	
	TIMInitStructure.TIM_ClockDivision=1;
	TIMInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIMInitStructure.TIM_Period=5999;
	TIMInitStructure.TIM_Prescaler=7999;
	TIMInitStructure.TIM_RepetitionCounter=0;
	
	TIM_TimeBaseInit(TIM3,&TIMInitStructure);
	TIM_Cmd(TIM3,ENABLE);
	}
	
void nvicConfig(){
	
	NVIC_InitTypeDef NvicInitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NvicInitStructure.NVIC_IRQChannel=TIM2_IRQn;
	NvicInitStructure.NVIC_IRQChannelCmd=ENABLE;
  NvicInitStructure.NVIC_IRQChannelPreemptionPriority=0;
	NvicInitStructure.NVIC_IRQChannelSubPriority=0;
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	NVIC_Init(&NvicInitStructure);

  NvicInitStructure.NVIC_IRQChannel=TIM3_IRQn;
	NvicInitStructure.NVIC_IRQChannelCmd=ENABLE;
  NvicInitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NvicInitStructure.NVIC_IRQChannelSubPriority=0;

	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	NVIC_Init(&NvicInitStructure);
}


void toggle_led(uint16_t pin){
   
   uint16_t readLed=GPIO_ReadInputDataBit(GPIOB,pin);
   
   if(readLed==(uint16_t)Bit_SET){
      GPIO_ResetBits(GPIOB,pin);

   }else{
     GPIO_SetBits(GPIOB,pin);
   
   }

}

void TIM2_IRQHandler(){
	toggle_led(GPIO_Pin_0);
	TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	

}
void TIM3_IRQHandler(){
	toggle_led(GPIO_Pin_1);
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	

}


int main(){
	
	gpioConfig();
	timConfig();
	nvicConfig();

	while(1){
	
	
	
	
	}


}
