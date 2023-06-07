/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 18/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : NVIC                 ************/
/****************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define GROUP4BITS_SUBGROUP0BITS    0b011
#define GROUP3BITS_SUBGROUP1BITS    0b100
#define GROUP2BITS_SUBGROUP2BITS    0b101
#define GROUP1BITS_SUBGROUP3BITS    0b110
#define GROUP0BITS_SUBGROUP4BITS    0b111

/*****************************************************************************************/
/*                         MACROS For Peripherals in Vector Table                        */
/*****************************************************************************************/
#define NVIC_u8_WWDT                                0
#define NVIC_u8_EXTI16_PVD                          1
#define NVIC_u8_EXTI21_TAMP_STAP                    2
#define NVIC_u8_EXTI22_RTC_WKUP                     3
#define NVIC_u8_FLASH                               4
#define NVIC_u8_RCC                                 5
#define NVIC_u8_EXTI0                               6
#define NVIC_u8_EXTI1                               7
#define NVIC_u8_EXTI2                               8
#define NVIC_u8_EXTI3                               9
#define NVIC_u8_EXTI4                               10
#define NVIC_u8_DMA1_STREAM_0                       11
#define NVIC_u8_DMA1_STREAM_1                       12
#define NVIC_u8_DMA1_STREAM_2                       13
#define NVIC_u8_DMA1_STREAM_3                       14
#define NVIC_u8_DMA1_STREAM_4                       15
#define NVIC_u8_DMA1_STREAM_5                       16
#define NVIC_u8_DMA1_STREAM_6                       17
#define NVIC_u8_ADC                                 18
#define NVIC_u8_EXTI9_5                             23

#define NVIC_u8_USART1                              37
#define NVIC_u8_USART2                              38
/*****************************************************************************************/



void NVIC_voidEnablePerInt ( u8 Copy_u8IntId);
void NVIC_voidDisablePerInt ( u8 Copy_u8IntId);
void NVIC_voidSetPendingFlag ( u8 Copy_u8IntId);
void NVIC_voidClearPendingFlag ( u8 Copy_u8IntId);
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption);
void NVIC_voidSetPeriPriority ( u8 Copy_u8Intid , u8 Copy_u8GroupId , u8 Copy_u8SubGroupId);


#endif