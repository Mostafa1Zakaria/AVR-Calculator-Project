#include "../../Common/Type_Def.h"

#ifndef HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_

u8_t u8_KeyPadButtons[4][4] = {{ 7 , 8 , 9 ,'/'},
							   { 4 , 5 , 6 ,'*'},
							   { 1 , 2 , 3 ,'-'},
							   {'c', 0 ,'=','+'}};

#define KeyPad_Row1_Port PORT_C
#define KeyPad_Row1_Pin  DIO_PIN5
#define KeyPad_Row2_Port PORT_C
#define KeyPad_Row2_Pin  DIO_PIN4
#define KeyPad_Row3_Port PORT_C
#define KeyPad_Row3_Pin  DIO_PIN3
#define KeyPad_Row4_Port PORT_C
#define KeyPad_Row4_Pin  DIO_PIN2

#define KeyPad_Column1_Port PORT_D
#define KeyPad_Column1_Pin  DIO_PIN7
#define KeyPad_Column2_Port PORT_D
#define KeyPad_Column2_Pin  DIO_PIN6
#define KeyPad_Column3_Port PORT_D
#define KeyPad_Column3_Pin  DIO_PIN5
#define KeyPad_Column4_Port PORT_D
#define KeyPad_Column4_Pin  DIO_PIN3

#endif /* HAL_KEYPAD_DRIVER_KEYPAD_CONFIG_H_ */
