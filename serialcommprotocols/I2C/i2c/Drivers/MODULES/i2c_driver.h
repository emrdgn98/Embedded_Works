#include "stm32g0xx_hal.h"


#ifndef __i2c_driver_H

#define __i2c_driver_H
void i2c_driver_init(void);

void i2c_driver_master_transmit(void);
void i2c_driver_master_receive(void);



void i2c_driver_slave_transmit(void);


void i2c_driver_slave_receive(void);





#endif
