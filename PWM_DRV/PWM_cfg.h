/*
 * PWM_cfg.h
 *
 *  Created on: Oct 6, 2018
 *      Author: Mohamed
 */

#ifndef PWM_DRV_PWM_CFG_H_
#define PWM_DRV_PWM_CFG_H_

// TIMER0 REGISTERS
#define TCCR1A          (*(volatile u8 *)0x4F) //timer1 settings
#define TCCR1B          (*(volatile u8 *)0x4E) //timer1 settings
#define TCNT1 			*((volatile u8 *)0x4C)	//timer1register
#define OCR1A           (*(volatile u16 *)0x4A) //timer1 compare match
#define OCR1B           (*(volatile u16 *)0x48) //timer1 compare match
#define ICR1            (*(volatile u16 *)0x46) //timer1 TOP
#define TIMSK 			*((volatile u8 *)0x59)	//interrupt flags enable----------
#define TIFR 			*((volatile u8 *)0x58)	//Flags
#define SREG     		*((volatile u8*)0x5F) 	// Global interrupt register

#endif /* PWM_DRV_PWM_CFG_H_ */
