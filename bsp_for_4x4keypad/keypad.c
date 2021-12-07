#include "keypad.h"

#include"stm32g0xx.h"


void setKeypad(char R1, int port_no){

	if(R1=='A' && port_no==7){ //R1-A7 R2-A5 R3-A6 R2-A4

		// ADJUSTING PINS AS OUTPUT AND INPUT
		RCC->IOPENR |=(1U<<0);

		GPIOA->MODER &=~(15U<<0);
		GPIOA->MODER |=(5U<<0);
		GPIOA->MODER &=~(15U<<2*4);
		GPIOA->MODER |=(5U<<2*4);
		GPIOA->MODER &=~(15U<<2*6);
		GPIOA->MODER &=~(15U<<2*11);

		//INTERRUPT

		EXTI->RTSR1 |=(1U<<7);
		EXTI->RTSR1 |=(1U<<11);
		EXTI->RTSR1 |=(1U<<6);
		EXTI->RTSR1 |=(1U<<12);


		EXTI->EXTICR[1] |=(1U<<3*8);
		EXTI->EXTICR[2] |=(1U<<3*8);
		EXTI->EXTICR[1] |=(1U<<2*8);
		EXTI->EXTICR[3] |=(1U<<0);

		EXTI->IMR1 =(1U<<7);
		EXTI->IMR1 =(1U<<11);
		EXTI->IMR1 =(1U<<6);
		EXTI->IMR1 =(1U<<12);

		NVIC_SetPriority(EXTI0_1_IRQn,0);
		NVIC_EnableIRQ(EXTI0_1_IRQn);

		NVIC_SetPriority(EXTI2_3_IRQn,0);
		NVIC_EnableIRQ(EXTI2_3_IRQn);

		NVIC_SetPriority(EXTI4_15_IRQn,0);
		NVIC_EnableIRQ(EXTI4_15_IRQn);

	}
	else if(R1=='A' && port_no==0){ //R1-A0 R2-A1 R3-A2 R2-A3

		// ADJUSTING PINS AS OUTPUT AND INPUT
		RCC->IOPENR |=(1U<<0);
		GPIOA->MODER &=~(15U<<0);
		GPIOA->MODER &=~(15U<<2*4);
		GPIOA->MODER &=~(15U<<2*6);
		GPIOA->MODER |=(5U<<2*6);
		GPIOA->MODER &=~(15U<<2*11);
		GPIOA->MODER |=(5U<<2*11);
		//INTERRUPT
		EXTI->RTSR1 |=(1U<<0);
		EXTI->RTSR1 |=(1U<<1);
		EXTI->RTSR1 |=(1U<<4);
		EXTI->RTSR1 |=(1U<<5);


		EXTI->EXTICR[0] |=(1U<<0);
		EXTI->EXTICR[0] |=(1U<<2*1);
		EXTI->EXTICR[1] |=(1U<<0);
		EXTI->EXTICR[1] |=(1U<<2*1);

		EXTI->IMR1 =(1U<<0);
		EXTI->IMR1 =(1U<<1);
		EXTI->IMR1 =(1U<<4);
		EXTI->IMR1 =(1U<<5);

		NVIC_SetPriority(EXTI0_1_IRQn,0);
		NVIC_EnableIRQ(EXTI0_1_IRQn);

		NVIC_SetPriority(EXTI2_3_IRQn,0);
		NVIC_EnableIRQ(EXTI2_3_IRQn);

		NVIC_SetPriority(EXTI4_15_IRQn,0);
		NVIC_EnableIRQ(EXTI4_15_IRQn);

	}
	else if(R1=='D'&& port_no==12){ //R1-D12 R2-D11 R3-D10 R2-D9

		RCC->IOPENR |=(3U<<0);
		// ADJUSTING PINS AS OUTPUT AND INPUT
		GPIOB->MODER &=~(3U<<0);
		GPIOB->MODER &=~(3U<<2*2);
		GPIOB->MODER &=~(15U<<2*4);
		GPIOB->MODER |=(5U<<2*4);
		GPIOB->MODER &=~(15U<<2*8);
		GPIOB->MODER |=(1U<<2*9);

		GPIOA->MODER &=~(15U<<2*8);
		GPIOA->MODER |=(1U<<2*8);

		//INTERRUPT
		EXTI->RTSR1 |=(1U<<4);
		EXTI->RTSR1 |=(1U<<5);
		EXTI->RTSR1 |=(1U<<9);
		EXTI->RTSR1 |=(1U<<8);


		EXTI->EXTICR[1] |=(1U<<0);
		EXTI->EXTICR[1] |=(1U<<1*8);
		EXTI->EXTICR[2] |=(1U<<1*8);
		EXTI->EXTICR[2] |=(1U<<0);

		EXTI->IMR1 =(1U<<4);
		EXTI->IMR1 =(1U<<5);
		EXTI->IMR1 =(1U<<9);
		EXTI->IMR1 =(1U<<8);

		NVIC_SetPriority(EXTI0_1_IRQn,0);
		NVIC_EnableIRQ(EXTI0_1_IRQn);

		NVIC_SetPriority(EXTI2_3_IRQn,0);
		NVIC_EnableIRQ(EXTI2_3_IRQn);

		NVIC_SetPriority(EXTI4_15_IRQn,0);
		NVIC_EnableIRQ(EXTI4_15_IRQn);

	}
	else if(R1=='D' && port_no==3){//R1-D3 R2-D4 R3-D5 R2-D6
		RCC->IOPENR |=(3U<<0);
		// ADJUSTING PINS AS OUTPUT AND INPUT
		GPIOB->MODER &=~(15U<<0);
		GPIOB->MODER &=~(3U<<2*2);
		GPIOB->MODER |=(1U<<2*2);
		GPIOB->MODER &=~(15U<<2*8);
		GPIOB->MODER |=(5U<<2*8);


		GPIOA->MODER &=~(15U<<2*8);
		GPIOA->MODER |=(1U<<2*8);
		GPIOA->MODER &=~(3U<<2*10);
		//INTERRUPT
	}

	else if(R1=='D' && port_no==4){ //R1-D4 R2-D5 R3-D6 R2-D7
		RCC->IOPENR |=(3U<<0);
		// ADJUSTING PINS AS OUTPUT AND INPUT
		GPIOB->MODER &=~(3U<<0);
		GPIOB->MODER &=~(3U<<2*2);
		GPIOB->MODER &=~(3U<<2*5);
		GPIOB->MODER |=(1U<<2*5);

		GPIOB->MODER &=~(15U<<2*8);
		GPIOB->MODER &=(5U<<2*8);

		GPIOA->MODER &=~(15U<<2*7);
		GPIOA->MODER |=(1U<<2*7);
		GPIOA->MODER &=~(3U<<2*9);
		//INTERRUPT
		EXTI->RTSR1 |=(1U<<10);
		EXTI->RTSR1 |=(1U<<9);
		EXTI->RTSR1 |=(1U<<0);
		EXTI->RTSR1 |=(1U<<2);


		EXTI->EXTICR[2] |=(1U<<2*8);
		EXTI->EXTICR[2] |=(1U<<1*8);
		EXTI->EXTICR[0] |=(1U<<0);
		EXTI->EXTICR[0] |=(1U<<2*8);

		EXTI->IMR1 |=(1U<<10);
		EXTI->IMR1 |=(1U<<9);
		EXTI->IMR1 |=(1U<<0);
		EXTI->IMR1 |=(1U<<2);

		NVIC_SetPriority(EXTI0_1_IRQn,0);
		NVIC_EnableIRQ(EXTI0_1_IRQn);

		NVIC_SetPriority(EXTI2_3_IRQn,0);
		NVIC_EnableIRQ(EXTI2_3_IRQn);

		NVIC_SetPriority(EXTI4_15_IRQn,0);
		NVIC_EnableIRQ(EXTI4_15_IRQn);

	}
	else if(R1=='D' && port_no==5){//R1-D5 R2-D6 R3-D7 R2-D8
		// ADJUSTING PINS AS OUTPUT AND INPUT
		RCC->IOPENR |=(3U<<0);
		GPIOB->MODER &=~(3U<<0);
		GPIOB->MODER &=~(3U<<2*2);
		GPIOB->MODER &=~(15U<<2*4);
		GPIOB->MODER |=(5U<<2*4);
		GPIOB->MODER &=~(15U<<2*8);
		GPIOB->MODER |=(1U<<2*9);

		GPIOA->MODER &=~(15U<<2*8);
		GPIOA->MODER |=(1U<<2*8);
		//INTERRUPT
		EXTI->RTSR1 |=(1U<<9);
		EXTI->RTSR1 |=(1U<<0);
		EXTI->RTSR1 |=(1U<<2);
		EXTI->RTSR1 |=(1U<<8);


		EXTI->EXTICR[2] |=(1U<<1*8);
		EXTI->EXTICR[0] |=(1U<<0);
		EXTI->EXTICR[0] |=(1U<<2*8);
		EXTI->EXTICR[2] |=(1U<<0);

		EXTI->IMR1 |=(1U<<9);
		EXTI->IMR1 |=(1U<<0);
		EXTI->IMR1 |=(1U<<2);
		EXTI->IMR1 |=(1U<<8);

		NVIC_SetPriority(EXTI0_1_IRQn,0);
		NVIC_EnableIRQ(EXTI0_1_IRQn);

		NVIC_SetPriority(EXTI2_3_IRQn,0);
		NVIC_EnableIRQ(EXTI2_3_IRQn);

		NVIC_SetPriority(EXTI4_15_IRQn,0);
		NVIC_EnableIRQ(EXTI4_15_IRQn);
	}
}
