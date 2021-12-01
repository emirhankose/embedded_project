#include "bsp.h"
//static int count=0;

/*void buttonISR(void){
	GPIOC->ODR ^=(1<<6);
	count++;
}


void EXTI4_15_IRQHandler(void){

	if((EXTI->RPR1 >>4)&1){
	GPIOC->ODR ^=(1U<<6);
	EXTI->RPR1 |= (1U<<4); //RISING EDGE PENDING REGISTER
	}


}*/

#define LEDDELAY 1600000U

void TIM1_BRK_UP_TRG_COM_IRQHandler(void);/*{
	BSP_onboardLed_Toggle();
	TIM1->SR &=~(1U<<0); //clear update status register.
}*/

void init_timer1();/*{

	RCC->APBENR2 |=(1U<<11); // enable tim1 module
	TIM1->CR1=0; //zero out the cotnrol register just in case
	TIM1->CR1 |=(1<<7);
	TIM1->CNT = 0; //zero out counter
	 //1 seconds interrupt
	TIM1->PSC = 999;
	TIM1->ARR = 16000;

	TIM1->DIER |=(1<<0);// update interrupt enable
	TIM1->CR1 |=(1<<0); //TIM 1 is ENABLED

	NVIC_EnableIRQ(TIM1_BRK_UP_TRG_COM_IRQn);
	NVIC_SetPriority(TIM1_BRK_UP_TRG_COM_IRQn, 1);
}*/


int main(){

	/*RCC->IOPENR |=(3U<<1);
	GPIOB->MODER &=~(3U<<2*4);
	GPIOC->MODER &=~(3U<<2*6);
	GPIOC->MODER |=(1U<<2*6);

	EXTI->RTSR1 |=(1U<<4);
	EXTI->EXTICR[1] |= 1U;
	EXTI->IMR1 |= (1U<<4);

	NVIC_SetPriority(EXTI4_15_IRQn,0);
	NVIC_EnableIRQ(EXTI4_15_IRQn);*/
 BSP_system_init();
 init_timer1();
while(1){

}

	return 0;
}
