/*
 * main.c
 *
 *  Created on: May 10, 2023
 *      Author: First
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SSD_interface.h"
void APP_voidDelayMs(u32 Copy_u32Delay );


int main(void)
{

	/*Step1 : System Clock is 25MHz from HSE */
	RCC_voidInitSysClk();
	/*Step2 : Enable GPIO Peripheral Clock for PORT A*/
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_A);
	//RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_B);
	STK_voidInit();
	SSD_type SSD1 = { PORTA , PIN0 , PIN6 , SSD_COMMON_CATHODE };
	SSD_u8Init(&SSD1);
	while(1)
	{

		for(u8 i = 0 ; i <= 9 ; i++)
		{
			SSD_u8SendNumber(&SSD1 , i);
			STK_voidSetBusyWait(1000000);
		}
		SSD_u8Disable(&SSD1);
		STK_voidSetBusyWait(1000000);

//		GPIO_u8SetPinValue(PORTA , PIN0 , GPIO_HIGH );
//		STK_voidSetBusyWait(1000000);
//		GPIO_u8SetPinValue(PORTA , PIN0 , GPIO_LOW );
//				STK_voidSetBusyWait(1000000);

	}
	return 0 ;
}

void APP_voidDelayMs(u32 Copy_u32Delay )
{
	for( u32 i = 0 ; i < Copy_u32Delay * 300 ; i++)
	{
		asm("NOP");
	}
}

