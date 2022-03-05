#include "stm32g0xx_hal.h"
int i=0;
void buttonuart_init()
 {

GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
 
/*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}
int buttonuart_getstate(){


	if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==0 || i==1){
		i=1;
		return 1;
		

	}
	
	else{
		i=0;
		return 0;
	
	
	
	
	}

}
