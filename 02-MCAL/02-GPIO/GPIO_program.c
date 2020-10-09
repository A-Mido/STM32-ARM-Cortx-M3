/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 14 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8MODE)
{
	switch (Copy_u8PORT)
	{
		case GPIOA:
			if (Copy_u8PIN <= 7)
			{
				GPIOA_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOA_CRL |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
			}
			else if (Copy_u8PIN <= 15 && Copy_u8PIN > 7)
			{
				Copy_u8PIN = Copy_u8PIN - 8;
				GPIOA_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOA_CRH |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
			}
			else
			{
				/* Return Erorr*/
			}
			break;
		case GPIOB:
			if (Copy_u8PIN <= 7)
			{
				GPIOB_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOB_CRL |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
			}
			else if (Copy_u8PIN <= 15 && Copy_u8PIN > 7)
			{
				Copy_u8PIN = Copy_u8PIN - 8;
				GPIOB_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOB_CRH |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
			}
			else
			{
				/* Return Erorr*/
			}
			break;
		case GPIOC:
			if (Copy_u8PIN <= 7)
			{
				GPIOC_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOC_CRL |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
			}
			else if (Copy_u8PIN <= 15 && Copy_u8PIN > 7)
			{
				Copy_u8PIN = Copy_u8PIN - 8;
				GPIOC_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
				GPIOC_CRH |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
			}
			else
			{
				/* Return Erorr*/
			}

			break;
	}
}

void MGPIO_voidSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8MODE)
{
	switch (Copy_u8PORT)
	{
		case GPIOA: 
			GPIOA_CRL &= 0x00000000;
			GPIOA_CRH &= 0x00000000;
			for (u8 i = 0; i < 8; i++)
			{
				GPIOA_CRL |=   ((Copy_u8MODE) << (i * 4));
				GPIOA_CRH |=   ((Copy_u8MODE) << (i * 4));
			}
			break;
		case GPIOB: 
			GPIOB_CRL &= 0x00000000;
			GPIOB_CRH &= 0x00000000;
			for (u8 i = 0; i < 8; i++)
			{
				GPIOB_CRL |=   ((Copy_u8MODE) << (i * 4));
				GPIOB_CRH |=   ((Copy_u8MODE) << (i * 4));
			}
			break;
		case GPIOC: 
			GPIOC_CRL &= 0x00000000;
			GPIOC_CRH &= 0x00000000;
			for (u8 i = 0; i < 8; i++)
			{
				GPIOC_CRL |=   ((Copy_u8MODE) << (i * 4));
				GPIOC_CRH |=   ((Copy_u8MODE) << (i * 4));
			}
			break;
	}
	
}


void MGPIO_voidSetHalfPortDirection(u8 Copy_u8PORT, u8 Copy_u8HALF, u8 Copy_u8MODE)
{
	switch (Copy_u8PORT)
	{
		case GPIOA: 
			if (Copy_u8HALF == LOW_HALF)
			{
				GPIOA_CRL &= 0x00000000;
				for (u8 i = 0; i < 8; i++)
				{
					GPIOA_CRL |=   ((Copy_u8MODE) << (i * 4));
				}
			}
			else if (Copy_u8HALF == HIGH_HALF)
			{
				GPIOA_CRH &= 0x00000000;
				for (u8 i = 0; i < 8; i++)
				{
					GPIOA_CRH |=   ((Copy_u8MODE) << (i * 4));
				}
			}
			
			break;
		case GPIOB:  
			if (Copy_u8HALF == LOW_HALF)
			{
				GPIOB_CRL &= 0x00000000;
				for (u8 i = 0; i < 8; i++)
				{
					GPIOB_CRL |=   ((Copy_u8MODE) << (i * 4));
				}
			}
			else if (Copy_u8HALF == HIGH_HALF)
			{
				GPIOB_CRH &= 0x00000000;
				for (u8 i = 0; i < 8; i++)
				{
					GPIOB_CRH |=   ((Copy_u8MODE) << (i * 4));
				}
			}
			
			break;
		case GPIOC: 
			if (Copy_u8HALF == LOW_HALF)
			{
				GPIOC_CRL &= 0x00000000;
				for (u8 i = 0; i < 8; i++)
				{
					GPIOC_CRL |=   ((Copy_u8MODE) << (i * 4));
				}
			}
			else if (Copy_u8HALF == HIGH_HALF)
			{
				GPIOC_CRH &= 0x00000000;
				for (u8 i = 0; i < 8; i++)
				{
					GPIOC_CRH |=   ((Copy_u8MODE) << (i * 4));
				}
			}
			
			break;
	}
	
	
}

void MGPIO_voidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8VALUE)
{
	switch (Copy_u8PORT)
	{
		case GPIOA:
		
			if (Copy_u8VALUE == HIGH)
			{
				/* about 4 operations at least */
				/*SET_BIT(GPIOA_ODR, Copy_u8PIN);*/
				
				/* speedy set pin value */ 
				GPIOA_BSRR = (1 << Copy_u8PIN);
			}
			else if (Copy_u8PIN == LOW)
			{
				/* both take more than 4 instruction at least
				GPIOA_BSRR = (1 << (Copy_u8PIN + 16));
				CLR_BIT(GPIOA_ODR, Copy_u8PIN);*/
				
				/* speedy reset pin value */
				GPIOA_BRR = (1 << Copy_u8PIN);
			}
			else
			{
				/* Return Erorr*/
			}
			break;
		case GPIOB:
		
			if (Copy_u8VALUE == HIGH)
			{
				//SET_BIT(GPIOB_ODR, Copy_u8PIN);
				GPIOB_BSRR = (1 << Copy_u8PIN);
			}
			else if (Copy_u8PIN == LOW)
			{
				//CLR_BIT(GPIOB_ODR, Copy_u8PIN);
				
				GPIOB_BRR = (1 << Copy_u8PIN);
			}
			else
			{
				/* Return Erorr*/
			}
			break;
		case GPIOC:
		
			if (Copy_u8VALUE == HIGH)
			{
				//SET_BIT(GPIOC_ODR, Copy_u8PIN);
				
				GPIOC_BSRR = (1 << Copy_u8PIN);
			}
			else if (Copy_u8PIN == LOW)
			{
				//CLR_BIT(GPIOC_ODR, Copy_u8PIN);
				
				GPIOC_BRR = (1 << Copy_u8PIN);
			}
			else
			{
				/* Return Erorr*/
			}

			break;
	}
}

void MGPIO_voidSetPortValue(u8 Copy_u8PORT, u8 Copy_u8VALUE)
{
	switch (Copy_u8PORT)
	{
		case GPIOA:
			GPIOA_ODR = Copy_u8VALUE;
			break;
		case GPIOB:

			GPIOB_ODR = Copy_u8VALUE;
			break;
		case GPIOC:

			GPIOC_ODR = Copy_u8VALUE;
			break;
	}
}


void MGPIO_voidSetHalfPortValue(u8 Copy_u8PORT, u8 Copy_u8HALF,u8 Copy_u8VALUE)
{
	u32 Temp_u32REG = 0;

	switch (Copy_u8PORT)
	{
		case GPIOA:
			if (Copy_u8HALF == LOW_HALF)
			{
				Temp_u32REG  = GPIOA_ODR;
				Temp_u32REG &= ~(0x00FF);
				Temp_u32REG |= Copy_u8VALUE;
				GPIOA_ODR  = Temp_u32REG;
			}	
			else if (Copy_u8HALF == HIGH_HALF)
			{
				Temp_u32REG  = GPIOA_ODR;
				Temp_u32REG &= ~(0xFF00);
				Temp_u32REG |= (Copy_u8VALUE << 8);
				GPIOA_ODR  = Temp_u32REG;
			}
			break;
		case GPIOB:
			if (Copy_u8HALF == LOW_HALF)
			{
				Temp_u32REG  = GPIOB_ODR;
				Temp_u32REG &= ~(0x00FF);
				Temp_u32REG |= Copy_u8VALUE;
				GPIOB_ODR  = Temp_u32REG;
			}	
			else if (Copy_u8HALF == HIGH_HALF)
			{
				Temp_u32REG  = GPIOB_ODR;
				Temp_u32REG &= ~(0xFF00);
				Temp_u32REG |= (Copy_u8VALUE << 8);
				GPIOB_ODR  = Temp_u32REG;
			}
			break;
		case GPIOC:
			if (Copy_u8HALF == LOW_HALF)
			{
				Temp_u32REG  = GPIOC_ODR;
				Temp_u32REG &= ~(0x00FF);
				Temp_u32REG |= Copy_u8VALUE;
				GPIOC_ODR  = Temp_u32REG;
			}	
			else if (Copy_u8HALF == HIGH_HALF)
			{
				Temp_u32REG  = GPIOC_ODR;
				Temp_u32REG &= ~(0xFF00);
				Temp_u32REG |= (Copy_u8VALUE << 8);
				GPIOC_ODR  = Temp_u32REG;
			}
			break;
	}
		

}

void MGPIO_voidLockPinConfig(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	switch (Copy_u8PORT)
	{
		case GPIOA:
			SET_BIT(GPIOA_LCKR, Copy_u8PIN);
			/* LOCK Key Writing sequence to active LCKR Register*/
			SET_BIT(GPIOA_LCKR, 16);
			CLT_BIT(GPIOA_LCKR, 16);
			SET_BIT(GPIOA_LCKR, 16);
			GET_BIT(GPIOA_LCKR, 16);
			GET_BIT(GPIOA_LCKR, 16);
			
			break;
		case GPIOB:
			SET_BIT(GPIOB_LCKR, Copy_u8PIN);
			
			SET_BIT(GPIOB_LCKR, 16);
			CLT_BIT(GPIOB_LCKR, 16);
			SET_BIT(GPIOB_LCKR, 16);
			GET_BIT(GPIOB_LCKR, 16);
			GET_BIT(GPIOB_LCKR, 16);
			
			break;
		case GPIOC:
			SET_BIT(GPIOC_LCKR, Copy_u8PIN);
			
			SET_BIT(GPIOC_LCKR, 16);
			CLT_BIT(GPIOC_LCKR, 16);
			SET_BIT(GPIOC_LCKR, 16);
			GET_BIT(GPIOC_LCKR, 16);
			GET_BIT(GPIOC_LCKR, 16);
			break;
	}
}


u8	 MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	u8 LOC_u8Result = 0;
	
	switch (Copy_u8PORT)
	{
		case GPIOA:
			LOC_u8Result = GET_BIT(GPIOA_IDR, Copy_u8PIN);
			break;
		case GPIOB:
			LOC_u8Result = GET_BIT(GPIOB_IDR, Copy_u8PIN);
			break;
		case GPIOC:
			LOC_u8Result = GET_BIT(GPIOC_IDR, Copy_u8PIN);
			break;
	}
	return LOC_u8Result;
}

