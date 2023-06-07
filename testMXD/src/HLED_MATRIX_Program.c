/*
 * HLED_MATRIX_Program.c
 *
 *  Created on: Aug 28, 2022
 *      Author: ahmed.hammad
 */

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"


/*******************************************************************************************************/
/*                                      HAL Components                                                */
/*******************************************************************************************************/
#include "HLED_MATRIX_Interface.h"
#include "HLED_MATRIX_Config.h"
#include "HLED_MATRIX_Private.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/



void HLEDMAT_voidInit(void)
{
	/*Set Mode For Row --> Output*/
	GPIO_u8SetPinMode(HLEDMAT_ROW0,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_ROW1,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_ROW2,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_ROW3,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_ROW4,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_ROW5,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_ROW6,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_ROW7,GPIO_OUTPUT) ;

	/*Set Mode For Col --> Output*/
	GPIO_u8SetPinMode(HLEDMAT_COL0,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_COL1,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_COL2,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_COL3,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_COL4,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_COL5,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_COL6,GPIO_OUTPUT) ;
	GPIO_u8SetPinMode(HLEDMAT_COL7,GPIO_OUTPUT) ;

	/*Set PushPull For Rows*/
	GPIO_u8SetPinType(HLEDMAT_ROW0,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_ROW1,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_ROW2,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_ROW3,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_ROW4,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_ROW5,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_ROW6,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_ROW7,GPIO_PUSH_PULL) ;

	/*Set PushPull For Col */
	GPIO_u8SetPinType(HLEDMAT_COL0,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_COL1,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_COL2,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_COL3,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_COL4,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_COL5,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_COL6,GPIO_PUSH_PULL) ;
	GPIO_u8SetPinType(HLEDMAT_COL7,GPIO_PUSH_PULL) ;

//	/*Set Pin Speed ForRows*/
//	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW0,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW1,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW2,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW3,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW4,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW5,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW6,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_ROW7,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//
//	/*Set Pin Speed For Col */
//	MGPIO_voidSetOutputSpeed(HLEDMAT_COL0,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_COL1,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_COL2,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_COL3,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_COL4,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_COL5,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_COL6,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//	MGPIO_voidSetOutputSpeed(HLEDMAT_COL7,MGPIO_OUTPUT_SPEED_MEDUIM) ;
//
}

void HLEDMAT_voidDisplay(u8 *Copy_u8Frame)
{
	/*Column 0*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[0]) ;
	/*Enable Column0 */
	GPIO_u8SetPinValue(HLEDMAT_COL0,GPIO_LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 1*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[1]) ;
	/*Enable Column0 */
	GPIO_u8SetPinValue(HLEDMAT_COL1,GPIO_LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 2*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[2]) ;
	/*Enable Column0 */
	GPIO_u8SetPinValue(HLEDMAT_COL2,GPIO_LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 3*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[3]) ;
	/*Enable Column0 */
	GPIO_u8SetPinValue(HLEDMAT_COL3,GPIO_LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 4*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[4]) ;
	/*Enable Column0 */
	GPIO_u8SetPinValue(HLEDMAT_COL4,GPIO_LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 5*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[5]) ;
	/*Enable Column0 */
	GPIO_u8SetPinValue(HLEDMAT_COL5,GPIO_LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms


	/*Column 6*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[6]) ;
	/*Enable Column0 */
	GPIO_u8SetPinValue(HLEDMAT_COL6,GPIO_LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

	/*Column 7*/
	/*Disable All Columns*/
	HLEDMAT_voidDisableCols() ;
	/*Set Row Value*/
	HLEDMAT_voidSetRowVlaues(Copy_u8Frame[7]) ;
	/*Enable Column0 */
	GPIO_u8SetPinValue(HLEDMAT_COL7,GPIO_LOW) ;
	//Delay 1042 us
	STK_voidSetBusyWait(2500) ; //2.5ms

}


static void HLEDMAT_voidDisableCols(void)
{
	GPIO_u8SetPinValue(HLEDMAT_COL0,GPIO_HIGH) ;
	GPIO_u8SetPinValue(HLEDMAT_COL1,GPIO_HIGH) ;
	GPIO_u8SetPinValue(HLEDMAT_COL2,GPIO_HIGH) ;
	GPIO_u8SetPinValue(HLEDMAT_COL3,GPIO_HIGH) ;
	GPIO_u8SetPinValue(HLEDMAT_COL4,GPIO_HIGH) ;
	GPIO_u8SetPinValue(HLEDMAT_COL5,GPIO_HIGH) ;
	GPIO_u8SetPinValue(HLEDMAT_COL6,GPIO_HIGH) ;
	GPIO_u8SetPinValue(HLEDMAT_COL7,GPIO_HIGH) ;
}

static void HLEDMAT_voidSetRowVlaues(u8 Copy_u8Frame)
{
	GPIO_u8SetPinValue(HLEDMAT_ROW0,GET_BIT(Copy_u8Frame,0)) ;
	GPIO_u8SetPinValue(HLEDMAT_ROW1,GET_BIT(Copy_u8Frame,1)) ;
	GPIO_u8SetPinValue(HLEDMAT_ROW2,GET_BIT(Copy_u8Frame,2)) ;
	GPIO_u8SetPinValue(HLEDMAT_ROW3,GET_BIT(Copy_u8Frame,3)) ;
	GPIO_u8SetPinValue(HLEDMAT_ROW4,GET_BIT(Copy_u8Frame,4)) ;
	GPIO_u8SetPinValue(HLEDMAT_ROW5,GET_BIT(Copy_u8Frame,5)) ;
	GPIO_u8SetPinValue(HLEDMAT_ROW6,GET_BIT(Copy_u8Frame,6)) ;
	GPIO_u8SetPinValue(HLEDMAT_ROW7,GET_BIT(Copy_u8Frame,7)) ;
}

