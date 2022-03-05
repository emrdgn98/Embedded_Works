#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include <stdlib.h>
#include "seg7Display.h"



int main(){
	seg7DisplayInit(portA,PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6);

	while(1){
		printNumber(portA,5);
		delay(3600000);
		printLetter(portA,'c');
		delay(3600000);
		cleanDisplay(portA);
		delay(3600000);
		countForward(portA,3600000);
		delay(3600000);	
	}



}
