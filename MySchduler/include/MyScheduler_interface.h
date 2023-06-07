/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 24/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : MyScheduler                 ************/
/****************************************************/
#ifndef MyScheduler_INTERFACE_H
#define MyScheduler_INTERFACE_H



void MySchduler_voidStartOs(void);

u8 MySchduler_u8CreateTask(u8 Copy_u8TaskId,u16 Copy_u32Periodicity , u16 Copy_u32FirstDelay,void(*Copy_pf)(void));

static void MySchduler_voidScheduler (void);


#endif