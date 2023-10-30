
#include "../MCAL/DIO_Driver/DIO_Interface.h"
#include "../HAL/LCD_Driver/LCD_Interface.h"
#include "../HAL/KEYPAD_Driver/KEYPAD_Interface.h"


int main(){

	HAL_KEYPAD_Void_Init();
	HAL_LCD_Void_Init();


	u8_t u8_Local_String1[] = "Calculator";
	u8_t u8_Local_Error_Stirng[] = "Cant divide by Zero";

	HAL_LCD_void_CursorPos(0 , 5);
	HAL_LCD_Void_Send_String(&u8_Local_String1);
	HAL_LCD_void_CursorPos(1 , 0);

	u32_t u32_Local_Number1 = 0;
	u32_t u32_Local_Number2 = 0;
	u32_t u32_Local_Temp_Keypad_Return = 0;
	s32_t s32_Local_Neg_Result = 0;
	u8_t u8_Local_Operation_Flag = 5;
	f32_t f32_Local_Result = 0;
	u8_t u8_Local_Counter = 1;

	while(1){
		u8_t u8_Local_Keypad_Return = HAL_KEYPAD_u8_Get_Pressed_Key();
		if(u8_Local_Keypad_Return != 'k'){
			switch(u8_Local_Keypad_Return){
				case '/':
					u32_Local_Number2 = u32_Local_Number1;
					HAL_LCD_Void_Send_Char('/');
					u32_Local_Number1 = 0;
					u8_Local_Counter = 1;
					u8_Local_Operation_Flag = 0;
					break;
				case '*':
					u32_Local_Number2 = u32_Local_Number1;
					HAL_LCD_Void_Send_Char('*');
					u32_Local_Number1 = 0;
					u8_Local_Counter = 1;
					u8_Local_Operation_Flag = 1;
					break;
				case '-':
					u32_Local_Number2 = u32_Local_Number1;
					HAL_LCD_Void_Send_Char('-');
					u32_Local_Number1 = 0;
					u8_Local_Counter = 1;
					u8_Local_Operation_Flag = 2;
					break;
				case '+':
					u32_Local_Number2 = u32_Local_Number1;
					HAL_LCD_Void_Send_Char('+');
					u32_Local_Number1 = 0;
					u8_Local_Counter = 1;
					u8_Local_Operation_Flag = 3;
					break;
				case '=':
					HAL_LCD_void_CursorPos(2 ,0);
					switch(u8_Local_Operation_Flag){
						case 0:
							if (u32_Local_Number1 == 0){HAL_LCD_Void_Send_String(&u8_Local_Error_Stirng);}
							else{
								f32_Local_Result = (f32_t)u32_Local_Number2/u32_Local_Number1;
								HAL_LCD_Void_Send_Float(f32_Local_Result);
							}
							break;
						case 1:
							f32_Local_Result = u32_Local_Number2*u32_Local_Number1;
							HAL_LCD_Void_Send_Float((s32_t)f32_Local_Result);
							break;
						case 2:
							s32_Local_Neg_Result = u32_Local_Number2-u32_Local_Number1;
							HAL_LCD_Void_Send_Integer(s32_Local_Neg_Result);
							break;
						case 3:
							f32_Local_Result = u32_Local_Number2+u32_Local_Number1;
							HAL_LCD_Void_Send_Float((s32_t)f32_Local_Result);
							break;
					}

					break;
				case 'c':
					u32_Local_Number1 = 0;
					u32_Local_Number2 = 0;
					u8_Local_Counter = 1;
					HAL_LCD_Void_Send_Command(LCD_Clear);
					HAL_LCD_void_CursorPos(0 , 5);
					HAL_LCD_Void_Send_String(&u8_Local_String1);
					HAL_LCD_void_CursorPos(1 ,0);
					break;
				default:
					u32_Local_Temp_Keypad_Return = u8_Local_Keypad_Return;
					if(u8_Local_Counter > 1){u32_Local_Number1 *= 10;}
					u8_Local_Counter++;
					u32_Local_Number1 += u32_Local_Temp_Keypad_Return;
					HAL_LCD_Void_Send_Integer(u32_Local_Temp_Keypad_Return);
					break;
			}
		}
	}
	return 0;
}





