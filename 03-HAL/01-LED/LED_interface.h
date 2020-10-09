/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 17 August 2020                                                    */
/*********************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/* You have to define the pins and its directions before calling any function*/
void LED_voidON		(u8 Copy_u8PortID, u8 Copy_u8Pin);
void LED_voidOFF	(u8 Copy_u8PortID, u8 Copy_u8Pin);
void LED_voidTog	(u8 Copy_u8PortID, u8 Copy_u8INPin, u8 Copy_u8OutPin);
void LED_voidBlink	(u8 Copy_u8PortID, u8 Copy_u8Pin);


#endif