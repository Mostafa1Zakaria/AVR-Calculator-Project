#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "../../MCAL/DIO_Driver/DIO_Interface.h"
#include "../../Common/Bit_Math.h"


// 4*20 LCD Initialize
void HAL_LCD_Void_Init(){

	MCAL_DIO_u8_Init_Direction(LCD_RS_PORT , LCD_RS_PIN ,Output);
	MCAL_DIO_u8_Init_Direction(LCD_EN_PORT , LCD_EN_PIN ,Output);
	MCAL_DIO_u8_Init_Direction(LCD_D4_PORT , LCD_D4_PIN ,Output);	
	MCAL_DIO_u8_Init_Direction(LCD_D5_PORT , LCD_D5_PIN ,Output);	
	MCAL_DIO_u8_Init_Direction(LCD_D6_PORT , LCD_D6_PIN ,Output);
	MCAL_DIO_u8_Init_Direction(LCD_D7_PORT , LCD_D7_PIN ,Output);	
	
	
	_delay_ms(20);
	HAL_LCD_Void_Send_Command(LCD_Reset);
	_delay_ms(5);
	HAL_LCD_Void_Send_Command(LCD_Reset);
	_delay_us(100);
	HAL_LCD_Void_Send_Command(LCD_Reset);
	_delay_us(200);
	HAL_LCD_Void_Send_Command(Return_home);
	HAL_LCD_Void_Send_Command(Four_bit_Mode);
	HAL_LCD_Void_Send_Command(Display_On);
	HAL_LCD_Void_Send_Command(LCD_Clear);
	_delay_ms(1);
	HAL_LCD_Void_Send_Command(Entry_Mode);
}

void HAL_LCD_Void_Send_Command( u8_t u8_Command){
	MCAL_DIO_u8_Set_Pin_Value(LCD_D7_PORT , LCD_D7_PIN , GET_BIT(u8_Command ,7));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D6_PORT , LCD_D6_PIN , GET_BIT(u8_Command ,6));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D5_PORT , LCD_D5_PIN , GET_BIT(u8_Command ,5));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D4_PORT , LCD_D4_PIN , GET_BIT(u8_Command ,4));
	MCAL_DIO_u8_Set_Pin_Value(LCD_RS_PORT , LCD_RS_PIN , Low);
	MCAL_DIO_u8_Set_Pin_Value(LCD_EN_PORT , LCD_EN_PIN , High);
	_delay_ms(1);
	MCAL_DIO_u8_Set_Pin_Value(LCD_EN_PORT , LCD_EN_PIN , Low);
	_delay_ms(1);
	
	MCAL_DIO_u8_Set_Pin_Value(LCD_D7_PORT , LCD_D7_PIN , GET_BIT(u8_Command ,3));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D6_PORT , LCD_D6_PIN , GET_BIT(u8_Command ,2));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D5_PORT , LCD_D5_PIN , GET_BIT(u8_Command ,1));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D4_PORT , LCD_D4_PIN , GET_BIT(u8_Command ,0));
	MCAL_DIO_u8_Set_Pin_Value(LCD_RS_PORT , LCD_RS_PIN , Low);
	MCAL_DIO_u8_Set_Pin_Value(LCD_EN_PORT , LCD_EN_PIN , High);
	_delay_ms(1);
	MCAL_DIO_u8_Set_Pin_Value(LCD_EN_PORT , LCD_EN_PIN , Low);
	_delay_ms(1);
}

void HAL_LCD_Void_Send_Char( u8_t u8_Data){
	MCAL_DIO_u8_Set_Pin_Value(LCD_D7_PORT , LCD_D7_PIN , GET_BIT(u8_Data ,7));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D6_PORT , LCD_D6_PIN , GET_BIT(u8_Data ,6));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D5_PORT , LCD_D5_PIN , GET_BIT(u8_Data ,5));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D4_PORT , LCD_D4_PIN , GET_BIT(u8_Data ,4));
	MCAL_DIO_u8_Set_Pin_Value(LCD_RS_PORT , LCD_RS_PIN , High);
	MCAL_DIO_u8_Set_Pin_Value(LCD_EN_PORT , LCD_EN_PIN , High);
	_delay_ms(1);
	MCAL_DIO_u8_Set_Pin_Value(LCD_EN_PORT , LCD_EN_PIN , Low);
	_delay_ms(3);
	
	MCAL_DIO_u8_Set_Pin_Value(LCD_D7_PORT , LCD_D7_PIN , GET_BIT(u8_Data ,3));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D6_PORT , LCD_D6_PIN , GET_BIT(u8_Data ,2));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D5_PORT , LCD_D5_PIN , GET_BIT(u8_Data ,1));
	MCAL_DIO_u8_Set_Pin_Value(LCD_D4_PORT , LCD_D4_PIN , GET_BIT(u8_Data ,0));
	MCAL_DIO_u8_Set_Pin_Value(LCD_RS_PORT , LCD_RS_PIN , High);
	MCAL_DIO_u8_Set_Pin_Value(LCD_EN_PORT , LCD_EN_PIN , High);
	_delay_ms(1);
	MCAL_DIO_u8_Set_Pin_Value(LCD_EN_PORT , LCD_EN_PIN , Low);
	_delay_ms(3);	
	
}

void HAL_LCD_Void_Send_String(u8_t* u8_Data){
	for (int i = 0; u8_Data[i] != 0; i++)
	{
		HAL_LCD_Void_Send_Char(u8_Data[i]);
		_delay_ms(250);
	}
}

void HAL_LCD_Void_Send_Integer(s32_t s32_Data){
	u8_t u8_Local_Array[16] ,  u8_Local_Reminder = 0 ,  u8_Local_Temporary = 0;
	if(s32_Data == 0){HAL_LCD_Void_Send_Char('0'); return;}
	if(s32_Data < 0){
		s32_Data = s32_Data * -1;
		HAL_LCD_Void_Send_Char('-');
	}
	while(s32_Data){
		u8_Local_Reminder = s32_Data % 10;
		u8_Local_Reminder = u8_Local_Reminder + '0';
		u8_Local_Array[u8_Local_Temporary] = u8_Local_Reminder ;
		u8_Local_Temporary++;
		s32_Data = s32_Data /10;
		
	}	
	for (int i = u8_Local_Temporary-1; i >= 0; i--)
	{
		HAL_LCD_Void_Send_Char(u8_Local_Array[i]);
		_delay_ms(250);
	}

}

void HAL_LCD_Void_Send_Float(f32_t f32_Data){
	u8_t u8_Local_Array[16] ,  u8_Local_Reminder = 0 ,  u8_Local_Temporary = 0 , u8_Local_Decimal = 0;
	u8_Local_Decimal = (f32_Data - (u32_t)f32_Data) * 10;
	if(f32_Data == 0){HAL_LCD_Void_Send_Char('0'); return;}
	if(f32_Data < 0){
		f32_Data = f32_Data * -1;
		HAL_LCD_Void_Send_Char('-');
	}
	while((u32_t)f32_Data){
		u8_Local_Reminder = (u32_t)f32_Data % 10;
		u8_Local_Reminder = u8_Local_Reminder + '0';
		u8_Local_Array[u8_Local_Temporary] = u8_Local_Reminder ;
		u8_Local_Temporary++;
		f32_Data = (u32_t)f32_Data /10;

	}
	for (int i = u8_Local_Temporary-1; i >= 0; i--)
	{
		HAL_LCD_Void_Send_Char(u8_Local_Array[i]);
		_delay_ms(250);
	}
	HAL_LCD_Void_Send_Char('.');
	HAL_LCD_Void_Send_Integer(u8_Local_Decimal);

}

void HAL_LCD_void_CursorPos(u8_t u8_Row , u8_t u8_Column){
	u8_t u8_Local_The_Address = 0;
	if (u8_Row == 0 ){u8_Local_The_Address = LCD_First_Line;}
	else if (u8_Row == 1) {u8_Local_The_Address = LCD_Secound_Line;}
	else if (u8_Row == 2) {u8_Local_The_Address = LCD_Third_Line;}
	else{u8_Local_The_Address = LCD_Fourth_Line;}		
	if(u8_Column <= 19){u8_Local_The_Address += u8_Column;}
	HAL_LCD_Void_Send_Command(u8_Local_The_Address);
}



