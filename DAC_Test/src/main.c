
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "agmal.h"

volatile u16 Global_u16Counter = 0 ;
void App_voidSetDAC(void)
{
	GPIO_u8SetPortValue(GPIO_PORTA , agmal_raw[Global_u16Counter] );
	Global_u16Counter++ ;
	if(Global_u16Counter == 38917)
		Global_u16Counter = 0 ;
}
int main(void)
{
	RCC_voidInitSysClk();
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_A);
	STK_voidInit() ;

	/*Configure pins */
	for(u8 i = 0 ; i < 8 ; i++)
	GPIO_u8SetPinMode(GPIO_PORTA , i , GPIO_OUTPUT);
	for(u8 i = 0 ; i < 8 ; i++)
	GPIO_u8SetPinType(GPIO_PORTA , i , GPIO_PUSH_PULL);


	STK_voidSetIntervalPeriodic(125 , &App_voidSetDAC);

	while(1)
	{

	}
	return 0 ;
}


