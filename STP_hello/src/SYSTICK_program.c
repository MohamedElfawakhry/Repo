/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 10/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : SYSTICK                 ************/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f401cc.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

static void (*Glo_pf)(void) = NULL ;
static u8 STK_u8IntervalMode ;
void STK_voidInit( void )
{
    #if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_PRESCALED_8
    CLR_BIT(SYSTICK->CTRL , 2);
    #elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB
    SET_BIT(SYSTICK->CTRL , 2 );
    #endif
}
void STK_voidStart ( u32 Copy_u32PreloadValue)
{
    SYSTICK->LOAD = Copy_u32PreloadValue ;

    SYSTICK->VAL = 0 ;

    /*Enable Systic*/
    SET_BIT(SYSTICK->CTRL , 0 );
}
void STK_voidSetBusyWait (u32 Copy_u32Ticks )
{
    SYSTICK->LOAD = Copy_u32Ticks ;
    /*Enable Timer */
    SET_BIT(SYSTICK->CTRL , 0);
    /*Hold untill flag raised*/
    while((GET_BIT(SYSTICK->CTRL , 16)) == 0);

    SYSTICK->LOAD = 0 ;
    SYSTICK->VAL = 0 ;
    /*Disable Timer */
    CLR_BIT(SYSTICK->CTRL , 0);
}
u32 STK_u32GetElapsedTime(void)
{
    return (SYSTICK->LOAD) - (SYSTICK->VAL) ;
}
u32 STK_u32GetRemainingTime(void)
{
    return SYSTICK->VAL ;
}

void STK_voidSetIntervalPeriodic (u32 Copy_u32Ticks , void (*Copy_pf)(void))
{
	if(Copy_pf != NULL)
	{
		/*Set Load Register with The input number of ticks*/
		SYSTICK->LOAD = Copy_u32Ticks - 1 ;

		/*Start Timer */
		SET_BIT(SYSTICK->CTRL , 0 );

		/*Save Address of the function that the interrupt should Call */
		STK_voidSetCallBackFunc(Copy_pf);

		/*Set the Indication flag to periodic interval	*/
		STK_u8IntervalMode = STK_u8_PERIODIC_INTERVAL	;

		/*	Enable Interrupt	*/
		STK_voidCtrlIntStateEnable();


	}
}
void STK_voidSetIntervalSingle (u32 Copy_u32Ticks , void (*Copy_pf)(void))
{
	if(Copy_pf != NULL)
	{
		/*Disable Timer*/
		CLR_BIT(SYSTICK->CTRL ,0);
		SYSTICK->VAL =  0 ;
		/*Set Load Register with the input ticks*/
		SYSTICK->LOAD = Copy_u32Ticks ;
		/*Start Timer */
		SET_BIT(SYSTICK->CTRL ,0);
		/*Save The Address the interrupt should call*/
		Glo_pf = Copy_pf ;

		/*Set the indication flag to singel interval*/
		STK_u8IntervalMode = STK_u8_SIGNLE_INTERVAL ;

		/*Enable Interrupt */
		STK_voidCtrlIntStateEnable();
	}
}







void STK_voidCtrlIntStateEnable(void)
{
    SYSTICK->CTRL |= (1 << 1 );
}
void STK_voidSetCallBackFunc(void (*Lpf) ( void ))
{
	if(Lpf != NULL)
		Glo_pf = Lpf ;
}
u8 STK_voidReadFlag (void)
{
    return (GET_BIT(SYSTICK->CTRL , 16));
}
void SysTick_Handler(void)
{

	if(STK_u8IntervalMode == STK_u8_SIGNLE_INTERVAL)
	{
		/*Disable the interrupt */
		SYSTICK->CTRL |= (0 << 1 );
		/*stop timer*/
		CLR_BIT(SYSTICK->CTRL , 0 );
		/*Clear Load and val registers*/
		SYSTICK->LOAD = 0 ;
		SYSTICK -> VAL = 0 ;
	}
	/*Call the function*/
	if(Glo_pf != NULL)
	{
		Glo_pf();
	}

    /*	Clear FLag ==>	by Reading  */
    STK_voidReadFlag() ;
}
