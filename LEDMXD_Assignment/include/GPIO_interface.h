/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 12/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : GPIO                 ************/
/****************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/*******MACROS USED IN DRIVER **********/
#define GPIO_PORTA       0
#define GPIO_PORTB       1
#define GPIO_PORTC       2

#define GPIO_PIN0        0 
#define GPIO_PIN1        1 
#define GPIO_PIN2        2 
#define GPIO_PIN3        3 
#define GPIO_PIN4        4 
#define GPIO_PIN5        5 
#define GPIO_PIN6        6 
#define GPIO_PIN7        7 
#define GPIO_PIN8        8 
#define GPIO_PIN9        9 
#define GPIO_PIN10       10
#define GPIO_PIN11       11
#define GPIO_PIN12       12
#define GPIO_PIN13       13
#define GPIO_PIN14       14
#define GPIO_PIN15       15

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
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB , PORTC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Type: GPIO_PUSH_PULL , GPIO_OPEN_DRAIN                              */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinType(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Type );


/******************************************************************/
/*Func. Name: GPIO_u8SetPinSpeed                              */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB , PORTC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Speed: LOW_SPEED , MID_SPEED ,  HIGH_SPEED , V_HIGH_SPEED */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinSpeed(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Speed );

/******************************************************************/
/*Func. Name: GPIO_u8SetPinType                              */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB , PORTC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Value: GPIO_HIGH , GPIO_LOW                              */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Value );

/******************************************************************/
/*Func. Name: GPIO_u8SetPinType                              */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB , PORTC */
/*Copy_u8PinId: PIN0 ==> PIN15                                   */
/*Copy_u8Value: Pointer to returned value variable               */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8* Copy_u8ReturnedData );

/******************************************************************/
/*Func. Name: GPIO_u8SetPortMode                              */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB , PORTC */
/*Copy_u8Mode: GPIO_INPUT , GPIO_OUTPUT                          */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPortMode(u8 Copy_u8PortId  , u8 Copy_u8Mode );
/******************************************************************/
/*Func. Name: GPIO_u8SetPortValue                              */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB , PORTC */
/*Copy_u8Value: GPIO_HIGH , GPIO_LOW                              */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPortValue(u8 Copy_u8PortId  , u8 Copy_u8Value );

/******************************************************************/
/*Func. Name: GPIO_u8GetPortValue                              */
/*i/p arguments: Copy_u8PortId options: PORTA, PORTB , PORTC */
/*Copy_u16ReturnedData: Pointer to returned value variable               */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8GetPortValue(u8 Copy_u8PortId, u16* Copy_u16ReturnedData );

#endif