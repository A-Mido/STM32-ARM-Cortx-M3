/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 16 August 2020                                                    */
/*********************************************************************************/

#ifndef SEVENSEG_INTERFACE_H
#define SEVENSEG_INTERFACE_H

#define COMMON_CATHODE 0
#define COMMON_ANODE   1

/* You have to define the port or half port direction before using this function*/
void _7SEGMENT_voidWriteNum(u8 Copy_u8MODE, u8 Copy_u8PORT, u8 Copy_u8HALF, u8 Copy_u8VALUE);

#endif