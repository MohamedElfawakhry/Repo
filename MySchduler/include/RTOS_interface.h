/*
 * RTOS_interface.h
 *
 *  Created on: Apr 19, 2023
 *      Author: First
 */

#ifndef SRV_RTOS_RTOS_INTERFACE_H_
#define SRV_RTOS_RTOS_INTERFACE_H_

#define RTOS_MAX_TASKS		3

void RTOS_voidInit(void);

u8 RTOS_u8CreateTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity , u16 Copy_u16FirstDelay,void(*Copy_pf)(void));



#endif /* SRV_RTOS_RTOS_INTERFACE_H_ */
