#include "util/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO_DRV/DIO_Int.h"
#include "../SevenSegment/7SEG_Int.h"
#include "../TIMER_DRV/Timer_Int.h"
#include "../PWM_DRV/PWM_Int.h"


void main(void)
{
	DIO_SetPortDir(PORTD, 0xff);
	DIO_SetPortDir(PORTC, 0xff);
	DIO_SetPortDir(PORTA, 0xff);
	DIO_SetPortDir(PORTB, 0xff);


	while(1)
	{
		//turn the Green LED on for 60 seconds PINA0 for green led
		DIO_SetPinVal(PORTA, PIN_0, HIGH);

		//Display 60 on seven segment
		SevenSeg_voidTwoSevenDisplay(PORTB,PORTC,60);

		//turn green led off
		DIO_SetPinVal(PORTA, PIN_0, LOW);





		/*turn the yellow LED for 10 seconds and the gate start closing slowly
		  while the buzzer is giving a beep PINA1 for yellow led*/
		DIO_SetPinVal(PORTA, PIN_1, HIGH);

		// turn on PINA3 for BUZZER
		DIO_SetPinVal(PORTA, PIN_3, HIGH);

		//open the gate(rotate the motor in clockwise)
		Timer1_FastPwm( 1 , 30);
		//those two pins for control the directions
		DIO_SetPinVal(PORTA, PIN_4, HIGH);
		DIO_SetPinVal(PORTA, PIN_5, LOW);

		//Display 10 second on seven segment
		SevenSeg_voidTwoSevenDisplay(PORTB,PORTC,10);

		//turn yellow led off
		DIO_SetPinVal(PORTA, PIN_1, LOW);

		//turn off the buzzer
		DIO_SetPinVal(PORTA, PIN_3, LOW);

		//stop the gate
		DIO_SetPinVal(PORTA, PIN_4, LOW);
		DIO_SetPinVal(PORTA, PIN_5, LOW);





		//turn on the Red LED for 60 seconds PIN2 for red led
		DIO_SetPinVal(PORTA, PIN_2, HIGH);

		//Display 60 second on seven segment
		SevenSeg_voidTwoSevenDisplay(PORTB,PORTC,60);

		//turn off the Red LED
		DIO_SetPinVal(PORTA, PIN_2, LOW);






		/*turn the yellow LED for 10 seconds and the gate start opening slowly
		  while the buzzer is giving a beep PINA1 for yellow led*/
		DIO_SetPinVal(PORTA, PIN_1, HIGH);

		// turn on PINA3 for BUZZER
		DIO_SetPinVal(PORTA, PIN_3, HIGH);

		//open the gate(rotate the motor in anti clockwise)
		Timer1_FastPwm( 1 , 30);
		//those two pins for control the directions
		DIO_SetPinVal(PORTA, PIN_4, LOW);
		DIO_SetPinVal(PORTA, PIN_5, HIGH);

		//Display 10 second on seven segment
		SevenSeg_voidTwoSevenDisplay(PORTD,PORTC,10);

		//turn yellow led off
		DIO_SetPinVal(PORTA, PIN_1, LOW);

		//turn off the buzzer
		DIO_SetPinVal(PORTA, PIN_3, LOW);

		//stop the gate
		DIO_SetPinVal(PORTA, PIN_4, LOW);
		DIO_SetPinVal(PORTA, PIN_5, LOW);


	}
}
