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

int main(void)
{
	RCC_voidInitSysClk();
	STK_voidInit();
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS ,  RCC_u8_GPIO_A  );
	GPIO_u8SetPinMode(PORTA , PIN0 , GPIO_OUTPUT);


	NVIC_voidEnablePerInt(6);
	while(1)
	{
		NVIC_voidSetPendingFlag(6);
	}

	return 0 ;
}

void EXTI0_IRQHandler(void)
{
	GPIO_u8SetPinValue(PORTA , PIN0 , GPIO_HIGH);
	STK_voidSetBusyWait(4000000);
	GPIO_u8SetPinValue(PORTA , PIN0 , GPIO_LOW);
		STK_voidSetBusyWait(4000000);

}
void EXTI1_IRQHandler(void)
{

}
