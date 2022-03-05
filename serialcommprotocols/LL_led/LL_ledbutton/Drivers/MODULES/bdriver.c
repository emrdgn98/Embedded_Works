#include "stm32g0xx_hal.h"


void bdriver_init()
{
	RCC ->IOPENR |=(1<<2);
	
	GPIOC ->MODER &= ~(1<<27);

	GPIOC -> MODER &= ~(1<<26);
	
	GPIOC ->OSPEEDR |= (1<<11);
	
	GPIOC ->OSPEEDR |= (1<<10);


}
	



int bdriver_getstate()
{
	if(!(GPIOC->IDR & (1<<13)))
		{
			
			return 1;
	
			
		}
		
		else
		{
			return 0;

		
		}





}
	



	


