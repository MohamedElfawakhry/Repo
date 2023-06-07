/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 12/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : SSD                 ************/
/****************************************************/

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_H

/* Struct includes 
    1. SSD_PORT             options : PORTA , PORTB , PORTC
    2. SSD_INIT_PIN         options : PIN0 => PIN15
    3. SSD_END_PIN          options : PIN0 => PIN15
    4. SSD_TYPE             options : SSD_COMMON_ANODE , SSD_COMMON_CATHODE
*/  
#define SSD_COMMON_ANODE        1
#define SSD_COMMON_CATHODE      0
typedef struct 
{
    u8 SSD_u8Port ;
    u8 SSD_u8InPin ;
    u8 SSD_u8EndPin ;
    u8 SSD_u8Type ;
}SSD_type;

#define ZERO 	0b00111111
#define ONE		0b00000110
#define TWO		0b01011011
#define THREE	0b01001111
#define FOUR	0b01100110
#define FIVE	0b01101101
#define SIX		0b01111101
#define SEVEN	0b00000111
#define EIGHT	0b01111111
#define NINE 	0b01101111

u8 SSD_u8Init(SSD_type* Copy_pstructSSD ) ;

u8 SSD_u8SendNumber (SSD_type* Copy_pstructSSD , u8 Copy_u8Number  );

u8 SSD_u8Disable ( SSD_type* Copy_pstructSSD );



#endif