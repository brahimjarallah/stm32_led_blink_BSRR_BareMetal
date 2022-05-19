#include "stm32f4xx.h" // Device header
// PD12 // LD4

//void delay(void);
void delay(int delay);

int main(void){
	
	RCC->AHB1ENR |= 1000;  // 1bit/input  /16bits
	GPIOD->MODER |= 0x1000000; // 2bits/input /32bits
	
	while(1){
		GPIOD->BSRR = 1000u;  // 1bit/input  /16bits
		delay(1000);
		GPIOD->BSRR = 10000000u;
		delay(1000);
	}	
}	


void delay(int delay)
{ int i ;
for(; delay>0; delay--)
{
for(i=0; i<4000; i++);
}
}

//void delay(void){
//	volatile int i;
//for(i=0;i<500000;i++);
//}
		