#include "stm32g0xx.h"
#include "keypad.h"





void EXTI4_15_IRQHandler(void);
void EXTI0_1_IRQHandler(void);
void EXTI2_3_IRQHandler(void);


int main(){

	setSSD();
	setKeypad();
	high_rows();
	ext_interrupt_keypad();

while(1){

}

	return 0;
}
