/*
 * main.c
 *
 *  Created on: May 30, 2023
 *      Author: First
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "LEDMXD_interface.h"



volatile u8 NewValues[50]={0, 255, 2, 4, 8, 4, 2, 255,0,0,0,0, 255, 8, 8, 8, 8, 255, 0 ,0,0,0,0, 255, 2, 4, 8, 4, 2, 255,0,0,0,0, 255, 129, 129, 129, 129, 126, 0 };


int main(void)
{
	/*Init RCC*/
	RCC_voidInitSysClk();
	/*Enable GPIOA , GPIOB*/
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS, RCC_u8_GPIO_A);
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS, RCC_u8_GPIO_B);

	/*Init Systic*/
	STK_voidInit();
	/*Initlize LEDMXD*/
	LEDMXD_voidInit();

	u8 Local_Au8DispliedChar[8] ;
	u8 Local_u8Counter = 0 ;
	u8 Local_u8Iterator ;
	while(1)
	{
		for(Local_u8Iterator = 0 ; Local_u8Iterator < 8 ; Local_u8Iterator++)
		{
			Local_Au8DispliedChar[Local_u8Iterator] = NewValues[Local_u8Iterator + Local_u8Counter];
		}
		LEDMXD_u8Display(Local_Au8DispliedChar);
		Local_u8Counter+=8 ;
	}
	return 0;
}
