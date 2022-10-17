/*
 * SEVEN_SEG.c
 *
 * Created: 8/13/2022 12:52:50 PM
 *  Author: safifi
 */ 
#include "SEVEN_SEG.h"
const uint8_t SEVEN_ARR[10]={zero, one, two, three, four, five, six, seven, eight, nine};
void SEVEN_SEG_init(void){
	INIT_SEVEN_SEG_PINS;
}
void SEVEN_SEG_write(uint8_t data,uint8_t sev_num){ // 0 to 99

	PORT_DISABLE_ALL_SS
	switch(sev_num){
		case 1:EN0 break;
		case 2:EN1 break;
		case 3:EN2 break;
		case 4:EN3 break;
		case 5:EN4 break;
		case 6:EN5 break;
		default: break;
	}	
	PORT_WRITE=SEVEN_ARR[data];
	//_delay_us(7);	
}
