/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 12 August 2020                                                    */
/*********************************************************************************/

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/* System clocks :
		RCC_HSE_RC
		RCC_HSE_CRYSTAL
		RCC_HSI
		RCC_PLL */
#define RCC_CLOCK_TYPE	 RCC_HSE_CRYSTAL


/* PLL clocks could be :
		RCC_HSI_DIV_2
		RCC_HSE_DIV_2
		RCC_HSE
		 */
#if  RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT 	RCC_PLL_IN_HSE_DIV_2
#endif

/* the multiplication values of PLL could be from
		2 to 16 */
#if  RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_MUL_VALUE	 2
#endif

#endif