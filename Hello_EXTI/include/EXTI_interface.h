/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 19/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : EXTI                ************/
/****************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_u8_GPIOA       0
#define EXTI_u8_GPIOB       1
#define EXTI_u8_GPIOC       2

#define EXTI_u8_PIN0        0
#define EXTI_u8_PIN1        1 
#define EXTI_u8_PIN2        2 
#define EXTI_u8_PIN3        3 
#define EXTI_u8_PIN4        4 
#define EXTI_u8_PIN5        5 
#define EXTI_u8_PIN6        6 
#define EXTI_u8_PIN7        7 
#define EXTI_u8_PIN8        8 
#define EXTI_u8_PIN9        9 
#define EXTI_u8_PIN10       10
#define EXTI_u8_PIN11       11
#define EXTI_u8_PIN12       12
#define EXTI_u8_PIN13       13
#define EXTI_u8_PIN14       14
#define EXTI_u8_PIN15       15

#define EXTI_u8_RAISING_EDGE    0
#define EXTI_u8_FALLING_EDGE    1
#define EXTI_u8_ON_CHANGE       2

#define EXTI_u8_EXTI0           0
#define EXTI_u8_EXTI1           1
#define EXTI_u8_EXTI2           2
#define EXTI_u8_EXTI3           3
#define EXTI_u8_EXTI4           4


typedef struct 
{
    u8 PortId ;
    u8 PinId  ;
    u8 TriggerLevel ;
    void (*pf)(void);
}EXTI_PinConfig_t ;

u8 EXTI_u8PinInit           (const EXTI_PinConfig_t * Copy_pstrPinInit );

u8 EXTI_u8IntEnable         (u8 Copy_u8EXTINum) ;

u8 EXTI_u8IntDisable         (u8 Copy_u8EXTINum) ;

u8 EXTI_u8ClearPendingFlag  (u8 Copy_u8EXTINum) ;

u8 EXTI_u8SetSoftwareInt    (u8 Copy_u8EXTINum) ;


#endif