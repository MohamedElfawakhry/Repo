
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SYSTICK_interface.h"
#include "MyScheduler_interface.h"


void App_Led1(void)
{
	static u8 Local_su8State = 0 ;
	if ( Local_su8State == 0 )
	{
		GPIO_u8SetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_HIGH);
		Local_su8State = 1 ;
	}
	else if ( Local_su8State == 1)
	{
		GPIO_u8SetPinValue(GPIO_PORTA , GPIO_PIN0 , GPIO_LOW);
		Local_su8State = 0 ;
	}
}
void App_Led2(void)
{
	static u8 Local_su8State = 0 ;
		if ( Local_su8State == 0 )
		{
			GPIO_u8SetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_HIGH);
			Local_su8State = 1 ;
		}
		else if ( Local_su8State == 1)
		{
			GPIO_u8SetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_LOW);
			Local_su8State = 0 ;
		}
}
void App_Led3(void)
{
	static u8 Local_su8State = 0 ;
			if ( Local_su8State == 0 )
			{
				GPIO_u8SetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_HIGH);
				Local_su8State = 1 ;
			}
			else if ( Local_su8State == 1)
			{
				GPIO_u8SetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_LOW);
				Local_su8State = 0 ;
			}
}
int main(void)
{
	RCC_voidInitSysClk();
	RCC_u8EnablePeripheralClock(RCC_u8_AHB1_BUS , RCC_u8_GPIO_A);


	/*Configure pins */
	GPIO_u8SetPinMode(GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT);
	GPIO_u8SetPinMode(GPIO_PORTA , GPIO_PIN1 , GPIO_OUTPUT);
	GPIO_u8SetPinMode(GPIO_PORTA , GPIO_PIN2 , GPIO_OUTPUT);

	GPIO_u8SetPinType(GPIO_PORTA , GPIO_PIN0 , GPIO_PUSH_PULL);
	GPIO_u8SetPinType(GPIO_PORTA , GPIO_PIN1 , GPIO_PUSH_PULL);
	GPIO_u8SetPinType(GPIO_PORTA , GPIO_PIN2 , GPIO_PUSH_PULL);

	/*Create Tasks */
	MySchduler_u8CreateTask(0,1000,0 ,App_Led1);
	MySchduler_u8CreateTask(1,5000,0 ,App_Led2);
	MySchduler_u8CreateTask(2,10000,1 ,App_Led3);

	MySchduler_voidStartOs();

	while(1)
	{

	}
	return 0 ;
}
