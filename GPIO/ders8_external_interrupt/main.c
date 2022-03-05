#include "stm32f10x.h"     // Device header
#include "stm32f10x_exti.h"
 void gpioConfig(){
 
 GPIO_InitTypeDef GPIO_InitStructure;
	 
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	 
	 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	 GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	 
	 
	 GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	 GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	 GPIO_Init(GPIOB,&GPIO_InitStructure);
	 GPIO_Init(GPIOC,&GPIO_InitStructure);
 
 
 }
 void extiConfig(){
	 
	 EXTI_InitTypeDef EXTIInitStructure;
	 NVIC_InitTypeDef NVICInitStructure;
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//burdada afio verilmis sanal oldugundan
	 GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource6);//kod farki var
		 
	 EXTIInitStructure.EXTI_Line=EXTI_Line6;
	 EXTIInitStructure.EXTI_LineCmd=ENABLE;
	 EXTIInitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	 EXTIInitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	 
	 EXTI_Init(&EXTIInitStructure);
	 
	 NVICInitStructure.NVIC_IRQChannel=EXTI9_5_IRQn;
	 NVICInitStructure.NVIC_IRQChannelCmd=ENABLE;
	 NVICInitStructure.NVIC_IRQChannelPreemptionPriority=1;
	 NVICInitStructure.NVIC_IRQChannelSubPriority=1;
	 
	 NVIC_Init(&NVICInitStructure);
	 
 }
 void delay(uint32_t time){
 
 while(time--);
 
 }
 void EXTI9_5_IRQHandler(){
	 if(EXTI_GetITStatus(EXTI_Line6)!=RESET){
	 
	 for(int i=0;i<4;i++){
	 
		 GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
		 delay(360000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
		 delay(360000);
	 
	 
	 }
	 EXTI_ClearITPendingBit(EXTI_Line6);
	 
	 }
	
 }

 
int main(){
  gpioConfig();
  extiConfig();
  int ledarray[3]={GPIO_Pin_0,GPIO_Pin_1,GPIO_Pin_2};
 while(1){
	
	 for(int i=0;i<3;i++){
		 
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
