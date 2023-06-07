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
//#include "LEDMXD_interface.h"
#include "HLED_MATRIX_Interface.h"

u8 Arr[8] = {0,255,2,4,8,4,2,255}; //{255, 2, 4, 8, 4, 2, 255, 0 } ;

int main(void)
{
	RCC_voidInitSysClk();
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_A);
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_B);
	//GPIOA->PUPDR = 1;
	//RCC_u8EnablePeripheralClock(RCC_u8_APB2_BUS , RCC_u8_SYSCFG );


//	EXTI_u8PinInit(&E0);
//	EXTI_u8IntEnable(E0.PinId);

	HLEDMAT_voidInit();

	while(1)
	{
		HLEDMAT_voidDisplay(Arr);

	}

	return 0 ;
}
