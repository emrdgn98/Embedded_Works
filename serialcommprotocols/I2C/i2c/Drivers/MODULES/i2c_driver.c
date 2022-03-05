#include "stm32g0xx.h"                  // Device header
#include "leduart.h"
#define BUFFERSIZE  (6)
#define TXBUFFERSIZE BUFFERSIZE
#define RXBUFFERSIZE sizeof(TXBUFFERSIZE)-1
uint8_t TxMessage[TXBUFFERSIZE]={1,2,3,4,5,6};
uint8_t RxMessage[RXBUFFERSIZE];


I2C_HandleTypeDef hi2c1;
void i2c_driver_init(){


	GPIO_InitTypeDef  GPIO_InitStruct;
  
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable GPIO TX/RX clock */  
	__HAL_RCC_GPIOB_CLK_ENABLE();

  /* Enable USARTx clock */
  __HAL_RCC_I2C1_CLK_ENABLE(); 
  
  /*##-2- Configure peripheral GPIO ##########################################*/  
  /* UART TX GPIO pin configuration  */
	
	
  GPIO_InitStruct.Pin       = GPIO_PIN_6;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    
  /* UART RX GPIO pin configuration  */
  GPIO_InitStruct.Pin 			= GPIO_PIN_7;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;

  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00303D5B;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_10BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 2;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  
	HAL_I2C_Init(&hi2c1);
	
	




}

void i2c_driver_master_transmit(){
	
	
	 HAL_I2C_Master_Transmit(&hi2c1, 0, (uint8_t *) TxMessage, TXBUFFERSIZE, 10000);

	


}

void i2c_driver_master_receive(){
	
	
HAL_I2C_Master_Receive(&hi2c1, 0, (uint8_t *) RxMessage, RXBUFFERSIZE, 10000);
  
    
  
	


}
void i2c_driver_slave_transmit(){
	
	
  
 HAL_I2C_Slave_Transmit(&hi2c1, (uint8_t *) TxMessage, TXBUFFERSIZE, 10000);
	


}
void i2c_driver_slave_receive(){
	
	
  HAL_I2C_Slave_Receive(&hi2c1, (uint8_t *) RxMessage,RXBUFFERSIZE, 10000);
	


}
