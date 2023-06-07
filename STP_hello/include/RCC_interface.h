/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 10/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : RCC         **********/
/****************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

void RCC_voidInitSysClk (void);

u8 RCC_u8EnablePeripheralClock(u8 Copy_u8BusId , u8 Copy_u8PerId);
u8 RCC_u8DisablePeripheralClock(u8 Copy_u8BusId , u8 Copy_u8PerId);

/* Macros for Busses */
#define RCC_u8_AHB2_BUS		0
#define RCC_u8_AHB1_BUS		1
#define RCC_u8_APB1_BUS		2
#define RCC_u8_APB2_BUS		3

/* Macros for peripherals id in AHB1 bus*/
#define RCC_u8_GPIO_A	0
#define RCC_u8_GPIO_B	1
#define RCC_u8_GPIO_C	2
#define RCC_u8_GPIO_D	3
#define RCC_u8_GPIO_E	4
#define RCC_u8_GPIO_H	7
#define RCC_u8_CRC		12
#define RCC_u8_DMA1		21
#define RCC_u8_DMA2		22

/* Macros for peripherals id in APB2 bus*/
#define RCC_u8_TIM_1	0
#define RCC_u8_USART_1	4
#define RCC_u8_USART_6	5
#define RCC_u8_ADC_1	8
#define RCC_u8_SDIO 	11
#define RCC_u8_SPI_1	12
#define RCC_u8_SPI_4	13
#define RCC_u8_SYSCFG	14  
#define RCC_u8_TIM_9	16
#define RCC_u8_TIM_10	17
#define RCC_u8_TIM_11	18

/* Macros for peripherals id in APB1 bus*/
#define RCC_u8_TIM_2	0
#define RCC_u8_TIM_3	1
#define RCC_u8_TIM_4	2
#define RCC_u8_TIM_5	3
#define RCC_u8_WWDG 	11
#define RCC_u8_SPI_2	14
#define RCC_u8_SPI_3	15
#define RCC_u8_UART_2	17
#define RCC_u8_I2C_1	21
#define RCC_u8_I2C_2	22
#define RCC_u8_I2C_3	23
#define RCC_u8_PWR	    28



#endif