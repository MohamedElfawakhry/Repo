/*
 * main.c
 *
 *  Created on: May 20, 2023
 *      Author: First
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f401cc.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "SSD_interface.h"

void EXTI0_Func(void);

EXTI_PinConfig_t E0 = { EXTI_u8_GPIOA , EXTI_u8_EXTI0 , EXTI_u8_FALLING_EDGE , &EXTI0_Func };
SSD_type S1 = {PORTA , PIN1 , PIN7 , SSD_COMMON_CATHODE  };
int main(void)
{
	RCC_voidInitSysClk();
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_A);
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_B);
	//GPIOA->PUPDR = 1;
	RCC_u8EnablePeripheralClock(RCC_u8_APB2_BUS , RCC_u8_SYSCFG );

	GPIO_u8SetPinMode(PORTA , PIN0 , GPIO_INPUT );

	for(u8 i = 1 ; i < 8 ; i++)
	{
		GPIO_u8SetPinMode(PORTA , i , GPIO_OUTPUT );
	}
	/*Enable NVIC for EXTI0 , USART*/
	NVIC_voidEnablePerInt(NVIC_u8_EXTI0);
	NVIC_voidEnablePerInt(NVIC_u8_USART1);
	/*SET Priority for EXTI0 , USART */
	//NVIC_u8InitPriorityField();
	NVIC_voidSetPriorityConfig(GROUP2BITS_SUBGROUP2BITS);
	NVIC_voidSetPeriPriority(NVIC_u8_EXTI0 ,0,0 );
	NVIC_voidSetPeriPriority(NVIC_u8_USART1 ,1,0 );

//	NVIC_u8InitPriorityField();
//	NVIC_u8SetIntPriority(NVIC_u8_EXTI0 ,1,0);
//	NVIC_u8SetIntPriority(NVIC_u8_USART1 ,0,0);


	EXTI_u8PinInit(&E0);
	EXTI_u8IntEnable(E0.PinId);

	SSD_u8Init (&S1);
	while(1)
	{
		NVIC_voidSetPendingFlag(NVIC_u8_USART1);
		//NVIC_voidSetPendingFlag(NVIC_u8_EXTI0);
//		u8 Local_u8Iterator = 0 ;
//			for(Local_u8Iterator = 0 ; Local_u8Iterator < 10 ; Local_u8Iterator++)
//			{
//				SSD_u8SendNumber(&S1 , Local_u8Iterator );
//				STK_voidSetBusyWait(4000000);
//			}

	}

	return 0 ;
}
void EXTI0_Func(void)
{
	u8 Local_u8Iterator = 0 ;
	for(Local_u8Iterator = 0 ; Local_u8Iterator < 10 ; Local_u8Iterator++)
	{
		SSD_u8SendNumber(&S1 , Local_u8Iterator );
		STK_voidSetBusyWait(4000000);
//		if(Local_u8Iterator == 4)
//		{
//			NVIC_voidSetPendingFlag(NVIC_u8_USART1);
//		}
	}
	SSD_u8Disable(&S1);
	NVIC_voidClearPendingFlag(NVIC_u8_EXTI0);
}
void USART1_IRQHandler(void)
{
	u8 Local_u8Iterator = 0 ;
		for(Local_u8Iterator = 0 ; Local_u8Iterator < 10 ; Local_u8Iterator++)
		{
			SSD_u8SendNumber(&S1 , 9-Local_u8Iterator );
			STK_voidSetBusyWait(4000000);

		}
		SSD_u8Disable(&S1);
		NVIC_voidClearPendingFlag(NVIC_u8_USART1);
}

