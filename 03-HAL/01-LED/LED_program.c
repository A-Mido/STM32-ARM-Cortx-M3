/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 17 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"




void LED_voidON(u8 Copy_u8PortID, u8 Copy_u8Pin)
{
	MGPIO_voidSetPinValue(Copy_u8PortID, Copy_u8Pin, HIGH);
}

void LED_voidOFF(u8 Copy_u8PortID, u8 Copy_u8Pin)
{
	MGPIO_voidSetPinValue(Copy_u8PortID, Copy_u8Pin, LOW);
}

void LED_voidTog(u8 Copy_u8PortID, u8 Copy_u8INPin, u8 Copy_u8OutPin)
{
	
	u8 Button = MGPIO_u8GetPinValue(Copy_u8PortID, Copy_u8INPin);
	
	for (u8 i = 0; i < 50; i++)
	{
		for (u8 j = 0; j < 50; j++)
		{
			asm("NOP");
		}
	}
	
	if (Button == 0)
	{
		MGPIO_voidSetPinValue(Copy_u8PortID, Copy_u8OutPin, HIGH);
	}
	else
	{
		MGPIO_voidSetPinValue(Copy_u8PortID, Copy_u8OutPin, LOW);
	}
}

void LED_voidBlink(u8 Copy_u8PortID, u8 Copy_u8Pin)
{
	
	MGPIO_voidSetPinValue(Copy_u8PortID, Copy_u8Pin, HIGH);
	for (u16 i = 0; i < 500; i++)
	{
		for (u16 j = 0; j < 500; j++)
		{
			asm("NOP");
		}
	}
	MGPIO_voidSetPinValue(Copy_u8PortID, Copy_u8Pin, LOW);
	for (u16 i = 0; i < 500; i++)
	{
		for (u16 j = 0; j < 500; j++)
		{
			asm("NOP");
		}
	}	
}