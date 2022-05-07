/*
 * PWM_Int.h
 *
 *  Created on: Oct 6, 2018
 *      Author: Mohamed
 */

#ifndef PWM_DRV_PWM_INT_H_
#define PWM_DRV_PWM_INT_H_

/*
 * Prescaler values for timer0
 */
#define Prescale_1 1
#define Prescale_8 8
#define Prescale_64 64
#define Prescale_256 256
#define Prescale_1024 1024

/*Frequencies range*/
#define Freq_8_MHZ   0
#define Freq_1_MHZ   1
#define Freq_125_KHZ 2
#define Freq_312_KHZ 3
#define Freq_7812_HZ 4

/*
 * Function Timer0_FastPwm for PWM signal
 * Inputs : u8Freq : Freq_8_MHZ , Freq_1_MHZ, Freq_125_KHZ, Freq_312_KHZ, Freq_7812_HZ
 * 			u8Duty_Cycle : Range from 0 to 100
 * Outputs : None
 * Notes :
 */
extern void Timer1_FastPwm( u8 u8Freq ,  u8 u8Duty_Cycle);
/*
 * Function Timer0_PhaseCorrectPwm for PWM signal
 * Inputs : u8Freq : Freq_8_MHZ , Freq_1_MHZ, Freq_125_KHZ, Freq_312_KHZ, Freq_7812_HZ
 * 			u8Duty_Cycle : Range from 0 to 100
 * Outputs : None
 * Notes :
 */
extern void Timer1_PhaseCorrectPwm( u8 u8Freq , u8 u8Duty_Cycle);


#endif /* PWM_DRV_PWM_INT_H_ */
