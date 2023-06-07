/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 10/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : stm32f401cc.h         **********/
/****************************************************/

#ifndef STM32F401CC_H_
#define STM32F401CC_H_

/*************************  RCC REGISTERS ***********************/
#define RCC_u32_BASE_ADDRESS        0x40023800
typedef struct  
{
    volatile u32 CR ; 
    volatile u32 PLLCFGR ;
    volatile u32 CFGR ;
    volatile u32 CIR ;
    volatile u32 AHB1RSTR ;
    volatile u32 AHB2RSTR ;
    volatile u32 RESERVED1 ;
    volatile u32 RESERVED2 ;
    volatile u32 APB1RSTR ;
    volatile u32 APB2RSTR ;
    volatile u32 RESERVED3 ;
    volatile u32 RESERVED4 ;
    volatile u32 AHB1ENR ;
    volatile u32 AHB2ENR ;
    volatile u32 RESERVED5 ;
    volatile u32 RESERVED6 ;
    volatile u32 APB1ENR ;
    volatile u32 APB2ENR ;
    volatile u32 RESERVED7 ;
    volatile u32 RESERVED8 ;
    volatile u32 AHB1LPENR ;
    volatile u32 AHB2LPENR ;
    volatile u32 RESERVED9 ;
    volatile u32 RESERVED10 ;
    volatile u32 APB1LPENR ;
    volatile u32 APB2LPENR ;
    volatile u32 RESERVED11 ;
    volatile u32 RESERVED12 ;
    volatile u32 BDCR ;
    volatile u32 CSR ;
    volatile u32 RESERVED13 ;
    volatile u32 RESERVED14 ;
    volatile u32 SSCGR ;
    volatile u32 PLLI2SCFGR ;
    volatile u32 RESERVED15 ;
    volatile u32 DCKCFGR ;
}RCC_RegDef_t ;

#define RCC         ((RCC_RegDef_t*)RCC_u32_BASE_ADDRESS)
/******************************************************************/
/*************************  GPIOA REGISTERS ***********************/
#define GPIOA_u32_BASE_ADDRESS        0x40020000
#define GPIOB_u32_BASE_ADDRESS        0x40020400
#define GPIOC_u32_BASE_ADDRESS        0x40020800

typedef struct
{
    volatile u32 MODER ;
    volatile u32 OTYPER ;
    volatile u32 OSPEEDR ;
    volatile u32 PUPDR ;
    volatile u32 IDR ;
    volatile u32 ODR ;
    volatile u32 BSRR;
    volatile u32 LCKR ;
    volatile u32 AFRL ;
    volatile u32 AFRH ;
}GPIO_RegDef_t ;

#define GPIOA    ((GPIO_RegDef_t*)GPIOA_u32_BASE_ADDRESS)
#define GPIOB    ((GPIO_RegDef_t*)GPIOB_u32_BASE_ADDRESS)
#define GPIOC    ((GPIO_RegDef_t*)GPIOC_u32_BASE_ADDRESS)

/******************************************************************/
/*************************  SYSTIC REGISTERS ***********************/
#define SYSTICK_u32_BASE_ADDRESS        0xE000E010


typedef struct
{
    volatile u32 CTRL ;
    volatile u32 LOAD ;
    volatile u32 VAL ;
    volatile u32 CALIB ;
}SYSTICK_RegDef_t ;

#define SYSTICK    ((SYSTICK_RegDef_t*)SYSTICK_u32_BASE_ADDRESS)
/******************************************************************/
/*************************  NVIC REGISTERS ***********************/
#define NVIC_u32_BASE_ADDRESS       0xE000E100

typedef struct 
{
    volatile u32 ISER[32];
    volatile u32 ICER[32];
    volatile u32 ISPR[32];
    volatile u32 ICPR[32];
    volatile u32 IABR[32];
    volatile u32 RESERVED[32];
    //volatile u32 IPR[60];
    volatile u8  IPR[90]; // elmafrod yb2o 240 elly homa 4*60 bytes
}NVIC_RegDef_t ;

#define NVIC        ((NVIC_RegDef_t*)NVIC_u32_BASE_ADDRESS)
/******************************************************************/
/*************************  SCB REGISTERS ***********************/
typedef struct{
    volatile u32  CUPID ;    
    volatile u32  ICSR ;   
    volatile u32  VTOR;   
    volatile u32  AIRCR;   
    volatile u32  SCR;   
    volatile u32  CCR;   
    volatile u32  SHPR[3];
    volatile u32  SHCSR;   
    volatile u32  CFSR;  
    volatile u32  HFSR  ;
    volatile u32  RESERVED ;
    volatile u32  MMFAR;
    volatile u32  BFAR;
}SCB_RegDef_t; 
#define SCB_BASEADDRESS		0xE000ED00

#define SCB     (( SCB_RegDef_t*)SCB_BASEADDRESS)

#endif