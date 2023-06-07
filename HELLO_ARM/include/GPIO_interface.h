/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 12/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : GPIO                 ************/
/****************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*******MACROS USED IN DRIVER **********/
#define PORTA       0
#define PORTB       1
#define PORTC       2

#define PIN0        0 
#define PIN1        1 
#define PIN2        2 
#define PIN3        3 
#define PIN4        4 
#define PIN5        5 
#define PIN6        6 
#define PIN7        7 
#define PIN8        8 
#define PIN9        9 
#define PIN10       10
#define PIN11       11
#define PIN12       12
#define PIN13       13
#define PIN14       14
#define PIN15       15

#define GPIO_INPUT      0
#define GPIO_OUTPUT     1
#define GPIO_ALTER_FUN  2
#define GPIO_ANALOG     3

#define GPIO_PUSH_PULL       0
#define GPIO_OPEN_DRAIN      1

#define LOW_SPEED           0
#define MID_SPEED           1
#define HIGH_SPEED          2
#define V_HIGH_SPEED        3

#define GPIO_HIGH           1
#define GPIO_LOW            0
/*******************************************************/

/******************************************************************/
/*Func. Name: GPIO_voidSetPinMode                              */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB , PORTC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Mode: GPIO_INPUT , GPIO_OUTPUT                                   */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinMode(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Mode );

/******************************************************************/
/*Func. Name: GPIO_u8SetPinType                              */
/*i/p arguments: Copy_u8PortId options: GPIOA, GPIOB , GPIOC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Type: GPIO_PUSH_PULL , GPIO_OPEN_DRAIN                              */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinType(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Type );


/******************************************************************/
/*Func. Name: GPIO_u8SetPinSpeed                              */
/*i/p arguments: Copy_u8PortId options: GPIOA, GPIOB , GPIOC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Speed: LOW_SPEED , MID_SPEED ,  HIGH_SPEED , V_HIGH_SPEED */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinSpeed(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Speed );

/******************************************************************/
/*Func. Name: GPIO_u8SetPinType                              */
/*i/p arguments: Copy_u8PortId options: GPIOA, GPIOB , GPIOC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Value: HIGH , LOW                              */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Value );

/******************************************************************/
/*Func. Name: GPIO_u8SetPinType                              */
/*i/p arguments: Copy_u8PortId options: GPIOA, GPIOB , GPIOC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Value: Pointer to returned value variable               */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8* ReturnedData );

#endif