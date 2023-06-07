/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 24/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : MyScheduler                 ************/
/****************************************************/
#ifndef MyScheduler_PRIVATE_H
#define MyScheduler_PRIVATE_H

typedef struct 
{
    void (*pf)(void);
    u32 First_Delay ;
    u32 Periodicity ;

}TCB_t;

TCB_t   Task_Arr[No_Of_Tasks] = {NULL};

static void MySchduler_voidScheduler (void);

#endif