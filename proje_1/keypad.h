#include "stm32g0xx.h"
#ifndef KEYPAD_H_
#define KEYPAD_H

void setKeypad();

void ext_interrupt_keypad();
void EXTI4_15_IRQHandler(void);
void EXTI0_1_IRQHandler(void);
void EXTI2_3_IRQHandler(void);
void setSSD();
void high_rows();
void low_rows();

void ssdOne();
void ssdTwo();
void ssdThree();
void ssdFour();
void ssdFive();
void ssdSix();
void ssdSeven();
void ssdEight();
void ssdNine();
void ssdZero();
void ssdA();
void ssdB();
void ssdC();
void ssdD();
void ssdStar();
void ssdSquare();

void toggle_r1();
void toggle_r2();
void toggle_r3();
void toggle_r4();


#endif
