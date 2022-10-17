/*
 * KEYPAD.c
 *
 * Created: 8/13/2022 4:14:01 PM
 *  Author: Mohamed Elsayed
 */ 
#include "KEYPAD.h"
/*****************************************************************************
* Function Name: KEYPAD_init
* Purpose      : PotrB Pins from 4 to 7 pull up input & PortD Pins (2 to 5) output
* Parameters   : void
* Return value : void
*****************************************************************************/
void KEYPAD_init(void){
	INIT_KEYPAD_PINS
}
/*****************************************************************************
* Function Name: KEYPAD_read
* Purpose      : Read data from Keypad
* Parameters   : void
* Return value : Ascii symbol from matrix array of keypad
*****************************************************************************/
uint8_t KEYPAD_read(void){
	const uint8_t keypad_matrix[]={'7','8','9','/',
								   '4','5','6','*',
								   '1','2','3','-',
								   'C','0','=','+'};
	K2(0); K3(1); K4(1); K5(1);
	if(B4==0) return keypad_matrix[0];
	if(B5==0) return keypad_matrix[4];
	if(B6==0) return keypad_matrix[8];
	if(B7==0) return keypad_matrix[12];
	_delay_ms(1);
	K2(1); K3(0); K4(1); K5(1);
	if(B4==0) return keypad_matrix[1];
	if(B5==0) return keypad_matrix[5];
	if(B6==0) return keypad_matrix[9];
	if(B7==0) return keypad_matrix[13];
	_delay_ms(1);
	K2(1); K3(1); K4(0); K5(1);
	if(B4==0) return keypad_matrix[2];
	if(B5==0) return keypad_matrix[6];
	if(B6==0) return keypad_matrix[10];
	if(B7==0) return keypad_matrix[14];
	_delay_ms(1);
	K2(1); K3(1); K4(1); K5(0);
	if(B4==0) return keypad_matrix[3];
	if(B5==0) return keypad_matrix[7];
	if(B6==0) return keypad_matrix[11];
	if(B7==0) return keypad_matrix[15];
	_delay_ms(1);
	
	return 0;
	
}
