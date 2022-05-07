/*
 * Timer_Prg.c
 *
 *  Created on: Oct 6, 2018
 *      Author: Mohamed
 */

/*
 * Timers_Driver.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ahmad
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO_DRV/DIO_Int.h"
#include "Timer_Int.h"
#include "Timer_cfg.h"

/* defines the ISR for timer0 compare match vector table interrupt 10*/
#define __INTR_ATTRS used, externally_visible
void __vector_10 (void) __attribute__((interrupt,__INTR_ATTRS));

/* defines the ISR for timer0 overflow vector table interrupt 11*/
#define __INTR_ATTRS used, externally_visible
void __vector_11 (void) __attribute__((interrupt,__INTR_ATTRS));


/*a delay counter*/
volatile u16 Delay_Counter=0;
/*a pointer to function for timer0 compare match interrupt*/
void (*CallBackPointer_Timer0)(void);

/* timer 0 compare match interrupt*/
void __vector_10 (void)
{

	/*timer0 compare match interrupt callback*/
	/*Add your code here*/
	CallBackPointer_Timer0();

}

/*timer 0 overflow interrupt*/
void __vector_11 (void)//
{
	/*timer0 overflow interrupt callback*/
	/*Add your code here*/
}
/*a function to set the callback pointer for compare match timer0 interrupt*/
extern void Set_Call_Back_Timer0(void (*Input_Function)(void))
{
	/*Set the callback pointer to the input function*/
	/*Add your code here*/
	CallBackPointer_Timer0=Input_Function;
}


/*
 * Function Timer0_InternalClock_Normal_Init for OVF timer
 * Inputs : Interrupt : ON , OFF
 * 			Prescaler : Prescale_1 , Prescale_8 , Prescale_64 , Prescale_256 , Prescale_1024
 * Outputs : None
 * Notes :
 */
extern void Timer0_InternalClock_Normal_Init(u8 Timer0_Interrupt, u16 Timer0_Prescaler)
{
	/*Check if the timer interrupt is requested to be ON*/
	if(Timer0_Interrupt == ON)
	{
		/*Enable the OVF interrupt*/
		/*Set Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable to 1 in register TIMSK*/
		/*Add your code here*/
		SET_BIT(TIMSK,0);
		/*Set the Global interrupt to enable by Setting Bit 7 in SREG to 1*/
		/*Add your code here*/
		SET_BIT(SREG,7);
	}
	else
	{
		/*if the user chooses to turn off interrupt clear the interrupt Enable bit*/
		/*Clear Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable in register TIMSK*/
		/*Add your code here*/
		CLR_BIT(TIMSK,0);
	}

	/* Turn On the timer with the prescaling that the user entered*/
	/* if the user enters a wrong value it will be automatically set to no prescaling*/
	switch(Timer0_Prescaler)
	{
	/*Prescaling values depend on bits CS02:CS01:CS00 in register TCCR0*/
/*	 CS02:CS01:CS00
	  0    0    0  : No clock source -> Stopped
	  0    0    1  : clk(No prescaling)
	  0    1    0  : clk/8
	  0    1    1  : clk/64
	  1    0    0  : clk/256
	  1    0    1  : clk/1024*/

	case Prescale_1:
		/*Request no Prescale*/
	    /*CS02:CS01:CS00*/
		/*0    0    1  : clk(No prescaling)*/
		/*Add your code here*/
			SET_BIT(TCCR0,0);
			/*Add your code here*/
			CLR_BIT(TCCR0,1);
			/*Add your code here*/
			CLR_BIT(TCCR0,2);
		break;
	case Prescale_8:
	    /*CS02:CS01:CS00*/
		/*0    1    0  : clk/8*/
		/*Add your code here*/
		CLR_BIT(TCCR0,0);
		/*Add your code here*/
		SET_BIT(TCCR0,1);
		/*Add your code here*/
		CLR_BIT(TCCR0,2);
		break;
	case Prescale_64:
	    /*CS02:CS01:CS00*/
		 /*0    1    1  : clk/64*/
		/*Add your code here*/
		SET_BIT(TCCR0,0);
		/*Add your code here*/
		SET_BIT(TCCR0,1);
		/*Add your code here*/
		CLR_BIT(TCCR0,2);
		break;
	case Prescale_256:
	    /*CS02:CS01:CS00*/
		/*1    0    0  : clk/256*/
		CLR_BIT(TCCR0,0);
		/*Add your code here*/
		CLR_BIT(TCCR0,1);
		/*Add your code here*/
		SET_BIT(TCCR0,2);
		break;
	case Prescale_1024:
	    /*CS02:CS01:CS00*/
		 /*1    0    1  : clk/1024*/
		SET_BIT(TCCR0,0);
		/*Add your code here*/
		CLR_BIT(TCCR0,1);
		/*Add your code here*/
		SET_BIT(TCCR0,2);
		break;
	default:
	    /*CS02:CS01:CS00*/
		/*0    0    1  : clk(No prescaling)*/
		SET_BIT(TCCR0,0);
		/*Add your code here*/
		CLR_BIT(TCCR0,1);
		/*Add your code here*/
		CLR_BIT(TCCR0,2);
		break;
	}
	/*TCCR0 Register configuration */
	/*Select the timer mode to be Normal by setting bits WGM01 and WGM00 to 0 in register TCCR0*/
	/*Clear Bit WGM01(Bit 3)*/
	/*Add your code here*/
	CLR_BIT(TCCR0,3);
	/*Clear Bit WGM00 (Bit6)*/
	/*Add your code here*/
	CLR_BIT(TCCR0,6);
	/*Select the Port mode to be Normal(Normal port operation, OC0 disconnected.)*/
	/* by setting bits COM00 and COM01 to 0 in register TCCR0*/
	/*Clear Bit COM00(Bit 4)*/
	/*Add your code here*/
	CLR_BIT(TCCR0,4);
	/*Clear Bit COM01(Bit 5)*/
	/*Add your code here*/
	CLR_BIT(TCCR0,5);
	/*Force output compare not used Clear bit7 FOC0*/
	/*Add your code here*/
	CLR_BIT(TCCR0,7);
}

/*
 * Function Timer0_InternalClock_CTC_Init for CTC
 * Inputs : Interrupt : ON , OFF
 * 			Prescaler : Prescale_1 , Prescale_8 , Prescale_64 , Prescale_256 , Prescale_1024
 * 			Output_Compare : 0 to 255 compare value
 * Outputs : None
 * Notes :
 */

extern void Timer0_InternalClock_CTC_Init(u8 Timer0_Interrupt, u16 Timer0_Prescaler , u8 Output_Compare)
{

	/* Set the Output Compare Register with required value*/
	/*Add your code here*/
	OCR0=125;

	/*Check if the timer interrupt is requested to be ON*/
	if(Timer0_Interrupt == ON)
	{
		/*Enable the CTC interrupt*/
		/*Set Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable to 1 in register TIMSK*/
		/*Add your code here*/
		SET_BIT(TIMSK,1);
		/*Set the Global interrupt to enable by Setting Bit 7 in SREG to 1*/
		/*Add your code here*/
		SET_BIT(SREG,7);

	}
	else
	{
		/*Disable the CTC interrupt*/
		/*Clear Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable to 0 in register TIMSK*/
		/*Add your code here*/
		CLR_BIT(TIMSK,1);
	}
	/* Turn On the timer with the prescaling that the user entered*/
	/* if the user enters a wrong value it will be automatically set to no prescaling*/
	switch(Timer0_Prescaler)
	{
	/*Prescaling values depend on bits CS02:CS01:CS00 in register TCCR0*/
/*	 CS02:CS01:CS00
	  0    0    0  : No clock source -> Stopped
	  0    0    1  : clk(No prescaling)
	  0    1    0  : clk/8
	  0    1    1  : clk/64
	  1    0    0  : clk/256
	  1    0    1  : clk/1024*/

	case Prescale_1:
		/*Request no Prescale*/
	    /*CS02:CS01:CS00*/
		/*0    0    1  : clk(No prescaling)*/
		/*Add your code here*/
			SET_BIT(TCCR0,0);
			/*Add your code here*/
			CLR_BIT(TCCR0,1);
			/*Add your code here*/
			CLR_BIT(TCCR0,2);
		break;
	case Prescale_8:
	    /*CS02:CS01:CS00*/
		/*0    1    0  : clk/8*/
		/*Add your code here*/
		CLR_BIT(TCCR0,0);
		/*Add your code here*/
		SET_BIT(TCCR0,1);
		/*Add your code here*/
		CLR_BIT(TCCR0,2);
		break;
	case Prescale_64:
	    /*CS02:CS01:CS00*/
		 /*0    1    1  : clk/64*/
		/*Add your code here*/
		SET_BIT(TCCR0,0);
		/*Add your code here*/
		SET_BIT(TCCR0,1);
		/*Add your code here*/
		CLR_BIT(TCCR0,2);
		break;
	case Prescale_256:
	    /*CS02:CS01:CS00*/
		/*1    0    0  : clk/256*/
		CLR_BIT(TCCR0,0);
		/*Add your code here*/
		CLR_BIT(TCCR0,1);
		/*Add your code here*/
		SET_BIT(TCCR0,2);
		break;
	case Prescale_1024:
	    /*CS02:CS01:CS00*/
		 /*1    0    1  : clk/1024*/
		SET_BIT(TCCR0,0);
		/*Add your code here*/
		CLR_BIT(TCCR0,1);
		/*Add your code here*/
		SET_BIT(TCCR0,2);
		break;
	default:
	    /*CS02:CS01:CS00*/
		/*0    0    1  : clk(No prescaling)*/
		SET_BIT(TCCR0,0);
		/*Add your code here*/
		CLR_BIT(TCCR0,1);
		/*Add your code here*/
		CLR_BIT(TCCR0,2);
		break;
	}
	/*TCCR0 Register configuration */
	/*Select the timer mode to be CTC by setting bits WGM01 to 1 and WGM00 to 0 in register TCCR0*/
	/*Set Bit WGM01(Bit 3) to 1*/
	/*Add your code here*/
	SET_BIT(TCCR0,3);
	/*Clear Bit WGM00 (Bit6)*/
	/*Add your code here*/
	CLR_BIT(TCCR0,6);
	/*Select the Port mode to be Normal(Normal port operation, OC0 disconnected.)*/
	/* by setting bits COM00 and COM01 to 0 in register TCCR0*/
	/*Clear Bit COM00(Bit 4)*/
	/*Add your code here*/
	CLR_BIT(TCCR0,4);
	/*Clear Bit COM01(Bit 5)*/
	/*Add your code here*/
	CLR_BIT(TCCR0,5);
	/*Force output compare not used Clear bit7 FOC0*/
	/*Add your code here*/
	CLR_BIT(TCCR0,7);

}

/* Private a function that increments the counter whenever an interrupt happens*/
void delay_Counter ()
{
	/*Increment the Delay counter 1 each time*/
	Delay_Counter++;
}
/*Function used to delay the CTC timer in ms*/
extern void Timer0_CTC_delay_ms(u16 delay_time_ms)
{
	/*Initialize the delay counter by 0*/
	Delay_Counter=0;


	/*Initialize the CTC timer to count up to 1ms using Sys clock is 8MHZ*/
	/*Add your code here*/
	Timer0_InternalClock_CTC_Init(ON,Prescale_64,125);
	
	/*Set the call back for timer 0 by delay_counter function to*/
	/*increment delay counter*/
	/*Add your code here*/
	Set_Call_Back_Timer0(delay_Counter);

	/*Check if the delay counter reach to delay user sent*/
	while(Delay_Counter < delay_time_ms);

}

/*Function used to delay the Normal timer in ms*/
extern void Timer0_Normal_delay_ms(u16 delay_time_ms)
{
	/*Initialize the delay counter by 0*/
	Delay_Counter=0;

	/*Initialize the CTC timer to count up to 2ms using Sys clock is 8MHZ*/
	/*Add your code here*/
	Timer0_InternalClock_Normal_Init(ON,Prescale_64);

	/*Set the call back for timer 0 by delay_counter function to*/
	/*increment delay counter*/
	/*Add your code here*/
	Set_Call_Back_Timer0(delay_Counter);
	
	/*Check if the delay counter reach to delay user sent*/
	/*Add your code here*/
	while(Delay_Counter < 4*delay_time_ms)
	{

	}
}
