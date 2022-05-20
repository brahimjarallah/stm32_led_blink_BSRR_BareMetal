#include "stm32f4xx.h" // Device header
// PD15 // LD6

void delay(void);
// void delay(int delay);

int main(void){
	
	RCC->AHB1ENR |= 8;  // 1bit/input  /16bits
	GPIOD->MODER |= 0x40000000; // 2bits/input /32bits
	
	while(1){
		GPIOD->BSRR = 0x8000u;  // 1bit/input  /16bits
		delay();
		GPIOD->BSRR = 0x80000000u;
		delay();
	}	
}	

void delay(void){
	volatile int i;
for(i=0;i<500000;i++);
}
		