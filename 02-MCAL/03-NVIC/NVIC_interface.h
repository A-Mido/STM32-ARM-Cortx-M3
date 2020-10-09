/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 20 August 2020                                                    */
/*********************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define MNVIC_GROUP_4_SUB_0 	0x05FA0300 	// 4 bits for group priority and 0 for sub-priority
#define MNVIC_GROUP_3_SUB_1		0x05FA0400	// 3 bits for group priority and 1 for sub-priority
#define MNVIC_GROUP_2_SUB_2		0x05FA0500	// 2 bits for group priority and 2 for sub-priority
#define MNVIC_GROUP_1_SUB_3		0x05FA0600	// 1 bits for group priority and 3 for sub-priority
#define MNVIC_GROUP_0_SUB_4		0x05FA0700	// 0 bits for group priority and 4 for sub-priority

void MNVIC_voidInit(void);
void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag  (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority	   (u8 Copy_s8PerIndex, u8 Copy_u8Priority);
u8 	 MNVIC_u8GetActiveFlag	   (u8 Copy_u8IntNumber);

#endif