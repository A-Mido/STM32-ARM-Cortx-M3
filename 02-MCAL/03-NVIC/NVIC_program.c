/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 20 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		//SET_BIT(NVIC_ISER0, Copy_u8IntNumber);
		/* zero in this reg has no effect so to make the op fast 
			 assign directly the value */
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		//SET_BIT(NVIC_ISER1, Copy_u8IntNumber);
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		// Do nothing
	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		//SET_BIT(NVIC_ICER0, Copy_u8IntNumber);
		/* zero in this reg has no effect so to make the op fast 
			 assign directly the value */
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		//SET_BIT(NVIC_ICER1, Copy_u8IntNumber);
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		// Do nothing
	}
}


void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		//SET_BIT(NVIC_ISPR0, Copy_u8IntNumber);
		/* zero in this reg has no effect so to make the op fast 
			 assign directly the value */
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		//SET_BIT(NVIC_ISPR1, Copy_u8IntNumber);
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		// Do nothing
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		//SET_BIT(NVIC_ICPR0, Copy_u8IntNumber);
		/* zero in this reg has no effect so to make the op fast 
			 assign directly the value */
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		//SET_BIT(NVIC_ICPR1, Copy_u8IntNumber);
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		// Do nothing
	}
}
void MNVIC_voidSetPriority(u8 Copy_s8PerIndex, u8 Copy_u8Priority)
{
	/* setting priority fo internal interrupts */
	
	
	/* here i can take the whole 240 external interrupts, but i will take only 60
	 Setting priority for external interrupts */
	if (Copy_s8PerIndex < 60)
	{
		NVIC_IPR[Copy_s8PerIndex] = Copy_u8Priority;
	}
	else
	{
		// return error
	}

}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result = 0;
	if (Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
	}
	else
	{
		// Do nothing
	}
	return Local_u8Result;
}

void MNVIC_voidInit(void)
{
	#define SCB_AIRCR	*((volatile u32*) 0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRBUTION;
	
}

