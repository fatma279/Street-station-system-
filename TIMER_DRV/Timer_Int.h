/*
 * Timer_Int.h
 *
 *  Created on: Oct 6, 2018
 *      Author: Mohamed
 */

#ifndef TIMER_DRV_TIMER_INT_H_
#define TIMER_DRV_TIMER_INT_H_

#define ON 1
#define OFF 0

/*
 * Prescaler values for timer0
 */
#define Prescale_1 1
#define Prescale_8 8
#define Prescale_64 64
#define Prescale_256 256
#define Prescale_1024 1024

extern void Timer0_InternalClock_Normal_Init(u8 Timer0_Interrupt, u16 Timer0_Prescaler);
extern void Timer0_Normal_delay_ms(u16 delay_time_ms);
extern void Timer0_InternalClock_CTC_Init(u8 Timer0_Interrupt, u16 Timer0_Prescaler , u8 Output_Compare);
extern void Timer0_CTC_delay_ms(u16 delay_time_ms);

extern void Set_Call_Back_Timer0(void (*Input_Function)(void));


#endif /* TIMER_DRV_TIMER_INT_H_ */
