/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 21/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : LEDMXD                 ************/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMXD_interface.h"
#include "LEDMXD_private.h"
#include "LEDMXD_config.h"

void LEDMXD_voidInit(void) 
{
    /*Set Mode for Rows and columns pins */
    /*Rows*/

    GPIO_u8SetPinMode(LEDMXD_ROW0_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_ROW1_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_ROW2_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_ROW3_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_ROW4_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_ROW5_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_ROW6_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_ROW7_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_ROW8_PIN , GPIO_OUTPUT);

    /*Cols*/
    GPIO_u8SetPinMode(LEDMXD_COL0_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_COL1_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_COL2_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_COL3_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_COL4_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_COL5_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_COL6_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_COL7_PIN , GPIO_OUTPUT);
    GPIO_u8SetPinMode(LEDMXD_COL8_PIN , GPIO_OUTPUT);
    /* PUSH PULL MODE */
    GPIO_u8SetPinType(LEDMXD_ROW0_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_ROW1_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_ROW2_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_ROW3_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_ROW4_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_ROW5_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_ROW6_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_ROW7_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_ROW8_PIN ,GPIO_PUSH_PULL);

    GPIO_u8SetPinType(LEDMXD_COL0_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_COL1_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_COL2_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_COL3_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_COL4_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_COL5_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_COL6_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_COL7_PIN ,GPIO_PUSH_PULL);
    GPIO_u8SetPinType(LEDMXD_COL8_PIN ,GPIO_PUSH_PULL);
 
}

u8 LEDMXD_u8Display ( u8* Copy_pu8Data  )
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    u8 Local_u8Value ;
    if(Copy_pu8Data != NULL)
    {
        /*1. Disable All Columns */
        LEDMXD_voidDisableAllColumns() ;
        /* Set Row Value */
        LEDMXD_voidSetRowValues(Copy_pu8Data[0] );
        /*Activate Column */
       // GPIO_u8SetPinValue(LEDMXD_COL0_PIN , GPIO_LOW);
        STP_voidSendSynchronus(0b11111110);
        /*Delay for 2.5ms*/
        STK_voidSetBusyWait(2500);

        /*1. Disable All Columns */
        LEDMXD_voidDisableAllColumns() ;
        /* Set Row Value */
        LEDMXD_voidSetRowValues(Copy_pu8Data[1] );
        /*Activate Column */
      //  GPIO_u8SetPinValue(LEDMXD_COL1_PIN , GPIO_LOW);
        STP_voidSendSynchronus(0b11111101);

        /*Delay for 2.5ms*/
        STK_voidSetBusyWait(2500);

        /*1. Disable All Columns */
        LEDMXD_voidDisableAllColumns() ;
        /* Set Row Value */
        LEDMXD_voidSetRowValues(Copy_pu8Data[2] );
        /*Activate Column */
        //GPIO_u8SetPinValue(LEDMXD_COL2_PIN , GPIO_LOW);
        STP_voidSendSynchronus(0b11111011);

        /*Delay for 2.5ms*/
        STK_voidSetBusyWait(2500);

        /*1. Disable All Columns */
        LEDMXD_voidDisableAllColumns() ;
        /* Set Row Value */
        LEDMXD_voidSetRowValues(Copy_pu8Data[3] );
        /*Activate Column */
        //GPIO_u8SetPinValue(LEDMXD_COL3_PIN , GPIO_LOW);
        STP_voidSendSynchronus(0b11110111);

        /*Delay for 2.5ms*/
        STK_voidSetBusyWait(2500);

        /*1. Disable All Columns */
        LEDMXD_voidDisableAllColumns() ;
        /* Set Row Value */
        LEDMXD_voidSetRowValues(Copy_pu8Data[4] );
        /*Activate Column */
//        GPIO_u8SetPinValue(LEDMXD_COL4_PIN , GPIO_LOW);
        STP_voidSendSynchronus(0b11101111);

        /*Delay for 2.5ms*/
        STK_voidSetBusyWait(2500);

        /*1. Disable All Columns */
        LEDMXD_voidDisableAllColumns() ;
        /* Set Row Value */
        LEDMXD_voidSetRowValues(Copy_pu8Data[5] );
        /*Activate Column */
        //GPIO_u8SetPinValue(LEDMXD_COL5_PIN , GPIO_LOW);
        STP_voidSendSynchronus(0b11011111);

        /*Delay for 2.5ms*/
        STK_voidSetBusyWait(2500);

        /*1. Disable All Columns */
        LEDMXD_voidDisableAllColumns() ;
        /* Set Row Value */
        LEDMXD_voidSetRowValues(Copy_pu8Data[6] );
        /*Activate Column */
        //GPIO_u8SetPinValue(LEDMXD_COL6_PIN , GPIO_LOW);
        STP_voidSendSynchronus(0b10111111);

        /*Delay for 2.5ms*/
        STK_voidSetBusyWait(2500);

        /*1. Disable All Columns */
        LEDMXD_voidDisableAllColumns() ;
        /* Set Row Value */
        LEDMXD_voidSetRowValues(Copy_pu8Data[7] );
        /*Activate Column */
//        GPIO_u8SetPinValue(LEDMXD_COL7_PIN , GPIO_LOW);
        STP_voidSendSynchronus(0b01111111);

        /*Delay for 2.5ms*/
        STK_voidSetBusyWait(2500);
        

    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    return Local_u8ErrorState ;

}
static void LEDMXD_voidDisableAllColumns ( void )
{
        /* Disable All Columns */
//        GPIO_u8SetPinValue(LEDMXD_COL0_PIN,GPIO_HIGH);
//        GPIO_u8SetPinValue(LEDMXD_COL1_PIN,GPIO_HIGH);
//        GPIO_u8SetPinValue(LEDMXD_COL2_PIN,GPIO_HIGH);
//        GPIO_u8SetPinValue(LEDMXD_COL3_PIN,GPIO_HIGH);
//        GPIO_u8SetPinValue(LEDMXD_COL4_PIN,GPIO_HIGH);
//        GPIO_u8SetPinValue(LEDMXD_COL5_PIN,GPIO_HIGH);
//        GPIO_u8SetPinValue(LEDMXD_COL6_PIN,GPIO_HIGH);
//        GPIO_u8SetPinValue(LEDMXD_COL7_PIN,GPIO_HIGH);
	STP_voidSendSynchronus(0xff);

}
static void LEDMXD_voidSetRowValues(u8 Copy_u8Value )
{
  //  u8 Local_u8Value ;
    STP_voidSendSynchronus(Copy_u8Value);
//    Local_u8Value = GET_BIT(Copy_u8Value,0);
//    GPIO_u8SetPinValue(LEDMXD_ROW0_PIN , Local_u8Value );
//    Local_u8Value = GET_BIT(Copy_u8Value,1);
//    GPIO_u8SetPinValue(LEDMXD_ROW1_PIN , Local_u8Value );
//    Local_u8Value = GET_BIT(Copy_u8Value,2);
//    GPIO_u8SetPinValue(LEDMXD_ROW2_PIN , Local_u8Value );
//    Local_u8Value = GET_BIT(Copy_u8Value,3);
//    GPIO_u8SetPinValue(LEDMXD_ROW3_PIN , Local_u8Value );
//    Local_u8Value = GET_BIT(Copy_u8Value,4);
//    GPIO_u8SetPinValue(LEDMXD_ROW4_PIN , Local_u8Value );
//    Local_u8Value = GET_BIT(Copy_u8Value,5);
//    GPIO_u8SetPinValue(LEDMXD_ROW5_PIN , Local_u8Value );
//    Local_u8Value = GET_BIT(Copy_u8Value,6);
//    GPIO_u8SetPinValue(LEDMXD_ROW6_PIN , Local_u8Value );
//    Local_u8Value = GET_BIT(Copy_u8Value,7);
//    GPIO_u8SetPinValue(LEDMXD_ROW7_PIN , Local_u8Value );
}
