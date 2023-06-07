/*
 * main.c
 *
 *  Created on: May 19, 2023
 *      Author: First
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f401cc.h"

#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "GPIO_private.h"
void App(void);
int main(void)
{
	RCC_voidInitSysClk();
	STK_voidInit();
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS ,  RCC_u8_GPIO_A  );
	RCC_u8EnablePeripheralClock(RCC_u8_APB2_BUS,  14  );
	//RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS ,  RCC_u8_GPIO_A  );

	GPIO_u8SetPinMode(PORTA , PIN1 , GPIO_OUTPUT);
	GPIO_u8SetPinMode(PORTA , PIN0 , GPIO_INPUT);
	/*PULL UP FOR PIN0*/
	GPIOA->PUPDR = 1;
	NVIC_voidEnablePerInt(6);
	EXTI_PinConfig_t E0 = { EXTI_u8_GPIOA , EXTI_u8_EXTI0 , EXTI_u8_FALLING_EDGE , &App  };
	EXTI_u8PinInit(&E0);
	EXTI_u8IntEnable(E0.PinId);
	while(1)
	{
		//NVIC_voidSetPendingFlag(6);
//		EXTI_u8SetSoftwareInt(E0.PinId);
//		EXTI_u8ClearPendingFlag(E0.PinId);
//		STK_voidSetBusyWait(4000000);

	}

	return 0 ;
}

void App(void)
{
	GPIO_u8SetPinValue(PORTA , PIN1 , GPIO_HIGH);
	STK_voidSetBusyWait(1000000);
	GPIO_u8SetPinValue(PORTA , PIN1 , GPIO_LOW);
		STK_voidSetBusyWait(1000000);
		EXTI_u8ClearPendingFlag(0);

}
