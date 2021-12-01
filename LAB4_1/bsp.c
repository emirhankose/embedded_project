#include "bsp.h"
#include "stm32g0xx.h"

void BSP_onboardLed_init(){
	RCC->IOPENR |=(1U<<2); // PORT C is ENABLED
	GPIOC->MODER &=~(3U<<2*6);
	GPIOC->MODER |=(1U<<2*6); //PC6 IS ADJUSTED AS INPUT
}

void BSP_onboardLed_Toggle(){
	GPIOC->ODR ^=(1U<<6);
}
void BSP_onboardLed_on(){

	GPIOC->ODR |=(1U<<6);
}

void BSP_onboardLed_off(){

	GPIOC->ODR &=~(1U<<6);

}
void BSP_Delay(volatile unsigned int s){
	for (s; s>0 ;s--);
}

void BSP_onboardButton_init(){
RCC->IOPENR |=(1<<5);
GPIOF->MODER &=~(3U<<2*2);
}

int BSP_onbaordButton_read(){
	int ret_value=((GPIOF->IDR >>2) & 1);

	if(ret_value) return 0;
	else return 1;
}
void BSP_system_init(){
	//SystemCoreClockUpdate();
	BSP_onboardLed_init();
	BSP_onboardButton_init();
	//Systick_Config(SystemCoreClock/1000); //16M/1000 1 ms

}
void init_timer1(){

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

}
void TIM1_BRK_UP_TRG_COM_IRQHandler(void){
		BSP_onboardLed_Toggle();
		TIM1->SR &=~(1U<<0); //clear update status register.
}
void updateProcessorsClock(){

	SystemCoreClockUpdate();
}

__STATIC_INLINE uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
  {
    return (1UL);                                                   /* Reload value impossible */
  }

  SysTick->LOAD  = (uint32_t)(ticks - 1UL);                         /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
  SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk |
                   SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                         /* Enable SysTick IRQ and SysTick Timer */
  return (0UL);                                                     /* Function successful */
}

void externalInterrupt_init(int port_number){

	EXTI->RTSR1 |=(1U<<port_number);
	if (0<=port_number<4){
		if(port_number==0)
			EXTI->EXTICR[0]=1U;
		else if(port_number==1)
			EXTI->EXTICR[0]=(1U<<8);
		else if(port_number==2)
			EXTI->EXTICR[0]=(1U<<2*8);
		else
			EXTI->EXTICR[0]=(1U<<3*8);
	}

	else if(4<=port_number<7){
		if(port_number==4)
			EXTI->EXTICR[1]=1U;
		else if(port_number==5)
			EXTI->EXTICR[1]=(1U<<8);
		else if(port_number==6)
			EXTI->EXTICR[1]=(1U<<2*8);
		else
			EXTI->EXTICR[1]=(1U<<3*8);
	}
	else if (7<=port_number<10){
		if(port_number==7)
			EXTI->EXTICR[2]=1U;
		else if(port_number==8)
			EXTI->EXTICR[2]=(1U<<8);
		else if(port_number==9)
			EXTI->EXTICR[2]=(1U<<2*8);
		else
			EXTI->EXTICR[2]=(1U<<3*8);
	}
	else if (10<=port_number<13){
			if(port_number==10)
				EXTI->EXTICR[3]=1U;
			else if(port_number==11)
				EXTI->EXTICR[3]=(1U<<8);
			else if(port_number==12)
				EXTI->EXTICR[3]=(1U<<2*8);
			else
				EXTI->EXTICR[3]=(1U<<3*8);
		}
	EXTI->IMR1 |=(1U<<port_number);
	if(0<=port_number<=1){
	NVIC_SetPriority(EXTI0_1_IRQn,0);
	NVIC_EnableIRQ(EXTI0_1_IRQn);
	}
	else if(2<=port_number<=3){
		NVIC_SetPriority(EXTI2_3_IRQn,0);
		NVIC_EnableIRQ(EXTI2_3_IRQn);
	}
	else if(3<port_number<=15){
		NVIC_SetPriority(EXTI4_15_IRQn,0);
		NVIC_EnableIRQ(EXTI4_15_IRQn);
	}
}


