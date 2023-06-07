/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 24/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : MyScheduler         ************/
/****************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "MyScheduler_interface.h"
#include "MyScheduler_config.h"
#include "MyScheduler_private.h"


void MySchduler_voidStartOs(void)
{
    STK_voidInit();
    STK_voidCtrlIntStateEnable();
    STK_voidSetCallBackFunc(MySchduler_voidScheduler);
    /* interrupt after 1 mSecond*/
    STK_voidStart(2000);
}

u8 MySchduler_u8CreateTask(u8 Copy_u8TaskId,u16 Copy_u32Periodicity , u16 Copy_u32FirstDelay,void(*Copy_pf)(void))
{
    u8 Local_u8ErrorState = STD_TYPES_OK;
    if(Copy_u8TaskId < No_Of_Tasks)
    {
        Task_Arr[Copy_u8TaskId].First_Delay = Copy_u32FirstDelay;
        Task_Arr[Copy_u8TaskId].Periodicity = Copy_u32Periodicity;
        Task_Arr[Copy_u8TaskId].pf = Copy_pf ;
        
    }
    else
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }



    return Local_u8ErrorState ;
}

static void MySchduler_voidScheduler (void)
{
    u8 Local_u8Count    =   0   ;
    for(Local_u8Count = 0   ;   Local_u8Count < No_Of_Tasks ; Local_u8Count++)
    {
        if((Task_Arr[Local_u8Count].First_Delay == 0) && (Task_Arr[Local_u8Count].pf != NULL))
        {
            Task_Arr[Local_u8Count].pf();
            Task_Arr[Local_u8Count].First_Delay = Task_Arr[Local_u8Count].Periodicity - 1  ;
        }
        else
        {
            Task_Arr[Local_u8Count].First_Delay -- ;
        }
    }
}
