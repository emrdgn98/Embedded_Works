#include "stm32f10x.h"                  // Device header
#include "stm32f10x_dac.h"              // Keil::Device:StdPeriph Drivers:DAC


void dacConfig(){

DAC_InitTypeDef DacInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);
	
	
	DacInitStructure.DAC_LFSRUnmask_TriangleAmplitude=DISABLE;
	DacInitStructure.DAC_OutputBuffer=ENABLE;
	DacInitStructure.DAC_Trigger=DAC_Trigger_None;
	DacInitStructure.DAC_WaveGeneration=DAC_WaveGeneration_None;
	
	DAC_Init(DAC_Channel_1,&DacInitStructure);
	DAC_Cmd(DAC_Channel_1,ENABLE);
	




}
void delay(uint32_t time){

while(time--);


}








int main(){
	
	while(1){
	for(int i=0; i<255; i++){
		
		DAC_SetChannel1Data(DAC_Align_12b_R,i);
		delay(3600);
	
	
	}
	
	
	}











}