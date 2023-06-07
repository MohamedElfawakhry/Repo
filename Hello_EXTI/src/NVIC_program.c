/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 18/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : NVIC                ************/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f401cc.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

static u8 StaticGlobal_u8PriorityConfig ;
void NVIC_voidEnablePerInt ( u8 Copy_u8IntId)
{
    NVIC->ISER[Copy_u8IntId /32 ] = (1 << Copy_u8IntId % 32 );
}

void NVIC_voidDisablePerInt ( u8 Copy_u8IntId)
{
    NVIC->ICER[Copy_u8IntId /32 ] = (1 << Copy_u8IntId % 32 );
}

void NVIC_voidSetPendingFlag ( u8 Copy_u8IntId)
{
    NVIC->ISPR[Copy_u8IntId /32 ] = (1 << Copy_u8IntId % 32 );

}
void NVIC_voidClearPendingFlag ( u8 Copy_u8IntId)
{
    NVIC->ICPR[Copy_u8IntId /32 ] = (1 << Copy_u8IntId % 32 );
   
}

/*
Copy_u8PriorityOption:
1. GROUP4BITS_SUBGROUP0BITS
2. GROUP3BITS_SUBGROUP1BITS
3. GROUP2BITS_SUBGROUP2BITS
4. GROUP1BITS_SUBGROUP3BITS
5. GROUP0BITS_SUBGROUP4BITS

*/
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption)
{
    StaticGlobal_u8PriorityConfig  = VECT_KEY | (Copy_u8PriorityOption << 8);
    SCB->AIRCR = StaticGlobal_u8PriorityConfig ; 
}
void NVIC_voidSetPeriPriority ( u8 Copy_u8Intid , u8 Copy_u8GroupId , u8 Copy_u8SubGroupId)
{
    u8 Local_u8Priority = Copy_u8SubGroupId | (Copy_u8GroupId << ((StaticGlobal_u8PriorityConfig - 0x05FA0300)/256));
    NVIC->IPR[Copy_u8Intid] = (Local_u8Priority << 4 ); 
}