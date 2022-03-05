#include "stm32g0xx.h"                  // Device header

UART_HandleTypeDef huart1;

uint8_t x[1]={1};
uint8_t y[1];

void uartdriver_init(){

	
	 GPIO_InitTypeDef  GPIO_InitStruct;
    
	__HAL_RCC_GPIOC_CLK_ENABLE();

  
  __HAL_RCC_USART1_CLK_ENABLE(); 
  
	
  GPIO_InitStruct.Pin       = GPIO_PIN_4;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_USART1;
  
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  GPIO_InitStruct.Pin 			= GPIO_PIN_5;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_USART1;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  
	HAL_UART_Init(&huart1);
}
int uarttransmit_init(){

	HAL_UART_Transmit(&huart1,(uint8_t *)x,sizeof(x),5000);
	return 1;
}

int uartreceive_init(){
 
		HAL_UART_Receive(&huart1,(uint8_t *)y,sizeof(y),5000);
	
	return 1;

}
