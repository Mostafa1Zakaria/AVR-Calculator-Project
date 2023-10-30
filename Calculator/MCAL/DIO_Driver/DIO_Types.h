#include "../../Common/Type_Def.h"

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

	typedef enum { PORT_A , PORT_B , PORT_C , PORT_D} Enum_Dio_Port_Id;
	typedef enum {DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7} Enum_DIO_Pin_Id;	
	typedef enum { Low , High} Enum_Logic_State;
	typedef enum { Input , Output} Enum_Direction;


#endif 