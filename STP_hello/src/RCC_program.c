/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 10/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : RCC                 ************/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f401cc.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClk (void)
{
    #if RCC_SYSCLSRC == HSE_CRYSTAL
        /* Enable HSE */ 
        SET_BIT(RCC->CR  , 16 );
        /*Disable Bypass */
        CLR_BIT (RCC->CR , 18 ); 
        /* System CLK source  ==> HSE */
        SET_BIT(RCC->CFGR , 0);
        CLR_BIT(RCC->CFGR,1);
       
    #elif RCC_SYSCLSRC == HSE_RC
        /* Enable HSE */ 
        SET_BIT(RCC->CR  , 16 );
        /*Disable Bypass */
        CLR_BIT (RCC->CR , 18 ); 
        /* System CLK source  ==> HSE */
        SET_BIT(RCC->CFGR , 0);
        CLR_BIT(RCC->CFGR,1);
    #elif RCC_SYSCLSRC == HSI
        /* Enable HSI */
        SET_BIT(RCC->CR , 0);
        /* Sys Clk Source ==> HSI */
        CLR_BIT(RCC->CFGR , 0);
        CLR_BIT(RCC->CFGR , 1); 
    #elif RCC_SYSCLSRC == PLL
        /**/
        #if PLL_CLK_INPUT == HSI
        #endif
    #else
        #error "Invalid Option for Clock Source "
    #endif
}

/******************************************************************/
/*Func. Name: RCC_u8EnablePeripheralClock                                 */
/*i/p arguments: Copy_u8BusId options: AHB1, AHB2 , APB1, APB2 */
/*Copy_u8PerId:     */
/*return: void                                                    */
/******************************************************************/
u8 RCC_u8EnablePeripheralClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PerId > 31 )
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        switch (Copy_u8BusId)
        {
        case RCC_u8_AHB1_BUS: 
            SET_BIT(RCC->AHB1ENR , Copy_u8PerId );
            break;
        case RCC_u8_AHB2_BUS:
            SET_BIT(RCC->AHB2ENR , Copy_u8PerId );
            break;
        case RCC_u8_APB1_BUS: 
            SET_BIT(RCC->APB1ENR , Copy_u8PerId );
            break;
        case RCC_u8_APB2_BUS:
            SET_BIT(RCC->APB2ENR , Copy_u8PerId );
            break;   
        default:
            break;
        }
    }
    return Local_u8ErrorState ; 
}
u8 RCC_u8DisablePeripheralClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PerId > 31 )
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        switch (Copy_u8BusId)
        {
        case RCC_u8_AHB1_BUS: 
            CLR_BIT(RCC->AHB1ENR , Copy_u8PerId );
            break;
        case RCC_u8_AHB2_BUS:
            CLR_BIT(RCC->AHB2ENR , Copy_u8PerId );
            break;
        case RCC_u8_APB1_BUS: 
            CLR_BIT(RCC->APB1ENR , Copy_u8PerId );
            break;
        case RCC_u8_APB2_BUS:
            CLR_BIT(RCC->APB2ENR , Copy_u8PerId );
            break;   
        default:
            break;
        }
    }
    return Local_u8ErrorState ; 
}
