/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 2/6/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : STP                 ************/
/****************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void STP_voidInit(void)
{
    /*Configure Pins A0 , A1 , A2  as o/p pins , push pull*/
    GPIO_u8SetPinMode(STP_SERIAL_DATA , GPIO_OUTPUT);
    GPIO_u8SetPinMode(STP_STORE_CLOCK , GPIO_OUTPUT);
    GPIO_u8SetPinMode(STP_SHIFT_CLOCK , GPIO_OUTPUT);

}

void STP_voidSendSynchronus(u8 Copy_u8DataToBeSent)
{
    u8 Local_u8Counter  ;
    u8 Local_u8Bit      ;
    for(Local_u8Counter = 0 ; Local_u8Counter < 8; Local_u8Counter++)
    {
        Local_u8Bit = GET_BIT(Copy_u8DataToBeSent , 7-Local_u8Counter) ;
        
        GPIO_u8SetPinValue(STP_SERIAL_DATA , Local_u8Bit);

        /*Send Pulse to shift clock */
        GPIO_u8SetPinValue(STP_SHIFT_CLOCK , GPIO_HIGH);
        STK_voidSetBusyWait(1);
        GPIO_u8SetPinValue(STP_SHIFT_CLOCK , GPIO_LOW);
        STK_voidSetBusyWait(1);
    }
    /*Send Pulse to Store clock */
        GPIO_u8SetPinValue(STP_STORE_CLOCK , GPIO_HIGH);
        STK_voidSetBusyWait(1);
        GPIO_u8SetPinValue(STP_STORE_CLOCK , GPIO_LOW);
        STK_voidSetBusyWait(1);
}