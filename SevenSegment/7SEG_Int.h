/***************************************************/
/* Author  : fatma                                 */
/* Date    : 2 august 2021                      */
/* version : V01                                   */
/***************************************************/

 #ifndef SEG_INTERFACE_H
 #define SEG_INTERFACE_H




         /* Display 7-segment from 0 to 9 */
void SevenSeg_voidSevenDisplay(u8 SEG_PORT);
     
         /* Display specific number on 7-segment */
void SevenSeg_voidSevenDisplayNumber(u8 SEG_PORT, u8 Copy_u8Number);

         /* Display Tow 7-segment */
void SevenSeg_voidTwoSevenDisplay(u8 SEG1_PORT,u8 SEG2_PORT,u8 Timing);

 #endif
 
