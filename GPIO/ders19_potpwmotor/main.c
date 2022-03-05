#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_adc.h"              // Keil::Device:StdPeriph Drivers:ADC

uint16_t adcValue=0;
float mapValue=0;
uint16_t potValue=0;
void gpioConfig(){
	
	GPIO_InitTypeDef GpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_1;
	GpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GpioInitStructure);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_AIN;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_1;
	
	
	GPIO_Init(GPIOC,&GpioInitStructure);




}

void adcConfig(){
	
	ADC_InitTypeDef AdcInitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	
	AdcInitStructure.ADC_ContinuousConvMode=ENABLE;
	AdcInitStructure.ADC_DataAlign=ADC_DataAlign_Right;
	AdcInitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	AdcInitStructure.ADC_Mode=ADC_Mode_Independent;
	AdcInitStructure.ADC_NbrOfChannel=1;
	AdcInitStructure.ADC_ScanConvMode=DISABLE;
	ADC_Init(ADC1,&AdcInitStructure);
	ADC_Cmd(ADC1,ENABLE);

	
	
	
	




}

uint16_t readAdc()
{
	ADC_RegularChannelConfig(ADC1,ADC_Channel_11,1,ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
	return ADC_GetConversionValue(ADC1);



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
float map(float adcValue , float max ,float min, float conMax , float conMin){

return adcValue*((conMax-conMin)/(max-min));


}
	
int main()
{
	gpioConfig();
	timConfig();
  adcConfig();  	
	
	
	
	while(1){
		potValue=readAdc();
		mapValue=map(potValue,4030,0,2399,0);
		pwmConfig(mapValue);
		
	
	
		
		
	
	
	
	}


}
