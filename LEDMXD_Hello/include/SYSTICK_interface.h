/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 10/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : SYSTICK                 ************/
/****************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#define SYSTICK_AHB_PRESCALED_8     0
#define SYSTICK_AHB                 1
#define SYSTICK_CLOCK_SOURCE        SYSTICK_AHB

void STK_voidInit( void );
void STK_voidSetBusyWait (u32 Copy_u32Ticks );
void STK_voidSetIntervalSingle (u32 Copy_u32Ticks , void (*Copy_ptr)(void));
void STK_voidSetIntervalPeriodic (u32 Copy_u32Ticks , void (*Copy_ptr)(void));
void STK_voidStopInterval(void);
u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemainingTime(void);

#endif
