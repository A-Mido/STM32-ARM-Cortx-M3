/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 14 August 2020                                                    */
/*********************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* Ports definitions*/
#define GPIOA		0
#define GPIOB		1
#define GPIOC		2

/* Half port*/
#define LOW_HALF		0
#define HIGH_HALF		1

/* Pins definitions */
#define PIN0 		0
#define PIN1 		1
#define PIN2 		2
#define PIN3 		3
#define PIN4 		4
#define PIN5 		5
#define PIN6 		6
#define PIN7 		7
#define PIN8 		8
#define PIN9 		9
#define PIN10 		10
#define PIN11 		11
#define PIN12 		12
#define PIN13 		13
#define PIN14 		14
#define PIN15 		15

/* Output values*/
#define HIGH	1
#define LOW	0

/* Input Modes*/
#define INPUT_ANALOG				0b0000
#define INPUT_FLOATING				0b0100
#define INPUT_PULL_UD				0b1000

/* Output Modes of 10MHZ */
#define OUTPUT_SPEED_10MHZ_PP		0b0001
#define OUTPUT_SPEED_10MHZ_OD		0b0101
#define OUTPUT_SPEED_10MHZ_AFPP		0b1001
#define OUTPUT_SPEED_10MHZ_AFOD		0b1101

/* Output Modes of 2MHZ */
#define OUTPUT_SPEED_2MHZ_PP		0b0010
#define OUTPUT_SPEED_2MHZ_OD		0b0110
#define OUTPUT_SPEED_2MHZ_AFPP		0b1010
#define OUTPUT_SPEED_2MHZ_AFOD		0b1110

/* Output Modes of 50MHZ */
#define OUTPUT_SPEED_50MHZ_PP		0b0011
#define OUTPUT_SPEED_50MHZ_OD		0b0111
#define OUTPUT_SPEED_50MHZ_AFPP		0b1011
#define OUTPUT_SPEED_50MHZ_AFOD		0b1111


void MGPIO_voidSetPinDirection		(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8MODE);
void MGPIO_voidSetPortDirection 	(u8 Copy_u8PORT, u8 Copy_u8MODE);
void MGPIO_voidSetHalfPortDirection (u8 Copy_u8PORT, u8 Copy_u8HALF, u8 Copy_u8MODE);
void MGPIO_voidSetPinValue	  		(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8VALUE);
void MGPIO_voidSetPortValue			(u8 Copy_u8PORT, u8 Copy_u8VALUE);
void MGPIO_voidSetHalfPortValue		(u8 Copy_u8PORT, u8 Copy_u8HALF,u8 Copy_u8VALUE);
void MGPIO_voidLockPinConfig		(u8 Copy_u8PORT, u8 Copy_u8PIN);
u8	 MGPIO_u8GetPinValue	 		(u8 Copy_u8PORT, u8 Copy_u8PIN);



#endif