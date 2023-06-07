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
#define SYSTICK_CLOCK_SOURCE        SYSTICK_AHB_PRESCALED_8

void STK_voidInit( void );
void STK_voidSetBusyWait (u32 Copy_u32Ticks );
void STK_voidSetIntervalSingle (u32 Copy_u32Ticks , void (*Copy_pf)(void));
void STK_voidSetIntervalPeriodic (u32 Copy_u32Ticks , void (*Copy_pf)(void));
void STK_voidStopInterval(void);
u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemainingTime(void);
void STK_voidStart ( u32 Copy_u32PreloadValue);

u8 STK_voidReadFlag (void);

void STK_voidCtrlIntStateEnable(void);
void STK_voidSetCallBackFunc(void (*Lpf)( void ));
#endif
