/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 21/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : LEDMXD                 ************/
/****************************************************/

#ifndef LEDMXD_CONFIG_H
#define LEDMXD_CONFIG_H

/* Options: 
    GPIO_PORTA, GPIO_PIN0 ..... GPIO_PIN15
    GPIO_PORTB, GPIO_PIN0 ..... GPIO_PIN15
    GPIO_PORTC, GPIO_PIN0 ..... GPIO_PIN15
*/

#define LEDMXD_ROW0_PIN         GPIO_PORTA,GPIO_PIN0
#define LEDMXD_ROW1_PIN         GPIO_PORTA,GPIO_PIN1
#define LEDMXD_ROW2_PIN         GPIO_PORTA,GPIO_PIN2
#define LEDMXD_ROW3_PIN         GPIO_PORTA,GPIO_PIN3
#define LEDMXD_ROW4_PIN         GPIO_PORTA,GPIO_PIN4
#define LEDMXD_ROW5_PIN         GPIO_PORTA,GPIO_PIN5
#define LEDMXD_ROW6_PIN         GPIO_PORTA,GPIO_PIN6
#define LEDMXD_ROW7_PIN         GPIO_PORTA,GPIO_PIN7


#define LEDMXD_COL0_PIN         GPIO_PORTB,GPIO_PIN0
#define LEDMXD_COL1_PIN         GPIO_PORTB,GPIO_PIN1
#define LEDMXD_COL2_PIN         GPIO_PORTB,GPIO_PIN5
#define LEDMXD_COL3_PIN         GPIO_PORTB,GPIO_PIN6
#define LEDMXD_COL4_PIN         GPIO_PORTB,GPIO_PIN7
#define LEDMXD_COL5_PIN         GPIO_PORTB,GPIO_PIN8
#define LEDMXD_COL6_PIN         GPIO_PORTB,GPIO_PIN9
#define LEDMXD_COL7_PIN         GPIO_PORTB,GPIO_PIN10



#endif
