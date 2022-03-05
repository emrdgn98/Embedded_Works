#include "stm32g0xx_hal.h"


void leddriver_init()
{
	
	RCC -> IOPENR |= (1<<0);
	
	

	GPIOA ->MODER &= ~(1<<11);

	GPIOA -> MODER |= (1<<10);
	
	GPIOA ->OTYPER &= ~(1<<5);
	
	GPIOA ->OSPEEDR |= (1<<11);
	
	GPIOA ->OSPEEDR |= (1<<10);



}
	


void leddriver_on()
{
	GPIOA -> BSRR = (1<<5);
	
	




}


void leddriver_off()
{

	GPIOA -> BRR = (1<<5);



}

	


