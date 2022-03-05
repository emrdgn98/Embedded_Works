#include "stm32g0xx_hal.h"

void buttonuart_init()
 {

GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
 
/*Configure GPIO pin : PC13 */
 GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);



}
int buttonuart_getstate(){


	if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==0){
		
		return 1;
		

	}
	
	else{
		
		return 0;
	
	
	
	
	}

}
