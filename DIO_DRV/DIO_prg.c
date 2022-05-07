#include "..\LIB\BIT_MATH.h"
#include "..\LIB\STD_TYPES.h"

#include "DIO_Reg.h"
#include "DIO_Int.h"

/*****************Interfaces*******************/
/****************DIO_SetPinDir*****************/
/*Set Pin Direction*/
void DIO_SetPinDir(u8 Port_ID, u8 Pin_no, u8 Pin_Dir)
{
	/*Check the Port ID and Pin value are valid*/
	if((Port_ID <= PORTD)&&(Pin_no <= PIN_7))
	{
		/*The ID is valid check the Pin Direction*/
		if(Pin_Dir == INPUT)
		{
			/*Configure Pin as Input*/
			switch(Port_ID)
			{
			case PORTA:
				/*Configure the required Pin in PORTA*/
				/* as input in PORTA*/
				CLR_BIT(DDRA_REG,Pin_no);
				break;
			case PORTB:
				/*Configure the required Pin in PORTA*/
				/* as input in PORTB*/
				CLR_BIT(DDRB_REG,Pin_no);
				break;
			case PORTC:
				/*Configure the required Pin in PORTA*/
				/* as input in PORTC*/
				CLR_BIT(DDRC_REG,Pin_no);
				break;
			case PORTD:
				/*Configure the required Pin in PORTA*/
				/* as input in PORTD*/
				CLR_BIT(DDRD_REG,Pin_no);
				break;
			}

		}
		else if(Pin_Dir == OUTPUT)
		{
			/*Configure Pin as Output*/
			/*Configure Pin as Input*/
			switch(Port_ID)
			{
			case PORTA:
				/*Configure the required Pin in PORTA*/
				/* as output in PORTA*/
				SET_BIT(DDRA_REG,Pin_no);
				break;
			case PORTB:
				/*Configure the required Pin in PORTA*/
				/* as output in PORTB*/
				SET_BIT(DDRB_REG,Pin_no);
				break;
			case PORTC:
				/*Configure the required Pin in PORTA*/
				/* as output in PORTC*/
				SET_BIT(DDRC_REG,Pin_no);
				break;
			case PORTD:
				/*Configure the required Pin in PORTA*/
				/* as output in PORTD*/
				SET_BIT(DDRD_REG,Pin_no);
				break;
			}
		}
		else
		{
			/*Do nothing wrong Direction*/
		}
	}
	else
	{
		/*Do nothing Wrong Port ID or Pin no*/
	}
}
/*************End of DIO_SetPinDir**************/

/****************DIO_SetPinVal******************/
/*Set Pin Value*/
void DIO_SetPinVal(u8 Port_ID, u8 Pin_no, u8 Pin_Val)
{
	/*Check the Port ID and Pin value are valid*/
	if((Port_ID <= PORTD)&&(Pin_no <= PIN_7))
	{
		/*Set the Pin value*/
		if(Pin_Val == LOW)
		{
			/*Set The corresponding Pin value to Low*/
			switch(Port_ID)
			{
			case PORTA:
				/*Set the required pin in PortA to low*/
				CLR_BIT(PORTA_REG, Pin_no);
				break;
			case PORTB:
				/*Set the required pin in PortB to low*/
				CLR_BIT(PORTB_REG, Pin_no);
				break;
			case PORTC:
				/*Set the required pin in PortC to low*/
				CLR_BIT(PORTC_REG, Pin_no);
				break;
			case PORTD:
				/*Set the required pin in PortD to low*/
				CLR_BIT(PORTD_REG, Pin_no);
				break;
			}
		}
		else if(Pin_Val == HIGH)
		{
			/*Set The corresponding Pin value to High*/
			switch(Port_ID)
			{
			case PORTA:
				/*Set the required pin in PortA to high*/
				SET_BIT(PORTA_REG, Pin_no);
				break;
			case PORTB:
				/*Set the required pin in PortB to high*/
				SET_BIT(PORTB_REG, Pin_no);
				break;
			case PORTC:
				/*Set the required pin in PortC to high*/
				SET_BIT(PORTC_REG, Pin_no);
				break;
			case PORTD:
				/*Set the required pin in PortD to high*/
				SET_BIT(PORTD_REG, Pin_no);
				break;
			}
		}
		else
		{
			/* DO Nothing Invalid pin value*/
		}
	}
	else
	{
		/*Do nothing wrong Port ID or Pin no*/
	}
}
/**************End of DIO_SetPinVal***************/

/*****************DIO_GetPinVal*******************/
u8 DIO_GetPinVal(u8 Port_ID, u8 Pin_no)
{
	/*Local variable to return the pin value*/
	/*Set the return value to 0xFF in case */
	/*of wrong PORT or PIN*/
	u8 Pin_value=(u8)0xFF;
	/*Check the Port ID and Pin value are valid*/
	if((Port_ID <= PORTD)&&(Pin_no <= PIN_7))
	{
		switch(Port_ID)
		{
		case PORTA:
			/*Get the Pin value from Port A*/
			Pin_value= GET_BIT(PINA_REG, Pin_no);
			break;
		case PORTB:
			/*Get the Pin value from Port B*/
			Pin_value= GET_BIT(PINB_REG, Pin_no);
			break;
		case PORTC:
			/*Get the Pin value from Port C*/
			Pin_value= GET_BIT(PINC_REG, Pin_no);
			break;
		case PORTD:
			/*Get the Pin value from Port D*/
			Pin_value= GET_BIT(PIND_REG, Pin_no);
			break;
		}
	}
	else
	{
		/*Do nothing wrong Port ID or Pin no*/
	}

return Pin_value;
}
/**************End of DIO_GetPinVal***************/

/*****************DIO_SetPortDir******************/
void DIO_SetPortDir(u8 Port_ID, u8 Port_Dir)
{
	/*Check the Port ID and Pin value are valid*/
	if(Port_ID <= PORTD)
	{
		switch(Port_ID)
		{
		case PORTA:
			/*Set whole PortA direction*/
			DDRA_REG= Port_Dir;
			break;
		case PORTB:
			/*Set whole PortB direction*/
			DDRB_REG= Port_Dir;
			break;
		case PORTC:
			/*Set whole PortC direction*/
			DDRC_REG= Port_Dir;
			break;
		case PORTD:
			/*Set whole PortD direction*/
			DDRD_REG= Port_Dir;
			break;
		}
	}
	else
	{
		/*Do nothing wrong Port ID*/
	}
}
/**************End of DIO_SetPortDir************/

/*****************DIO_SetPortVal******************/
void DIO_SetPortVal(u8 Port_ID, u8 Port_val)
{
	/*Check the Port ID and Pin value are valid*/
	if(Port_ID <= PORTD)
	{
		switch(Port_ID)
		{
		case PORTA:
			/*Set whole PortA value*/
			PORTA_REG= Port_val;
			break;
		case PORTB:
			/*Set whole PortB value*/
			PORTB_REG= Port_val;
			break;
		case PORTC:
			/*Set whole PortC value*/
			PORTC_REG= Port_val;
			break;
		case PORTD:
			/*Set whole PortD value*/
			PORTD_REG= Port_val;
			break;
		}
	}
	else
	{
		/*Do nothing wrong Port ID*/
	}
}
/**************End of DIO_SetPortVal************/
