/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* there is no lower layers to call*/

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if 	RCC_CLOCK_TYPE == RCC_HSI
			RCC_CR   = 0x00000081; /* choose HSI on*/
			RCC_CFGR = 0x00000000; /* making sw 00 to make HSI source*/
	#elif   RCC_CLOCK_TYPE == RCC_HSE_RC
			RCC_CR   = 0x00050000; /* choose HSE on and using bypass*/
			RCC_CFGR = 0x00000001; /* making sw 01 to make HSE source*/
	#elif	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
			RCC_CR   = 0x00010000; /* choose HSE on without bypass*/
			RCC_CFGR = 0x00000001; /* making sw 01 to make HSE source*/
	#elif	RCC_CLOCK_TYPE == RCC_PLL
	
			#if 	RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
					RCC_CR   = 0x00000000; /* disable PLL */
					RCC_CFGR = 0x00000002; 
					RCC_CR   = 0x01000000; /* enable PLL */
			#elif	RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
					RCC_CR   = 0x00000000; /* disable PLL */
					RCC_CFGR = 0x00030002;
					RCC_CR   = 0x01000000; /* enable PLL */
			#elif	RCC_PLL_INPUT == RCC_PLL_IN_HSE
					RCC_CR   = 0x00000000; /* disable PLL */
					RCC_CFGR = 0x00010002;
					RCC_CR   = 0x01000000; /* enable PLL */
			#endif	
	
	#else
		#error("You choose wrong clock type")
	#endif
}

	
/* if you want to enable clock for a certain periphral you have
 to send the bus in which the periphral exisit and the the periphral 
 you want to enable*/
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* each bus has 32 bits each bit for a periphral on the bus 
		from 0 to 31 be sure that the periphral bit does not excced
		the location 31 */
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			/*what this line mean go to RCC_AHBENR bus access bit 
				no Copy_u8PerId set this bit to 1 */
			case RCC_AHB :	SET_BIT(RCC_AHBENR , Copy_u8PerId); break;
			case RCC_APB1:  SET_BIT(RCC_APB1ENR, Copy_u8PerId); break;
			case RCC_APB2:  SET_BIT(RCC_APB2ENR, Copy_u8PerId); break;
			
			/* some compilers are not good with empty default statment 
				so we will leav it till now*/
			//default		 : /* Return Error */ 					break;
		}
	}
	else
	{
		/* Return Error */
	}

}

/* if you want to disable clock for a certain periphral you have
 to send the bus in which the periphral exisit and the the periphral 
 you want to disable*/
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	/* each bus has 32 bits each bit for a periphral on the bus 
		from 0 to 31 be sure that the periphral bit does not excced
		the location 31*/
	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			/*what this line mean go to RCC_AHBENR bus access bit 
				no Copy_u8PerId clear this bit to 0 */
			case RCC_AHB :	CLR_BIT(RCC_AHBENR , Copy_u8PerId); break;
			case RCC_APB1:  CLR_BIT(RCC_APB1ENR, Copy_u8PerId); break;
			case RCC_APB2:  CLR_BIT(RCC_APB2ENR, Copy_u8PerId); break;
			
			/* some compilers are not good with empty default statment 
				so we will leav it till now*/
			//default		 : /* Return Error */ 					break;
		}
	}
	else
	{
		/* Return Error */
	}

}