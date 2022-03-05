#include "stm32g0xx_hal.h"



#ifndef __uartdriver_H

#define __uartdriver_H

void uartdriver_init(void);

 
  
int uarttransmit_init(void);
int uartreceive_init(void);



#endif
