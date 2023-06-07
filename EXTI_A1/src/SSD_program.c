/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 12/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : SSD                 ************/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"
u8 SSD_ArrNumbers[10]={ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT ,NINE };
u8 SSD_u8Init(SSD_type* Copy_pstructSSD ) 
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    for(u8 Local_u8Iter = Copy_pstructSSD->SSD_u8InPin ; Local_u8Iter <= Copy_pstructSSD->SSD_u8EndPin ; Local_u8Iter++)
    {
        GPIO_u8SetPinMode(Copy_pstructSSD->SSD_u8Port , Local_u8Iter , GPIO_OUTPUT );
    }

    if(Copy_pstructSSD ->SSD_u8Type == SSD_COMMON_ANODE)
    {
      for(u8 Local_u8Iter = Copy_pstructSSD->SSD_u8InPin ; Local_u8Iter <= Copy_pstructSSD->SSD_u8EndPin ; Local_u8Iter++)
        {
            GPIO_u8SetPinValue(Copy_pstructSSD->SSD_u8Port , Local_u8Iter , GPIO_HIGH );
        }  
    }
    else if(Copy_pstructSSD ->SSD_u8Type == SSD_COMMON_CATHODE)
    {
        for(u8 Local_u8Iter = Copy_pstructSSD->SSD_u8InPin ; Local_u8Iter <= Copy_pstructSSD->SSD_u8EndPin ; Local_u8Iter++)
        {
            GPIO_u8SetPinValue(Copy_pstructSSD->SSD_u8Port , Local_u8Iter , GPIO_LOW );
        } 
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }

    return Local_u8ErrorState ;
}

u8 SSD_u8SendNumber (SSD_type* Copy_pstructSSD , u8 Copy_u8Number  )
{
    u8 Local_u8ErrorState ; 
    if(Copy_pstructSSD ->SSD_u8Type == SSD_COMMON_ANODE)
    {
      for(u8 Local_u8Iter = 0 ; Local_u8Iter <= 7 ; Local_u8Iter++)
        {
            GPIO_u8SetPinValue(Copy_pstructSSD->SSD_u8Port , (Copy_pstructSSD->SSD_u8InPin +Local_u8Iter) , !GET_BIT(SSD_ArrNumbers[Copy_u8Number],Local_u8Iter) );
        }  
    }
    else if(Copy_pstructSSD ->SSD_u8Type == SSD_COMMON_CATHODE)
    {
        for(u8 Local_u8Iter = 0 ; Local_u8Iter <= 7 ; Local_u8Iter++)
        {
            GPIO_u8SetPinValue(Copy_pstructSSD->SSD_u8Port , (Copy_pstructSSD->SSD_u8InPin +Local_u8Iter) , GET_BIT(SSD_ArrNumbers[Copy_u8Number],Local_u8Iter) );
        } 
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState ;
}

u8 SSD_u8Disable ( SSD_type* Copy_pstructSSD )
{
    u8 Local_u8ErrorState ; 
    if(Copy_pstructSSD ->SSD_u8Type == SSD_COMMON_ANODE)
    {
      for(u8 Local_u8Iter = 0 ; Local_u8Iter <= 7 ; Local_u8Iter++)
        {
            GPIO_u8SetPinValue(Copy_pstructSSD->SSD_u8Port , (Copy_pstructSSD->SSD_u8InPin +Local_u8Iter) , GPIO_HIGH );
        }  
    }
    else if(Copy_pstructSSD ->SSD_u8Type == SSD_COMMON_CATHODE)
    {
        for(u8 Local_u8Iter = 0 ; Local_u8Iter <= 7 ; Local_u8Iter++)
        {
            GPIO_u8SetPinValue(Copy_pstructSSD->SSD_u8Port , (Copy_pstructSSD->SSD_u8InPin +Local_u8Iter) , GPIO_LOW );
        } 
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState ;
}