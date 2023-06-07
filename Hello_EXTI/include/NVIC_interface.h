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

void NVIC_voidEnablePerInt ( u8 Copy_u8IntId);
void NVIC_voidDisablePerInt ( u8 Copy_u8IntId);
void NVIC_voidSetPendingFlag ( u8 Copy_u8IntId);
void NVIC_voidClearPendingFlag ( u8 Copy_u8IntId);
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption);
void NVIC_voidSetPeriPriority ( u8 Copy_u8Intid , u8 Copy_u8GroupId , u8 Copy_u8SubGroupId);


#endif