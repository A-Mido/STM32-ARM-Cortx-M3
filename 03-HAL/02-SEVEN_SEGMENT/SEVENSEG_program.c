/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 16 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"


#include "SEVENSEG_interface.h"





void _7SEGMENT_voidWriteNum(u8 Copy_u8MODE, u8 Copy_u8PORT, u8 Copy_u8HALF, u8 Copy_u8VALUE)
{
	u8 Seven_Seg_Array[11] = {0x3F, 0x06, 0x5B, 0x4F, 0x66,
							  0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	Seven_Seg_Array[10] = '\0';
	
	if (Copy_u8MODE == COMMON_CATHODE)
	{
		
		if (Copy_u8VALUE < 10)
		{
			switch (Copy_u8PORT)
			{
				case GPIOA: 
					//MGPIO_voidSetHalfPortDirection(GPIOA, Copy_u8HALF, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetHalfPortValue(GPIOA, Copy_u8HALF, Seven_Seg_Array[Copy_u8VALUE]);
						  
					break;
						  
				case GPIOB:
					//MGPIO_voidSetHalfPortDirection(GPIOB, Copy_u8HALF, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetHalfPortValue(GPIOB, Copy_u8HALF, Seven_Seg_Array[Copy_u8VALUE]);
						  
					break;
						  
				case GPIOC:
					//MGPIO_voidSetHalfPortDirection(GPIOC, Copy_u8HALF, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetHalfPortValue(GPIOC, Copy_u8HALF, Seven_Seg_Array[Copy_u8VALUE]);
					
					break;
				
			}
			
		}
		else
		{
			// Return Error
		}
	
	}
	else if (Copy_u8MODE == COMMON_ANODE)
	{
		if (Copy_u8VALUE < 10)
		{
			switch (Copy_u8PORT)
			{
				case GPIOA: 
					//MGPIO_voidSetHalfPortDirection(GPIOA, Copy_u8HALF, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetHalfPortValue(GPIOA, Copy_u8HALF, ~Seven_Seg_Array[Copy_u8VALUE]);
					
					break;
					
				case GPIOB:
					//MGPIO_voidSetHalfPortDirection(GPIOB, Copy_u8HALF, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetHalfPortValue(GPIOB, Copy_u8HALF, ~Seven_Seg_Array[Copy_u8VALUE]);

					break;

				case GPIOC:
					//MGPIO_voidSetHalfPortDirection(GPIOC, Copy_u8HALF, OUTPUT_SPEED_10MHZ_PP);
					MGPIO_voidSetHalfPortValue(GPIOC, Copy_u8HALF, ~Seven_Seg_Array[Copy_u8VALUE]);

					break;
				
			}
			
		}
		else
		{
			// Return Error
		}
		
	}
	else
	{
		// Return Error
	}
	
}
