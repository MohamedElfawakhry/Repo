/*
 * HLED_MATRIX_Config.h
 *
 *  Created on: Aug 28, 2022
 *      Author: ahmed.hammad
 */

#ifndef HLED_MATRIX_CONFIG_H_
#define HLED_MATRIX_CONFIG_H_


/*Please write port,pin in pair*/


#define HLEDMAT_ROW0      GPIO_PORTA,GPIO_PIN0
#define HLEDMAT_ROW1      GPIO_PORTA,GPIO_PIN1
#define HLEDMAT_ROW2      GPIO_PORTA,GPIO_PIN2
#define HLEDMAT_ROW3      GPIO_PORTA,GPIO_PIN3
#define HLEDMAT_ROW4      GPIO_PORTA,GPIO_PIN4
#define HLEDMAT_ROW5      GPIO_PORTA,GPIO_PIN5
#define HLEDMAT_ROW6      GPIO_PORTA,GPIO_PIN6
#define HLEDMAT_ROW7      GPIO_PORTA,GPIO_PIN7

/*Please write port,pin in pair*/


#define HLEDMAT_COL0      GPIO_PORTB,GPIO_PIN0
#define HLEDMAT_COL1      GPIO_PORTB,GPIO_PIN1
#define HLEDMAT_COL2      GPIO_PORTB,GPIO_PIN5     // 3 for jtag
#define HLEDMAT_COL3      GPIO_PORTB,GPIO_PIN6     // 4 for jtagA
#define HLEDMAT_COL4      GPIO_PORTB,GPIO_PIN7
#define HLEDMAT_COL5      GPIO_PORTB,GPIO_PIN8
#define HLEDMAT_COL6      GPIO_PORTB,GPIO_PIN9
#define HLEDMAT_COL7      GPIO_PORTB,GPIO_PIN10



#endif /* HLED_MATRIX_CONFIG_H_ */
