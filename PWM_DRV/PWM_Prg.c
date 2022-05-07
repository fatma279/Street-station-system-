/*
 * PWM_Prg.c
 *
 *  Created on: Oct 6, 2018
 *      Author: Mohamed
 */


/*
 * PWM_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmad
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO_DRV/DIO_Int.h"
#include "../PWM_DRV/PWM_cfg.h"
#include "../PWM_DRV/PWM_Int.h"

/*
 * Function Timer0_FastPwm for PWM signal
 * Inputs : u8Freq : Freq_8_MHZ , Freq_1_MHZ, Freq_125_KHZ, Freq_312_KHZ, Freq_7812_HZ
 * 			u8Duty_Cycle : Range from 0 to 100
 * Outputs : None
 * Notes :
 */
extern void Timer1_FastPwm( u8 u8Freq , u8 u8Duty_Cycle)
{	
	u16 u16Calc_Duty_Cycle;
	/*Calculate the duty cycle convert from (0 to 100) to be (from 0 to 255)*/
	u16Calc_Duty_Cycle=(u8Duty_Cycle*255)/100;
	/* Set the Output Compare Register with required value*/
	/*Set the OCR1A & OCR1B register */
	OCR1A=u16Calc_Duty_Cycle;
	OCR1B=u16Calc_Duty_Cycle;

	/* Turn On the timer with the prescaling that the user entered*/
	/* if the user enters a wrong value it will be automatically set to no prescaling*/
	switch(u8Freq)
	{
	/*Prescaling values depend on bits CS12:CS11:CS10 in register TCCR1B */
/*	 CS12:CS11:CS10
	  0    0    0  : No clock source -> Stopped
	  0    0    1  : clk(No prescaling)
	  0    1    0  : clk/8
	  0    1    1  : clk/64
	  1    0    0  : clk/256
	  1    0    1  : clk/1024*/

	case Freq_8_MHZ:
		/*Request no Prescale*/
	    /*CS12:CS11:CS10*/
		/*0    0    1  : clk(No prescaling)*/
		SET_BIT(TCCR1B, 0);
		CLR_BIT(TCCR1B, 1);
		CLR_BIT(TCCR1B, 2);
		break;
	case Freq_1_MHZ:
	    /*CS12:CS11:CS10*/
		/*0    1    0  : clk/8*/
		CLR_BIT(TCCR1B, 0);
		SET_BIT(TCCR1B, 1);
		CLR_BIT(TCCR1B, 2);
		break;
	case Freq_125_KHZ:
	    /*CS12:CS11:CS10*/
		 /*0    1    1  : clk/64*/
		SET_BIT(TCCR1B, 0);
		SET_BIT(TCCR1B, 1);
		CLR_BIT(TCCR1B, 2);
		break;
	case Freq_312_KHZ:
	    /*CS12:CS11:CS10*/
		/*1    0    0  : clk/256*/
		CLR_BIT(TCCR1B, 0);
		CLR_BIT(TCCR1B, 1);
		SET_BIT(TCCR1B, 2);
		break;
	case Freq_7812_HZ:
	    /*CS12:CS11:CS10*/
		 /*1    0    1  : clk/1024*/
		SET_BIT(TCCR1B, 0);
		CLR_BIT(TCCR1B, 1);
		SET_BIT(TCCR1B, 2);
		break;
	default:
	    /*CS12:CS11:CS10*/
		/*0    0    1  : clk(No prescaling)*/
		SET_BIT(TCCR1B, 0);
		CLR_BIT(TCCR1B, 1);
		CLR_BIT(TCCR1B, 2);
		break;
	}
//	/*TCCR1A &TCCR1B Register configuration */
	/*Select the timer mode to be FAST PWM by setting bits WGM11 to 0 and WGM10 to 1 in register TCCR1A*/
	/*Select the timer mode to be FAST PWM by setting bits WGM13 to 0 and WGM12 to 1 in register TCCR1B*/
	/*Set Bit WGM10(Bit 0) to 1*/
	SET_BIT(TCCR1A, 0);
	/*Set Bit WGM11 (Bit1) to 1*/
	CLR_BIT(TCCR1A, 1);
	/*Set Bit WGM12(Bit 3) to 1*/
	SET_BIT(TCCR1B, 3);
	/*Set Bit WGM13 (Bit1) to 1*/
	CLR_BIT(TCCR1B, 4);
	/*Select the Port mode to be Clear OC1A & OC1B on compare match       */
	/* by setting bits COM1A1 to 1 and COM1A0 to 0 and COM1B1 to 1 and COM1B0 to 0 in register TCCR1A*/
	/*SET Bit COM1A1(Bit 7)*/
	SET_BIT(TCCR1A, 7);
	/*CLR Bit COM1A0(Bit 6) to 1*/
	CLR_BIT(TCCR1A, 6);
	/*SET Bit COM1B1(Bit 5)*/
	SET_BIT(TCCR1A, 5);
	/*CLR Bit COM1B0(Bit 4) to 1*/
	CLR_BIT(TCCR1A, 4);

	/*Force output compare not used Clear bit3 and bit 2 FOC1A & FOC1B*/
	CLR_BIT(TCCR1A, 3);
	CLR_BIT(TCCR1A, 2);

	/*Set the OC1B pin as output OC1B -> PD4*/
	/*Set the OC1A pin as output OC1A -> PD5*/
	/*Add your code here*/

	DIO_SetPinDir(PORTD,PIN_4, OUTPUT);
	DIO_SetPinDir(PORTD,PIN_5, OUTPUT);


}

/*
 * Function Timer0_PhaseCorrectPwm for PWM signal
 * Inputs : u8Freq : Freq_8_MHZ , Freq_1_MHZ, Freq_125_KHZ, Freq_312_KHZ, Freq_7812_HZ
 * 			u8Duty_Cycle : Range from 0 to 100
 * Outputs : None
 * Notes :
 */
extern void Timer1_PhaseCorrectPwm( u8 u8Freq , u8 u8Duty_Cycle)
{
	/* Set the Output Compare Register with required value*/
	u16 u16Calc_Duty_Cycle;
	/*Calculate the duty cycle convert from (0 to 100) to be (from 0 to 255)*/
	u16Calc_Duty_Cycle=(u8Duty_Cycle*255)/100;
	/* Set the Output Compare Register with required value*/
	/*Set the OCR1A & OCR1B register */
	OCR1A=u16Calc_Duty_Cycle;
	OCR1B=u16Calc_Duty_Cycle;
	/* Turn On the timer with the prescaling that the user entered*/
	/* if the user enters a wrong value it will be automatically set to no prescaling*/
	switch(u8Freq)
	{
	/*Prescaling values depend on bits CS12:CS11:CS10 in register TCCR1B */
/*	 CS12:CS11:CS10
	  0    0    0  : No clock source -> Stopped
	  0    0    1  : clk(No prescaling)
	  0    1    0  : clk/8
	  0    1    1  : clk/64
	  1    0    0  : clk/256
	  1    0    1  : clk/1024*/

	case Freq_8_MHZ:
		/*Request no Prescale*/
	    /*CS12:CS11:CS10*/
		/*0    0    1  : clk(No prescaling)*/
		SET_BIT(TCCR1B, 0);
		CLR_BIT(TCCR1B, 1);
		CLR_BIT(TCCR1B, 2);
		break;
	case Freq_1_MHZ:
	    /*CS12:CS11:CS10*/
		/*0    1    0  : clk/8*/
		CLR_BIT(TCCR1B, 0);
		SET_BIT(TCCR1B, 1);
		CLR_BIT(TCCR1B, 2);
		break;
	case Freq_125_KHZ:
	    /*CS12:CS11:CS10*/
		 /*0    1    1  : clk/64*/
		SET_BIT(TCCR1B, 0);
		SET_BIT(TCCR1B, 1);
		CLR_BIT(TCCR1B, 2);
		break;
	case Freq_312_KHZ:
	    /*CS12:CS11:CS10*/
		/*1    0    0  : clk/256*/
		CLR_BIT(TCCR1B, 0);
		CLR_BIT(TCCR1B, 1);
		SET_BIT(TCCR1B, 2);
		break;
	case Freq_7812_HZ:
	    /*CS12:CS11:CS10*/
		 /*1    0    1  : clk/1024*/
		SET_BIT(TCCR1B, 0);
		CLR_BIT(TCCR1B, 1);
		SET_BIT(TCCR1B, 2);
		break;
	default:
	    /*CS12:CS11:CS10*/
		/*0    0    1  : clk(No prescaling)*/
		SET_BIT(TCCR1B, 0);
		CLR_BIT(TCCR1B, 1);
		CLR_BIT(TCCR1B, 2);
		break;
	}
	//	/*TCCR1A &TCCR1B Register configuration */
		/*Select the timer mode to be Phase Correct PWM by setting bits WGM11 to 0 and WGM10 to 1 in register TCCR1A*/
		/*Select the timer mode to be Phase Correct  PWM by setting bits WGM13 to 0 and WGM12 to 1 in register TCCR1B*/
		/*Set Bit WGM10(Bit 0) to 1*/
		SET_BIT(TCCR1A, 0);
		/*Set Bit WGM11 (Bit1) to 1*/
		CLR_BIT(TCCR1A, 1);
		/*Set Bit WGM12(Bit 3) to 1*/
		CLR_BIT(TCCR1B, 3);
		/*Set Bit WGM13 (Bit1) to 1*/
		CLR_BIT(TCCR1B, 4);
		/*Select the Port mode to be Clear OC1A & OC1B on compare match       */
		/* by setting bits COM1A1 to 1 and COM1A0 to 0 and COM1B1 to 1 and COM1B0 to 0 in register TCCR1A*/
		/*SET Bit COM1A1(Bit 7)*/
		SET_BIT(TCCR1A, 7);
		/*CLR Bit COM1A0(Bit 6) to 1*/
		CLR_BIT(TCCR1A, 6);
		/*SET Bit COM1B1(Bit 5)*/
		SET_BIT(TCCR1A, 5);
		/*CLR Bit COM1B0(Bit 4) to 1*/
		CLR_BIT(TCCR1A, 4);

		/*Force output compare not used Clear bit3 and bit 2 FOC1A & FOC1B*/
		CLR_BIT(TCCR1A, 3);
		CLR_BIT(TCCR1A, 2);

		/*Set the OC1B pin as output OC1B -> PD4*/
		/*Set the OC1A pin as output OC1A -> PD5*/
		/*Add your code here*/

		DIO_SetPinDir(PORTD,PIN_4, OUTPUT);
		DIO_SetPinDir(PORTD,PIN_5, OUTPUT);

}
