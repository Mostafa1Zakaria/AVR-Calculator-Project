#include "DIO_Interface.h"





u8_t MCAL_DIO_u8_Init_Direction(u8_t u8_Port_Id , u8_t u8_Pin_no , u8_t u8_Direction){
	
	u8_t u8_Local_Return = E_Not_Ok; 
	
	if(u8_Pin_no <= DIO_PIN7){
		if(u8_Direction == Input){	
			switch(u8_Port_Id){
				case PORT_A: CLEAR_BIT(DDRA,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_B: CLEAR_BIT(DDRB,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_C: CLEAR_BIT(DDRC,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_D: CLEAR_BIT(DDRD,u8_Pin_no); u8_Local_Return = E_Ok ; break;
			}
		}
		else if (u8_Direction == Output){
			switch(u8_Port_Id){
				case PORT_A: SET_BIT(DDRA,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_B: SET_BIT(DDRB,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_C: SET_BIT(DDRC,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_D: SET_BIT(DDRD,u8_Pin_no); u8_Local_Return = E_Ok ; break;
			}
		}
	}
		else{
			//DO NO THING
		}	
	return u8_Local_Return;	
}

u8_t MCAL_DIO_u8_Set_Pin_Value(u8_t u8_Port_Id , u8_t u8_Pin_no , u8_t u8_Direction){
	
	u8_t u8_Local_Return = E_Not_Ok;
	
	if(u8_Pin_no <= DIO_PIN7){
		if(u8_Direction == Low){
			switch(u8_Port_Id){
				case PORT_A: CLEAR_BIT(PORTA,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_B: CLEAR_BIT(PORTB,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_C: CLEAR_BIT(PORTC,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_D: CLEAR_BIT(PORTD,u8_Pin_no); u8_Local_Return = E_Ok ; break;
			}
		}
		else if (u8_Direction == Output){
			switch(u8_Port_Id){
				case PORT_A: SET_BIT(PORTA,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_B: SET_BIT(PORTB,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_C: SET_BIT(PORTC,u8_Pin_no); u8_Local_Return = E_Ok ; break;
				case PORT_D: SET_BIT(PORTD,u8_Pin_no); u8_Local_Return = E_Ok ; break;
			}
		}
	}
	else{
		//DO NO THING
	}
	return u8_Local_Return;
}

u8_t MCAL_DIO_u8_Read_Pin_Value( u8_t u8_Port_Id , u8_t u8_Pin_no , u8_t *Pin_Value){
	
	u8_t u8_Local_Return = E_Not_Ok;
	if(u8_Pin_no <= DIO_PIN7){
			switch(u8_Port_Id)
			{
				case PORT_A : *Pin_Value= GET_BIT(PINA , u8_Pin_no); u8_Local_Return = E_Ok; break;
				case PORT_B : *Pin_Value= GET_BIT(PINB , u8_Pin_no); u8_Local_Return = E_Ok; break;
				case PORT_C : *Pin_Value= GET_BIT(PINC , u8_Pin_no); u8_Local_Return = E_Ok; break;
				case PORT_D : *Pin_Value= GET_BIT(PIND , u8_Pin_no); u8_Local_Return = E_Ok; break;
			}
	}
	else{
		//DO NO THING
	}
	
	return u8_Local_Return;		
}

u8_t MCAL_DIO_u8_Toggle_Pin(u8_t u8_Port_Id , u8_t u8_Pin_no){
	
	u8_t u8_Local_Return = E_Not_Ok;
	if(u8_Pin_no <= DIO_PIN7){
		
		switch(u8_Port_Id){
			case PORT_A:
				TOGGLE_BIT(PORTA , u8_Pin_no);
				u8_Local_Return = E_Ok;
				break;
			case PORT_B:
				TOGGLE_BIT(PORTB , u8_Pin_no);
				u8_Local_Return = E_Ok;
				break;
			case PORT_C:
				TOGGLE_BIT(PORTC , u8_Pin_no);
				u8_Local_Return = E_Ok;
				break;
			case PORT_D:
				TOGGLE_BIT(PORTD , u8_Pin_no);
				u8_Local_Return = E_Ok;
				break;
		}
	}
	else{
		//DO NO THING
	}
	
	return u8_Local_Return;
}
