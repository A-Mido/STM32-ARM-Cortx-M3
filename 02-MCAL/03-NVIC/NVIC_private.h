/*********************************************************************************/
/* Author    : Ahmed Sayed                                                       */
/* Version   : V01                                                               */
/* Date      : 20 August 2020                                                    */
/*********************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

// BASEADD 0xE000E100

/* Register Definitions */
#define NVIC_ISER0		*((u32*) 0xE000E100) /* Enable the external interrupts from 0 to 31 */
#define NVIC_ISER1		*((u32*) 0xE000E104) /* Enable the external interrupts from 32 to 63 */
// there is more regs in stm32 but i will use these only

#define NVIC_ICER0		*((u32*) 0xE000E180) /* Disable the external interrupts from 0 to 31 */
#define NVIC_ICER1		*((u32*) 0xE000E184) /* Disable the external interrupts from 32 to 63 */

#define NVIC_ISPR0		*((u32*) 0xE000E200) /* Enable the pending flags from 0 to 31 */
#define NVIC_ISPR1		*((u32*) 0xE000E204) /* Enable the pending flags from 32 to 63 */

#define NVIC_ICPR0		*((u32*) 0xE000E280) /* Disable the pending flags from 0 to 31 */
#define NVIC_ICPR1		*((u32*) 0xE000E284) /* Disable the pending flags from 32 to 63 */

/* volatile for read only registers */
#define NVIC_IABR0		*((volatile u32*) 0xE000E300)
#define NVIC_IABR1		*((volatile u32*) 0xE000E304)

#define NVIC_IPR		 ((volatile u8*) 0xE000E400) // 0x100 + 0x300





#endif