/*
 * main.c
 *
 *  Created on: Jun 2, 2023
 *      Author: First
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"
#include "STP_interface.h"



void UpdateArray (u8 *Copy_u8Array, u8 Copy_NewValue);
u8 LEDMXD_ARRAY[8]={0, 0, 0, 0, 0, 0, 0, 0};
u8 NewValues[]={0, 255, 2, 4, 8, 4, 2, 255,0,0,0,0, 255, 8, 8, 8, 8, 255, 0 ,0,0,0,0, 255, 2, 4, 8, 4, 2, 255,0,0,0,0, 255, 129, 129, 129, 129, 126, 0 };


int main()
{

	/*System Clock */
	RCC_voidInitSysClk();
	/*Enable GPIOA */
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_A);
	/*Systick Initilization */
	STK_voidInit();
	/*	STP Initilization	*/
	STP_voidInit();

	/*	LEDMatrix */
	LEDMXD_voidInit();

	while(1)
	{
//		for(u8 i = 0 ; i<8 ; i++)
//		{
//			STP_voidSendSynchronus(1 << i );
//			STK_voidSetBusyWait(1000000);
//		}
		for ( u8 i=0 ; i<50 ; i++ )
				{
					LEDMXD_u8Display(LEDMXD_ARRAY);
					UpdateArray(LEDMXD_ARRAY,NewValues[i]);
				}
	}


	return 0 ;
}

void UpdateArray (u8 *Copy_u8Array, u8 Copy_NewValue)
{
	for(u8 i=0 ; i<8 ; i++)
	{
		Copy_u8Array[i] ^= Copy_u8Array[i+1] ;
		Copy_u8Array[i+1] ^= Copy_u8Array[i] ;
		Copy_u8Array[i] ^= Copy_u8Array[i+1] ;
		if ( i == 7 )
		{ Copy_u8Array[i] = Copy_NewValue ; }
	}
}

