#include "DIO_Types.h"
#include "../../Common/Type_Def.h"
#include "../../Common/Bit_Math.h"

#include "DIO_Registers.h"




#ifndef INTERFACE_H_
#define INTERFACE_H_

#define E_Not_Ok 1
#define E_Ok 0

u8_t MCAL_DIO_u8_Init_Direction(u8_t u8_Port_Id , u8_t u8_Pin_no , u8_t u8_Direction);
u8_t MCAL_DIO_u8_Set_Pin_Value(u8_t u8_Port_Id , u8_t u8_Pin_no , u8_t u8_Logic_State);
u8_t MCAL_DIO_u8_Read_Pin_Value( u8_t u8_Port_Id , u8_t u8_Pin_no , u8_t *Pin_Value);
u8_t MCAL_DIO_u8_Toggle_Pin(u8_t u8_Port_Id , u8_t u8_Pin_no);


#endif 