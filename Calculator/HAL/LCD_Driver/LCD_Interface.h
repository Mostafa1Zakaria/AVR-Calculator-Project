#include "../../Common/Type_Def.h"

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include <util\delay.h>

#define  Four_bit_Mode  0x28


#define Display_On 0x0C
#define Display_Off 0x08
#define LCD_Clear 0x01
#define Entry_Mode 0x06
#define Return_home 0x02
#define LCD_Reset 0x03

#define LCD_First_Line 0x80
#define LCD_Secound_Line 0xC0
#define LCD_Third_Line 0x94
#define LCD_Fourth_Line 0xD0

void HAL_LCD_Void_Init();

void HAL_LCD_Void_Send_Command( u8_t u8_Command);

void HAL_LCD_Void_Send_Char( u8_t u8_Data);
void HAL_LCD_Void_Send_String(u8_t* u8_Data);
void HAL_LCD_Void_Send_Integer(s32_t s32_Data);
void HAL_LCD_Void_Send_Float(f32_t f32_Data);

void HAL_LCD_void_CursorPos(u8_t u8_Row , u8_t u8_Column);





#endif /* LCD_INTERFACE_H_ */
