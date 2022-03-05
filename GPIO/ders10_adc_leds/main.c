#include "stm32f10x.h"                  // Device header
#include "stm32f10x_adc.h"              // Keil::Device:StdPeriph Drivers:ADC

uint16_t adcValue=0;
float mapValue=0;
void gpioConfig(){
	
	GPIO_InitTypeDef GpioInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GpioInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GpioInitStructure);
	
	GpioInitStructure.GPIO_Mode=GPIO_Mode_AIN;
	GpioInitStructure.GPIO_Pin=GPIO_Pin_1;
	
	GPIO_Init(GPIOA,&GpioInitStructure);
	

	
	
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

uint16_t readADC(){
   ADC_RegularChannelConfig(ADC1,ADC_Channel_1,1,ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);
	return ADC_GetConversionValue(ADC1);



}

	
float map(float adcValue , float max ,float min, float conMax , float conMin){

return adcValue*((conMax-conMin)/(max-min));


}








int main(){
	gpioConfig();
	adcConfig();
	
	while(1){
		adcValue=readADC();
		mapValue=map(adcValue,4095,0,180,0);
		
		if(mapValue>=0 && mapValue<60){
			GPIO_SetBits(GPIOB,GPIO_Pin_0);
			GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1);
		
		}
		if(mapValue>=60 && mapValue<120){
			GPIO_SetBits(GPIOB,GPIO_Pin_0 |GPIO_Pin_1);
			GPIO_ResetBits(GPIOB,GPIO_Pin_2);
		
		}
			if(mapValue>=120 && mapValue<180){
			GPIO_SetBits(GPIOB,GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2);
				GPIO_ResetBits(GPIOB,GPIO_Pin_0 |GPIO_Pin_1 |GPIO_Pin_2);
				
		 }
			
	        }
}

		
	