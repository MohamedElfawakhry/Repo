/*
 * RTOS_private.h
 *
 *  Created on: Apr 19, 2023
 *      Author: First
 */

#ifndef SRV_RTOS_RTOS_PRIVATE_H_
#define SRV_RTOS_RTOS_PRIVATE_H_

#define RTOS_OK		1
#define RTOS_NOK	0

typedef struct {

	u16 FirstDelay 		;
	u16 Periodicity 	;
	void (*Pf)(void)	;

}RTOS_TCB;

static void RTOS_voidScheduler (void);

#endif /* SRV_RTOS_RTOS_PRIVATE_H_ */
