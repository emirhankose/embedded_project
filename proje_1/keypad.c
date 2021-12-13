#include "keypad.h"

#include"stm32g0xx.h"

void setKeypad(){ //R1 ->A7(PA7) , R2 ->A5(PA11), R3 ->A6(PA6), R4 ->A4(PA12), C1 ->A3(PA5), C2 ->A2(PA4), C3 ->A1(PA1), C4 ->A0(PA0)

	RCC ->IOPENR |=(1U<<0);

	//ROWS ARE OUTPUT COLUMNS ARE INPUT.
	GPIOA ->MODER &=~(15U<<0);
	GPIOA ->MODER &=~(15U<<2*4);
	GPIOA ->MODER &=~(15U<<2*6);
	GPIOA ->MODER |=(5U<<2*6);
	GPIOA ->MODER &=~(15U<<2*11);
	GPIOA ->MODER |=(5U<<2*11);
}

void ext_interrupt_keypad(){
	EXTI ->RTSR1 |=(1U<<0);
	EXTI ->RTSR1 |=(1U<<1);
	EXTI ->RTSR1 |=(1U<<4);
	EXTI ->RTSR1 |=(1U<<5);

	EXTI ->EXTICR[0] |=(1U<<0);
	EXTI ->EXTICR[0] |=(1U<<8);
	EXTI ->EXTICR[1] |=(1U<<0);
	EXTI ->EXTICR[1] |=(1U<<8);

	EXTI ->IMR1 |=(1U<<0);
	EXTI ->IMR1 |=(1U<<1);
	EXTI ->IMR1 |=(1U<<4);
	EXTI ->IMR1 |=(1U<<5);

	NVIC_SetPriority(EXTI0_1_IRQn,0);
	NVIC_EnableIRQ(EXTI0_1_IRQn);
	NVIC_SetPriority(EXTI2_3_IRQn,0);
	NVIC_EnableIRQ(EXTI2_3_IRQn);
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	NVIC_EnableIRQ(EXTI4_15_IRQn);

}

void EXTI4_15_IRQHandler(void){
	low_rows();


}


void EXTI0_1_IRQHandler(void){
	low_rows();
	if((EXTI->RPR1>>1)&1){
		//3 6 9 # yanacak
	}
	else if((EXTI->RPR1)&1){
		//harfler hanacak
	}

}

void EXTI2_3_IRQHandler(void){
	////
}

void setSSD(){
	//D1->D12(PB4), A->D11(PB5), F->D10(PB9), D2->D9(PA8), D3->D8(PB8), B->D7(PB2),
	//E->D1(PB6), D->D0(PB7), dec->D3(PB1),C->D4(PA10),G->D5(PA9),D4->D6(PB0)
RCC ->IOPENR |=(3U<<0);

GPIOA ->MODER &=~(63U<<2*7);
GPIOA ->MODER |=(21U<<2*7);

GPIOB ->MODER &=~(15U<<2*8);
GPIOB ->MODER |=(5U<<2*8);
GPIOB ->MODER &=~(15U<<2*6);
GPIOB ->MODER |=(5U<<2*6);
GPIOB ->MODER &=~(15U<<2*4);
GPIOB ->MODER |=(5U<<2*4);
GPIOB ->MODER &=~(15U<<2);
GPIOB ->MODER |=(5U<<2);
GPIOB ->MODER &=~(3U<<0);
GPIOB ->MODER |=(1U<<0);
}

void ssdOne(){ // B  C

	GPIOA->ODR |=(1U<<10);
	GPIOB->ODR |=(1U<<2);
}
void ssdTwo(){// A B G E D
	GPIOB ->ODR |(1U<<5);
	GPIOB->ODR |=(1U<<2);
	GPIOA->ODR |=(1U<<9);
	GPIOB->ODR |=(1U<<6);
	GPIOB->ODR |=(1U<<7);
}
void ssdThree(){//A B G C D
	GPIOB ->ODR|=(1U<<5);
	GPIOB->ODR |=(1U<<2);
	GPIOA->ODR |=(1U<<10);
	GPIOA->ODR |=(1U<<9);
	GPIOB->ODR |=(1U<<7);
}
void ssdFour(){ //F G B C
	GPIOA->ODR |=(1U<<9);
	GPIOA->ODR |=(1U<<10);
	GPIOB->ODR |=(1U<<2);
	GPIOB->ODR |=(1U<<9);

}
void ssdFive(){ //A F G C D
	GPIOB->ODR |=(1U<<5);
	GPIOB->ODR |=(1U<<9);
	GPIOA->ODR |=(1U<<9);
	GPIOA->ODR |=(1U<<10);
	GPIOB->ODR |=(1U<<7);
}
void ssdSix(){
	GPIOB->ODR |=(1U<<5);
	GPIOB->ODR |=(1U<<9);
	GPIOA->ODR |=(1U<<9);
	GPIOA->ODR |=(1U<<10);
	GPIOB->ODR |=(1U<<7);
	GPIOB->ODR |=(1U<<6);
}
void ssdSeven(){
	GPIOA->ODR |=(1U<<10);
	GPIOB->ODR |=(1U<<2);
	GPIOB->ODR |=(1U<<5);
}
void ssdEight(){
	GPIOB->ODR |=(1U<<5);
	GPIOB->ODR |=(1U<<2);
	GPIOA->ODR |=(1U<<9);
	GPIOB->ODR |=(1U<<7);
	GPIOA->ODR |=(1U<<10);
	GPIOB->ODR |=(1U<<9);
}
void ssdNine(){
	GPIOB->ODR |=(1U<<5);
	GPIOB->ODR |=(1U<<2);
	GPIOA->ODR |=(1U<<9);
	GPIOB->ODR |=(1U<<6);
	GPIOB->ODR |=(1U<<7);
	GPIOA->ODR |=(1U<<10);
	GPIOB->ODR |=(1U<<9);
}
void ssdZero(){
	GPIOB->ODR |=(1U<<5);
	GPIOB->ODR |=(1U<<2);
	GPIOB->ODR |=(1U<<7);
	GPIOA->ODR |=(1U<<10);
	GPIOB->ODR |=(1U<<9);
}

void on_SSD1() {/* turn on SSD 1(LEFT).*/
	 /* turn on ODR*/
	GPIOB->ODR |= (0x100);
}
void off_SSD1() {/* turn off SSD 1(LEFT).*/
	 /* turn on ODR*/
	GPIOB->BRR |= (0x100);
}
void on_SSD2() {/* turn on SSD 2.*/
	 /* turn on ODR*/
	GPIOB->ODR |= (0x4);
}
void off_SSD2() {/* turn off SSD 2.*/
	 /* turn on ODR*/
	GPIOB->BRR |= (0x4);
}
void on_SSD3() {/* turn on SSD 3.*/
	 /* turn on ODR*/
	GPIOB->ODR |= (0x1);
}
void off_SSD3() {/* turn off SSD 3.*/
	 /* turn on ODR*/
	GPIOB->BRR |= (0x1);
}
void on_SSD4() {/* turn on SSD 4.*/
	 /* turn on ODR*/
	GPIOB->ODR |= (0x2);
}
void off_SSD4() {/* turn off SSD 4.*/
	 /* turn on ODR*/
	GPIOB->BRR |= (0x2);
}

void run(){
	       on_SSD1();
		   setSSD(l);
		   delay(3250);
		   off_SSD1();
		   delay(100);

		   on_SSD2();
		   setSSD(k);
		   delay(3250);
		   off_SSD2();
		   delay(100);

		   on_SSD3();
		   setSSD(j);
		   delay(3250);
		   off_SSD3();
		   delay(100);

		   on_SSD4();
		   setSSD(i);
		   delay(3250);
		   off_SSD4();
		   delay(100);
}

void ssdA();//amplitude
void ssdB();//frequency
void ssdC();//cycle through mode
void ssdD();//displaying mode
void ssdStar(){// dot

	GPIOB->ODR |=(1U<<0);

}
void ssdSquare();// enter


void toggle_r1(){
GPIOA->ODR ^=(1U<<7);
}
void toggle_r2(){
	GPIOA->ODR ^=(1U<<11);
}

void toggle_r3(){
	GPIOA->ODR ^=(1U<<6);
}

void toggle_r4(){
	GPIOA->ODR ^=(1U<<12);

}
void low_rows(){
	GPIOA->ODR &=~(1U<<7);
	GPIOA->ODR &=~(1U<<11);
	GPIOA->ODR &=~(1U<<6);
	GPIOA->ODR &=~(1U<<12);
}
void high_rows(){
	GPIOA->ODR |=(1U<<7);
	GPIOA->ODR |=(1U<<11);
	GPIOA->ODR |=(1U<<6);
	GPIOA->ODR |=(1U<<12);
}

