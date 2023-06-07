/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 19/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : EXTI                ************/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f401cc.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*Global_pf[5])(void)= { NULL };

u8 EXTI_u8PinInit           (const EXTI_PinConfig_t * Copy_pstrPinInit )
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if( Copy_pstrPinInit->PortId < EXTI_u8_GPIOC)
    {
        if ( Copy_pstrPinInit -> PinId < 23)
        {
            if ( Copy_pstrPinInit ->PinId == 20 || Copy_pstrPinInit ->PinId == 19 )
            {
                Local_u8ErrorState = STD_TYPES_NOK ;
            }
            else
            {
                /*  Mask the Interrupt pin */
                SET_BIT(EXTI->IMR , Copy_pstrPinInit->PinId);
                /* Mask the Port for selected pin */
                switch (Copy_pstrPinInit->PortId)
                {
                case EXTI_u8_GPIOA:
                    SYSCFG->EXTICR[Copy_pstrPinInit->PinId/4] |= (0x0) << ((Copy_pstrPinInit->PinId%4)*4);
                    
                    break;
                case EXTI_u8_GPIOB:
                    SYSCFG->EXTICR[Copy_pstrPinInit->PinId/4] |= (0x1) << ((Copy_pstrPinInit->PinId%4)*4);
                    break;
                case EXTI_u8_GPIOC:
                    SYSCFG->EXTICR[Copy_pstrPinInit->PinId/4] |= (0x2) << ((Copy_pstrPinInit->PinId%4)*4);
                    break;
                default:
                    break;
                }
                /*Set Falling or Raising or on change */
                switch (Copy_pstrPinInit->TriggerLevel)
                    {
                    case EXTI_u8_FALLING_EDGE:
                        SET_BIT(EXTI->FTSR,Copy_pstrPinInit->PinId);
                        break;
                    case EXTI_u8_RAISING_EDGE:
                        SET_BIT(EXTI->RTSR,Copy_pstrPinInit->PinId);
                        break;
                    case EXTI_u8_ON_CHANGE:
                        SET_BIT(EXTI->FTSR,Copy_pstrPinInit->PinId);
                        SET_BIT(EXTI->RTSR,Copy_pstrPinInit->PinId);
                        break;
                    default:
                        break;
                    }
                switch (Copy_pstrPinInit->PinId)
                {
                case EXTI_u8_PIN0 :
                    Global_pf[0] = Copy_pstrPinInit->pf ;
                    break;
                case EXTI_u8_PIN1 :
                    Global_pf[1] = Copy_pstrPinInit->pf ;
                    break;
                case EXTI_u8_PIN2 :
                    Global_pf[2] = Copy_pstrPinInit->pf ;
                    break;
                case EXTI_u8_PIN3 :
                    Global_pf[3] = Copy_pstrPinInit->pf ;
                    break;
                case EXTI_u8_PIN4 :
                    Global_pf[4] = Copy_pstrPinInit->pf ;
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            Local_u8ErrorState = STD_TYPES_NOK ;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable         (u8 Copy_u8EXTINum) 
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8EXTINum < 16)
    {
        SET_BIT(EXTI->IMR , Copy_u8EXTINum);
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState ;
}

u8 EXTI_u8IntDisable         (u8 Copy_u8EXTINum) 
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8EXTINum < 16)
    {
        CLR_BIT(EXTI->IMR , Copy_u8EXTINum);
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState ;
}

u8 EXTI_u8ClearPendingFlag  (u8 Copy_u8EXTINum) 
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8EXTINum < 16)
    {
        SET_BIT(EXTI->PR , Copy_u8EXTINum);
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState ;
}

u8 EXTI_u8SetSoftwareInt    (u8 Copy_u8EXTINum) 
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8EXTINum < 16)
    {
        CLR_BIT(EXTI->SWIER , Copy_u8EXTINum);
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState ;
}
void EXTI0_IRQHandler(void)
{
	if(Global_pf[0] != NULL)
	{
		Global_pf[0]();
	}
}
