/***************************************************/
/* Author  : fatma                                 */
/* Date    : 2 august 2021                         */
/* version : V01                                   */
/***************************************************/

#include "..\LIB\BIT_MATH.h"
#include "..\LIB\STD_TYPES.h"
#include "..\DIO_DRV\DIO_Int.h"
#include "..\TIMER_DRV\Timer_Int.h"
#include "7SEG_cfg.h"
#include "7SEG_INT.h"


/* Display 7-segment from 0 to 9 */
void SevenSeg_voidSevenDisplay(u8 SEG_PORT)
{
if (SEG_TYPE == SEG_COMMON_ANOD)
{
for(int i=0;i<10;i++)
		{
	DIO_SetPortVal(SEG_PORT, ANOD_SEG[i]);
			 //delay 800ms
	Timer0_CTC_delay_ms(1000);

		}
}
else if(SEG_TYPE == SEG_COMMON_CATHOD)
{

for(u8 i=0;i<10;i++)
		{
	DIO_SetPortVal(SEG_PORT, CATHOD_SEG[i]);

			 //delay 800ms
	Timer0_CTC_delay_ms(1000);

		}

}
}

/* Display specific number on 7-segment */
void SevenSeg_voidSevenDisplayNumber(u8 SEG_PORT, u8 Copy_u8Number ){
	if (SEG_TYPE == SEG_COMMON_ANOD)
	{
	for(u8 i=0;i<10;i++)
	{
		if (Copy_u8Number==i)
			DIO_SetPortVal(SEG_PORT, ANOD_SEG[i]);
	}
}
	else if (SEG_TYPE == SEG_COMMON_CATHOD)
	{
	for(u8 i=0;i<10;i++)
	{
		if (Copy_u8Number==i)
			DIO_SetPortVal(SEG_PORT, CATHOD_SEG[i]);

	}
}
}


void SevenSeg_voidTwoSevenDisplay(u8 SEG1_PORT,u8 SEG2_PORT,u8 Timing)
{
	u8 counter=Timing/10;
	if (SEG_TYPE == SEG_COMMON_ANOD)
	{
		  for(u8 j=0;j<=counter; j++)
		  {

		  DIO_SetPortVal(SEG2_PORT, ANOD_SEG[j]);

		  if(j==counter)
		  {
			  DIO_SetPortVal(SEG1_PORT, ANOD_SEG[0]);
			  Timer0_CTC_delay_ms(1000);
			  break;
		  }

			for(u8 i=0;i<10;i++)
					{
				DIO_SetPortVal(SEG1_PORT, ANOD_SEG[i]);

						 //delay 1s
				Timer0_CTC_delay_ms(1000);

					}
		  }
	}
	else if(SEG_TYPE == SEG_COMMON_CATHOD)
	{
  for(u8 j=0;j<=counter; j++)
  {

  DIO_SetPortVal(SEG2_PORT, CATHOD_SEG[j]);

  if(j==counter)
  {
	  DIO_SetPortVal(SEG1_PORT, CATHOD_SEG[0]);
	  Timer0_CTC_delay_ms(1000);
	  break;
  }

	for(u8 i=0;i<10;i++)
			{
		DIO_SetPortVal(SEG1_PORT, CATHOD_SEG[i]);

				 //delay 1s
		Timer0_CTC_delay_ms(1000);

			}
  }

	}
}
