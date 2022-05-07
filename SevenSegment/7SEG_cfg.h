/***************************************************/
/* Author  : fatma                                 */
/* Date    : 2 august 2021                       */
/* version : V01                                   */
/***************************************************/

 #ifndef SEG_CONFIG_H
 #define SEG_CONFIG_H
 
/*   7SEGMENT type   */
#define SEG_COMMON_CATHOD    0
#define SEG_COMMON_ANOD      1

/* Options for 7SEGMENT type:     SEG_COMMON_ANOD 
				                  SEG_COMMON_CATHOD     */
#define SEG_TYPE  SEG_COMMON_CATHOD


             /* 7SEGMENT type = SEG_COMMON_ANOD*/
u8 ANOD_SEG[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};


              /* 7SEGMENT type = SEG_COMMON_CATHOD*/
u8 CATHOD_SEG[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

 #endif
