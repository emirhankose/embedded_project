/*
 * bsp.h
 *
 *  Created on: 30 Kas 2021
 *      Author: Lenovo
 */
#include "stm32g0xx.h"
#ifndef BSP_H_
#define BSP_H_


void BSP_onboardLed_init();
void BSP_onboardLed_Toggle();
void BSP_onboardLed_on();
void BSP_onboardLed_off();
void BSP_Delay(volatile unsigned int);

void BSP_onboardButton_init();
int BSP_onbaordButton_read();

void BSP_system_init();
void init_timer1();
void TIM1_BRK_UP_TRG_COM_IRQHandler(void);
__STATIC_INLINE uint32_t SysTick_Config(uint32_t ticks);
void updateProcessorsClock();

void externalInterrupt_init(int port_number);




#endif /* BSP_H_ */
