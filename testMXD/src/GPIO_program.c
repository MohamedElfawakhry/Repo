/****************************************************/
/************ Name    : Mohamed ElFawakhry **********/
/************ Date    : 12/5/2023          **********/
/************ Version  : 1.0v              **********/
/************ SWC  : GPIO                 ************/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "stm32f401cc.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
/******************************************************************/
/*Func. Name: GPIO_voidSetPinMode                              */
/*i/p arguments: Copy_u8PortId options: GPIO_GPIO_GPIO_PORTA, GPIO_PORTB , GPIO_PORTC */
/*Copy_u8PinId: GPIO_PIN0 ==> GPIO_PIN15                                   */
/*Copy_u8Mode: GPIO_INPUT , GPIO OUTPUT ,GPIO_ALTER_FUN, GPIO_ANALOG   */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinMode(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Mode )
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PortId > GPIOC)
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        if(Copy_u8PinId > GPIO_PIN15)
        {
            Local_u8ErrorState = STD_TYPES_NOK ;
        }
        else
        {
            switch (Copy_u8PortId)
            {
            case GPIO_PORTA:
                switch (Copy_u8Mode)
                {
                case GPIO_INPUT:
                    CLR_BIT(GPIOA->MODER , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOA->MODER , (2*Copy_u8PinId) +1 );
                    break;
                case GPIO_OUTPUT:
                    SET_BIT(GPIOA->MODER , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOA->MODER , (2*Copy_u8PinId) +1 );
                    break;
                case GPIO_ALTER_FUN:
                    CLR_BIT(GPIOA->MODER , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOA->MODER , (2*Copy_u8PinId) +1 );
                    break;
                case GPIO_ANALOG:
                    SET_BIT(GPIOA->MODER , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOA->MODER , (2*Copy_u8PinId) +1 );
                    break;
                default: Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
                break;
            case GPIO_PORTB:
                switch (Copy_u8Mode)
                {
                case GPIO_INPUT:
                    CLR_BIT(GPIOB->MODER , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOB->MODER , (2*Copy_u8PinId) +1 );
                    break;
                case GPIO_OUTPUT:
                    SET_BIT(GPIOB->MODER , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOB->MODER , (2*Copy_u8PinId) +1 );
                    break;
                case GPIO_ALTER_FUN:
                    CLR_BIT(GPIOB->MODER , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOB->MODER , (2*Copy_u8PinId) +1 );
                    break;
                case GPIO_ANALOG:
                    SET_BIT(GPIOB->MODER , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOB->MODER , (2*Copy_u8PinId) +1 );
                    break;
                default: Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
                break;
            case GPIO_PORTC:
                if(Copy_u8PinId >=13 && Copy_u8PinId <= 15)
                {
                    switch (Copy_u8Mode)
                    {
                    case GPIO_INPUT:
                        CLR_BIT(GPIOC->MODER , (2*Copy_u8PinId)    );
                        CLR_BIT(GPIOC->MODER , (2*Copy_u8PinId) +1 );
                        break;
                    case GPIO_OUTPUT:
                        SET_BIT(GPIOC->MODER , (2*Copy_u8PinId)    );
                        CLR_BIT(GPIOC->MODER , (2*Copy_u8PinId) +1 );
                        break;
                    case GPIO_ALTER_FUN:
                        CLR_BIT(GPIOC->MODER , (2*Copy_u8PinId)    );
                        SET_BIT(GPIOC->MODER , (2*Copy_u8PinId) +1 );
                        break;
                    case GPIO_ANALOG:
                        SET_BIT(GPIOC->MODER , (2*Copy_u8PinId)    );
                        SET_BIT(GPIOC->MODER , (2*Copy_u8PinId) +1 );
                        break;
                    default: Local_u8ErrorState = STD_TYPES_NOK ;
                        break;
                    }
                }
                
                break;
            default:    Local_u8ErrorState = STD_TYPES_NOK ;
                break;
            }
        }
    }

}

/******************************************************************/
/*Func. Name: GPIO_u8SetPinType                              */
/*i/p arguments: Copy_u8PortId options: GPIO_GPIO_GPIO_PORTA, GPIO_PORTB , GPIO_PORTC */
/*Copy_u8PinId: GPIO_PIN0 ==> GPIO_PIN15                                   */
/*Copy_u8Type: GPIO_PUSH_PULL , GPIO_OPEN_DRAIN                   */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinType(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Type )
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PortId > GPIOC)
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        if(Copy_u8PinId > GPIO_PIN15)
        {
            Local_u8ErrorState = STD_TYPES_NOK ;
        }
        else
        {
            switch (Copy_u8PortId)
            {
            case GPIO_PORTA:
                switch (Copy_u8Type)
                {
                case GPIO_PUSH_PULL: 
                    CLR_BIT(GPIOA->OTYPER , Copy_u8PinId    );
                    break;
                case GPIO_OPEN_DRAIN:
                    SET_BIT(GPIOA->OTYPER , Copy_u8PinId    );
                    break;
               
                }
                break;
            case GPIO_PORTB:
                switch (Copy_u8Type)
                {
                case GPIO_PUSH_PULL: 
                    CLR_BIT(GPIOB->OTYPER , Copy_u8PinId    );
                    break;
                case GPIO_OPEN_DRAIN:
                    SET_BIT(GPIOB->OTYPER , Copy_u8PinId    );
                    break;
               
                }
                break;
            case GPIO_PORTC:
                if(Copy_u8PinId >=13 && Copy_u8PinId <= 15)
                {
                    switch (Copy_u8Type)
                {
                case GPIO_PUSH_PULL: 
                    CLR_BIT(GPIOC->OTYPER , Copy_u8PinId    );
                    break;
                case GPIO_OPEN_DRAIN:
                    SET_BIT(GPIOC->OTYPER , Copy_u8PinId    );
                    break;
               
                }
                }
                
                break;
            default:    Local_u8ErrorState = STD_TYPES_NOK ;
                break;
            }
        }
    }
}


/******************************************************************/
/*Func. Name: GPIO_u8SetPinSpeed                              */
/*i/p arguments: Copy_u8PortId options: GPIO_GPIO_PORTA, GPIO_PORTB , GPIO_PORTC */
/*Copy_u8PinId: GPIO_PIN0 ==> GPIO_PIN15                                   */
/*Copy_u8Speed: LOW_SPEED , MID_SPEED ,  HIGH_SPEED , V_HIGH_SPEED */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinSpeed(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Speed )
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PortId > GPIOC)
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        if(Copy_u8PinId > GPIO_PIN15)
        {
            Local_u8ErrorState = STD_TYPES_NOK ;
        }
        else
        {
            switch (Copy_u8PortId)
            {
            case GPIO_PORTA:
                switch (Copy_u8Speed)
                {
                case LOW_SPEED: 
                    CLR_BIT(GPIOA->OSPEEDR , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOA->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case MID_SPEED:
                    SET_BIT(GPIOA->OSPEEDR , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOA->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case HIGH_SPEED:
                    CLR_BIT(GPIOA->OSPEEDR , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOA->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case V_HIGH_SPEED:
                    SET_BIT(GPIOA->OSPEEDR , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOA->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                default: Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
                break;
            case GPIO_PORTB:
                switch (Copy_u8Speed)
                {
                case LOW_SPEED: 
                    CLR_BIT(GPIOB->OSPEEDR , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOB->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case MID_SPEED:
                    SET_BIT(GPIOB->OSPEEDR , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOB->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case HIGH_SPEED:
                    CLR_BIT(GPIOB->OSPEEDR , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOB->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case V_HIGH_SPEED:
                    SET_BIT(GPIOB->OSPEEDR , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOB->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                default: Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
                break;
            case GPIO_PORTC:
                if(Copy_u8PinId >=13 && Copy_u8PinId <= 15)
                {
                    switch (Copy_u8Speed)
                {
                case LOW_SPEED: 
                    CLR_BIT(GPIOC->OSPEEDR , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOC->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case MID_SPEED:
                    SET_BIT(GPIOC->OSPEEDR , (2*Copy_u8PinId)    );
                    CLR_BIT(GPIOC->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case HIGH_SPEED:
                    CLR_BIT(GPIOC->OSPEEDR , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOC->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                case V_HIGH_SPEED:
                    SET_BIT(GPIOC->OSPEEDR , (2*Copy_u8PinId)    );
                    SET_BIT(GPIOC->OSPEEDR , (2*Copy_u8PinId) +1 );
                    break;
                default: Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
                }
                
                break;
            default:    Local_u8ErrorState = STD_TYPES_NOK ;
                break;
            }
        }
    }
}

/******************************************************************/
/*Func. Name: GPIO_u8SetPinType                              */
/*i/p arguments: Copy_u8PortId options: GPIO_GPIO_PORTA, GPIO_PORTB , GPIO_PORTC */
/*Copy_u8PinId: GPIO_PIN0 ==> GPIO_PIN15                                   */
/*Copy_u8Value: GPIO_HIGH , GPIO_LOW                              */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Value )
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PortId > GPIOC)
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        if(Copy_u8PinId > GPIO_PIN15)
        {
            Local_u8ErrorState = STD_TYPES_NOK ;
        }
        else
        {
            switch (Copy_u8PortId)
            {
            case GPIO_PORTA:
                switch (Copy_u8Value)
                {
                case GPIO_HIGH:
                    GPIOA->BSRR =( 1 << (Copy_u8PinId) ); 
                    break;
                case GPIO_LOW:
                    GPIOA->BSRR =( 1 << (Copy_u8PinId+16) );
                    break;
                
                default: Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
                break;
            case GPIO_PORTB:
                switch (Copy_u8Value)
                {
                case GPIO_HIGH:
                    GPIOB->BSRR =( 1 << Copy_u8PinId ); 
                    break;
                case GPIO_LOW:
                    GPIOB->BSRR =( 1 << (Copy_u8PinId+16) );
                    break;
                
                default: Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
                break;
            case GPIO_PORTC:
                if(Copy_u8PinId >=13 && Copy_u8PinId <= 15)
                {
                    switch (Copy_u8Value)
                {
                case GPIO_HIGH:
                    GPIOC->BSRR =( 1 << Copy_u8PinId ); 
                    break;
                case GPIO_LOW:
                    GPIOC->BSRR =( 1 << (Copy_u8PinId+16) );
                    break;
                
                default: Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
                }
                
                break;
            default:    Local_u8ErrorState = STD_TYPES_NOK ;
                break;
            }
        }
    }
}

/******************************************************************/
/*Func. Name: GPIO_u8SetPinType                              */
/*i/p arguments: Copy_u8PortId options: GPIO_GPIO_PORTA, GPIO_PORTB , GPIO_PORTC */
/*Copy_u8PinId: GPIO_PIN0 ==> GPIO_PIN15                                   */
/*Copy_u8Value: Pointer to returned value variable               */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId , u8* Copy_u8ReturnedData )
{
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PortId > GPIOC)
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        if(Copy_u8PinId > GPIO_PIN15)
        {
            Local_u8ErrorState = STD_TYPES_NOK ;
        }
        else
        {   
            if(Copy_u8ReturnedData != NULL)
            {
                switch (Copy_u8PortId)
                {
                case GPIO_PORTA: 
                    *Copy_u8ReturnedData = GET_BIT(GPIOA->IDR , Copy_u8PinId);
                    break;
                case GPIO_PORTB:
                    *Copy_u8ReturnedData = GET_BIT(GPIOB->IDR , Copy_u8PinId);
                    break;
                case GPIO_PORTC:
                    if(Copy_u8PinId >=13 && Copy_u8PinId <= 15)
                    {
                    *Copy_u8ReturnedData = GET_BIT(GPIOC->IDR , Copy_u8PinId);
                    }

                    break;
                default:    Local_u8ErrorState = STD_TYPES_NOK ;
                    break;
                }
            }
            else
            {
                Local_u8ErrorState = STD_TYPES_NOK ;
            }
        }
    } 
}
/******************************************************************/
/*Func. Name: GPIO_u8SetPortMode                              */
/*i/p arguments: Copy_u8PortId options: GPIO_GPIO_PORTA, GPIO_PORTB , GPIO_PORTC */
/*Copy_u8Mode: GPIO_INPUT , GPIO_OUTPUT                          */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPortMode(u8 Copy_u8PortId  , u8 Copy_u8Mode )
{   
    u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PortId > GPIO_PORTC)
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        switch (Copy_u8PortId)
        {
        case GPIO_PORTA:
            switch (Copy_u8Mode)
            {
            case GPIO_INPUT:
                GPIOA->MODER = 0x00000000;
                break;
            case GPIO_OUTPUT:
                for(u8 Local_u8Iterator = 0 ; Local_u8Iterator < 16 ; Local_u8Iterator++ )
                {
                    SET_BIT(GPIOA->MODER , (2 * Local_u8Iterator));
                    CLR_BIT(GPIOA->MODER , (2 * Local_u8Iterator)+1);
                }
            default:
                break;
            }
            break;
        case GPIO_PORTB:
            switch (Copy_u8Mode)
            {
            case GPIO_INPUT:
                GPIOB->MODER = 0x00000000;
                break;
            case GPIO_OUTPUT:
                for(u8 Local_u8Iterator = 0 ; Local_u8Iterator < 16 ; Local_u8Iterator++ )
                {
                    SET_BIT(GPIOB->MODER , (2 * Local_u8Iterator));
                    CLR_BIT(GPIOB->MODER , (2 * Local_u8Iterator)+1);
                }
            default:
                break;
            }
            break;
        case GPIO_PORTC:
            switch (Copy_u8Mode)
            {
            case GPIO_INPUT:
                GPIOC->MODER = 0x00000000;
                break;
            case GPIO_OUTPUT:
                for(u8 Local_u8Iterator = 0 ; Local_u8Iterator < 16 ; Local_u8Iterator++ )
                {
                    SET_BIT(GPIOC->MODER , (2 * Local_u8Iterator));
                    CLR_BIT(GPIOC->MODER , (2 * Local_u8Iterator)+1);
                }
            default:
                break;
            }
            break;
        default:        
            Local_u8ErrorState = STD_TYPES_NOK ;
            break;
        }
    }
}
/******************************************************************/
/*Func. Name: GPIO_u8SetPortValue                              */
/*i/p arguments: Copy_u8PortId options: GPIO_GPIO_PORTA, GPIO_PORTB , GPIO_PORTC */
/*Copy_u8Value: GPIO_HIGH , GPIO_LOW                              */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8SetPortValue(u8 Copy_u8PortId  , u8 Copy_u8Value )
{
   u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PortId > GPIO_PORTC)
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        switch (Copy_u8PortId)
        {
        case GPIO_PORTA:
            switch (Copy_u8Value)
            {
            case GPIO_HIGH:
                GPIOA->ODR = 0xFFFFFFFF;
                break;
            case GPIO_LOW:
                GPIOA->ODR = 0x00000000;
            default:
                break;
            }
            break;
        case GPIO_PORTB:
            switch (Copy_u8Value)
            {
            case GPIO_HIGH:
                GPIOB->ODR = 0xFFFFFFFF;
                break;
            case GPIO_LOW:
                GPIOB->ODR = 0x00000000;
            default:
                break;
            }
            break;
        case GPIO_PORTC:
            switch (Copy_u8Value)
            {
            case GPIO_HIGH:
                GPIOC->ODR = 0xFFFFFFFF;
                break;
            case GPIO_LOW:
                GPIOC->ODR = 0x00000000;
            default:
                break;
            }
            break;
        default:        
            Local_u8ErrorState = STD_TYPES_NOK ;
            break;
        }
    } 
}

/******************************************************************/
/*Func. Name: GPIO_u8GetPortValue                              */
/*i/p arguments: Copy_u8PortId options: GPIO_GPIO_PORTA, GPIO_PORTB , GPIO_PORTC */
/*Copy_u16ReturnedData: Pointer to returned value variable               */
/*return: u8                                                    */
/******************************************************************/
u8 GPIO_u8GetPortValue(u8 Copy_u8PortId, u16* Copy_u16ReturnedData )
{
   u8 Local_u8ErrorState = STD_TYPES_OK ;
    if(Copy_u8PortId > GPIO_PORTC || (Copy_u16ReturnedData == NULL))
    {
        Local_u8ErrorState = STD_TYPES_NOK ;
    }
    else
    {
        switch (Copy_u8PortId)
        {
        case GPIO_PORTA:
            *Copy_u16ReturnedData = (u16)(GPIOA->IDR);
            break;
        case GPIO_PORTB:
            *Copy_u16ReturnedData = (u16)(GPIOB->IDR);
            break;
        case GPIO_PORTC:
            *Copy_u16ReturnedData = (u16)(GPIOC->IDR);
            break;
        default:        
            Local_u8ErrorState = STD_TYPES_NOK ;
            break;
        }
    }  
}