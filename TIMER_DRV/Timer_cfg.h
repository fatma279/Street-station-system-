/*
 * Timer_cfg.h
 *
 *  Created on: Oct 6, 2018
 *      Author: Mohamed
 */

#ifndef TIMER_DRV_TIMER_CFG_H_
#define TIMER_DRV_TIMER_CFG_H_

// TIMER0 REGISTERS
#define TCCR0           *((volatile u8 *)0x53)	//timer0 settings
#define TCNT0 			*((volatile u8 *)0x54)	//timer0 register
#define OCR0 			*((volatile u8 *)0x5C)	//timer0 compare match
#define TIMSK 			*((volatile u8 *)0x59)	//interrupt flags enable----------
#define TIFR 			*((volatile u8 *)0x58)	//Flags
#define SREG     		*((volatile u8*)0x5F) 	// Global interrupt register
#endif /* TIMER_DRV_TIMER_CFG_H_ */
