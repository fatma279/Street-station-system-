/*
 * DIO_Int.h
 *
 *  Created on: Sep 14, 2018
 *      Author: Mohamed
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_
/****************Definitions*******************/
/*Port ID's*/
#define PORTA              (u8)0
#define PORTB              (u8)1
#define PORTC              (u8)2
#define PORTD              (u8)3
/*Pin numbers*/
#define PIN_0              (u8)0
#define PIN_1              (u8)1
#define PIN_2              (u8)2
#define PIN_3              (u8)3
#define PIN_4              (u8)4
#define PIN_5              (u8)5
#define PIN_6              (u8)6
#define PIN_7              (u8)7
/*Pin directions*/
#define INPUT              (u8)0
#define OUTPUT             (u8)1
/*Pin values*/
#define HIGH               (u8)1
#define LOW                (u8)0
/*****************Interfaces*******************/
/*Set Pin Direction*/
void DIO_SetPinDir(u8 Port_ID, u8 Pin_no, u8 Pin_Dir);
/*Set Pin Value*/
void DIO_SetPinVal(u8 Port_ID, u8 Pin_no, u8 Pin_Val);
/*Get Pin Value*/
u8 DIO_GetPinVal(u8 Port_ID, u8 Pin_no);
/*Set PORT Direction*/
void DIO_SetPortDir(u8 Port_ID, u8 Port_Dir);
/*Set PORT Value*/
void DIO_SetPortVal(u8 Port_ID, u8 Port_val);
#endif /* DIO_INT_H_ */
