#include "KEYPAD_Config.h"
#include "KEYPAD_Private.h"
#include "KEYPAD_Interface.h"
#include "../../Common/Bit_Math.h"
#include <util/delay.h>

void HAL_KEYPAD_Void_Init(){
	// Columns Output
	MCAL_DIO_u8_Init_Direction(KeyPad_Column1_Port , KeyPad_Column1_Pin , Output);
	MCAL_DIO_u8_Init_Direction(KeyPad_Column2_Port , KeyPad_Column2_Pin , Output);
	MCAL_DIO_u8_Init_Direction(KeyPad_Column3_Port , KeyPad_Column3_Pin , Output);
	MCAL_DIO_u8_Init_Direction(KeyPad_Column4_Port , KeyPad_Column4_Pin , Output);
	// Cloumns High
	MCAL_DIO_u8_Set_Pin_Value(KeyPad_Column1_Port , KeyPad_Column1_Pin , High);
	MCAL_DIO_u8_Set_Pin_Value(KeyPad_Column2_Port , KeyPad_Column2_Pin , High);
	MCAL_DIO_u8_Set_Pin_Value(KeyPad_Column3_Port , KeyPad_Column3_Pin , High);
	MCAL_DIO_u8_Set_Pin_Value(KeyPad_Column4_Port , KeyPad_Column4_Pin , High);
	// Rows Input
	MCAL_DIO_u8_Init_Direction(KeyPad_Row1_Port , KeyPad_Row1_Pin , Input);
	MCAL_DIO_u8_Init_Direction(KeyPad_Row2_Port , KeyPad_Row2_Pin , Input);
	MCAL_DIO_u8_Init_Direction(KeyPad_Row3_Port , KeyPad_Row3_Pin , Input);
	MCAL_DIO_u8_Init_Direction(KeyPad_Row4_Port , KeyPad_Row4_Pin , Input);
	// Pull-up Resistance for Input
	MCAL_DIO_u8_Set_Pin_Value(KeyPad_Row1_Port , KeyPad_Row1_Pin , High);
	MCAL_DIO_u8_Set_Pin_Value(KeyPad_Row2_Port , KeyPad_Row2_Pin , High);
	MCAL_DIO_u8_Set_Pin_Value(KeyPad_Row3_Port , KeyPad_Row3_Pin , High);
	MCAL_DIO_u8_Set_Pin_Value(KeyPad_Row4_Port , KeyPad_Row4_Pin , High);
}
u8_t HAL_KEYPAD_u8_Get_Pressed_Key(){
	u8_t u8_Local_Pressed_Key = 'k';
	u8_t u8_Local_If_Pressed = 1;

	u8_t u8_Local_Rows_Pins_Array[] = {KeyPad_Row1_Pin , KeyPad_Row2_Pin , KeyPad_Row3_Pin , KeyPad_Row4_Pin};
	u8_t u8_Local_Rows_Ports_Array[] = {KeyPad_Row1_Port , KeyPad_Row2_Port , KeyPad_Row3_Port , KeyPad_Row4_Port};
	u8_t u8_Local_Columns_Pins_Array[] = {KeyPad_Column1_Pin , KeyPad_Column2_Pin , KeyPad_Column3_Pin , KeyPad_Column4_Pin};
	u8_t u8_Local_Columns_Ports_Array[] = {KeyPad_Column1_Port , KeyPad_Column2_Port , KeyPad_Column3_Port , KeyPad_Column4_Port};

	for (u8_t i = 0; i <= 3 ; i++ ){
		MCAL_DIO_u8_Set_Pin_Value(u8_Local_Columns_Ports_Array[i] , u8_Local_Columns_Pins_Array[i] , Low);
		for (u8_t j = 0; j <= 3 ; j++ ){
			MCAL_DIO_u8_Read_Pin_Value(u8_Local_Rows_Ports_Array[j] , u8_Local_Rows_Pins_Array[j] ,&u8_Local_If_Pressed);
			if (u8_Local_If_Pressed == Low){
				u8_Local_Pressed_Key = u8_KeyPadButtons[j][i];
				_delay_ms(500);
				return u8_Local_Pressed_Key;
			}
		}
		MCAL_DIO_u8_Set_Pin_Value(u8_Local_Columns_Ports_Array[i] , u8_Local_Columns_Pins_Array[i] , High);
	}
	return u8_Local_Pressed_Key;
}
