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

void (*Glo_pf)(void) = NULL ;
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
void STK_voidCtrlIntStateEnable(void)
{
    SYSTICK->CTRL |= (1 << 1 );
}
void STK_voidSetCallBackFunc(void *Lpf ( void ))
{
    Glo_pf = Lpf ;
}
void STK_voidReadFlag (void)
{
    return (GET_BIT(SYSTICK->CTRL , 16));
}
void SysTick_Handler(void)
{
    Glo_pf();
    /*To Clear FLag */
    STK_voidReadFlag() ;
}