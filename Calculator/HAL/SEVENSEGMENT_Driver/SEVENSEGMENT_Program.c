#include "SEVENSEGMENT_Config.h"
#include "SEVENSEGMENT_Interface.h"
#include "SEVENSEGMENT_Private.h"
#include "../../Common/Bit_Math.h"
#include <util\delay.h>

const u8_t  u8_Seven_Segment_Display_Numbers[] = {0,1,2,3,4,5,6,7,8,9};

void HAL_SEVENSEGMENT_Void_Init(){
	MCAL_DIO_u8_Init_Direction(Seven_Segment_PinA_Port , Seven_Segment_PinA_Pin , Output);
	MCAL_DIO_u8_Init_Direction(Seven_Segment_PinB_Port , Seven_Segment_PinB_Pin , Output);
	MCAL_DIO_u8_Init_Direction(Seven_Segment_PinC_Port , Seven_Segment_PinC_Pin , Output);
	MCAL_DIO_u8_Init_Direction(Seven_Segment_PinD_Port , Seven_Segment_PinD_Pin , Output);

	MCAL_DIO_u8_Init_Direction(Seven_Segment_Enable1_Port , Seven_Segment_Enable1_Pin , Output);
	MCAL_DIO_u8_Init_Direction(Seven_Segment_Enable2_Port , Seven_Segment_Enable2_Pin , Output);
	MCAL_DIO_u8_Init_Direction(Seven_Segment_Enable3_Port , Seven_Segment_Enable3_Pin , Output);
	MCAL_DIO_u8_Init_Direction(Seven_Segment_Enable4_Port , Seven_Segment_Enable4_Pin , Output);
	MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable1_Port ,Seven_Segment_Enable1_Pin , Low);
	MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable2_Port ,Seven_Segment_Enable2_Pin , Low);
	MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable3_Port ,Seven_Segment_Enable3_Pin , Low);
	MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable4_Port ,Seven_Segment_Enable4_Pin , Low);
}
void HAL_SEVENSEGMENT_Void_Display(u32_t Number){
	u8_t u8_Local_Reminder = 0;

	while(Number){
		for (u8_t u8_Local_temp = 3 ; u8_Local_temp >=0 ; u8_Local_temp-- ){
			u8_Local_Reminder = Number%10;
			Number /= 10;
			switch(u8_Local_temp){
				case 0:
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinA_Port , Seven_Segment_PinA_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 0));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinB_Port , Seven_Segment_PinB_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 1));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinC_Port , Seven_Segment_PinC_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 2));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinD_Port , Seven_Segment_PinD_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 3));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable1_Port ,Seven_Segment_Enable1_Pin , High);
					_delay_ms(50);
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable1_Port ,Seven_Segment_Enable1_Pin , Low);
					break;
				case 1:
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinA_Port , Seven_Segment_PinA_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 0));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinB_Port , Seven_Segment_PinB_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 1));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinC_Port , Seven_Segment_PinC_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 2));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinD_Port , Seven_Segment_PinD_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 3));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable2_Port ,Seven_Segment_Enable2_Pin , High);
					_delay_ms(40);
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable2_Port ,Seven_Segment_Enable2_Pin , Low);
					break;
				case 2:
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinA_Port , Seven_Segment_PinA_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 0));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinB_Port , Seven_Segment_PinB_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 1));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinC_Port , Seven_Segment_PinC_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 2));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinD_Port , Seven_Segment_PinD_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 3));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable3_Port ,Seven_Segment_Enable3_Pin , High);
					_delay_ms(40);
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable3_Port ,Seven_Segment_Enable3_Pin , Low);
					break;
				case 3:
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinA_Port , Seven_Segment_PinA_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 0));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinB_Port , Seven_Segment_PinB_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 1));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinC_Port , Seven_Segment_PinC_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 2));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_PinD_Port , Seven_Segment_PinD_Pin ,GET_BIT(u8_Seven_Segment_Display_Numbers[u8_Local_Reminder] , 3));
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable4_Port ,Seven_Segment_Enable4_Pin , High);
					_delay_ms(40);
					MCAL_DIO_u8_Set_Pin_Value(Seven_Segment_Enable4_Port ,Seven_Segment_Enable4_Pin , Low);
					break;
			}
		}
	}
}
