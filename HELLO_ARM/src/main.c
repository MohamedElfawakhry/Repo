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
void APP_voidDelayMs(u32 Copy_u32Delay );


int main(void)
{

	/*Step1 : System Clock is 25MHz from HSE */
	RCC_voidInitSysClk();
	/*Step2 : Enable GPIO Peripheral Clock for PORT A*/
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_A);
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_B);

	/*Step 3 :configure Pin A0 as OUTPUT */
	GPIO_u8SetPinMode(PORTA , PIN0 , GPIO_OUTPUT);
	GPIO_u8SetPinMode(PORTB , PIN0 , GPIO_OUTPUT);

	/*Step 4 : configure Pin A0 as pin HIGH*/
	GPIO_u8SetPinValue(PORTA , PIN0 , GPIO_HIGH);
	GPIO_u8SetPinValue(PORTB , PIN0 , GPIO_HIGH);

	while(1)
	{
		/* Step 5 : Toggle LED */
		GPIO_u8SetPinValue(PORTA , PIN0 , GPIO_HIGH);
		GPIO_u8SetPinValue(PORTB , PIN0 , GPIO_HIGH);

		APP_voidDelayMs(10000);
		GPIO_u8SetPinValue(PORTA , PIN0 , GPIO_LOW);
		GPIO_u8SetPinValue(PORTB , PIN0 , GPIO_LOW);

		APP_voidDelayMs(10000);

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

