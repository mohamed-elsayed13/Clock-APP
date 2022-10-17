/*
 * KEYPAD.h
 *
 * Created: 8/13/2022 4:14:17 PM
 *  Author: Mohamed Elsayed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "STD_MACROS.h"
#define INIT_KEYPAD_PINS DDRB = 0b00001111; PORTB|= 0b11110000;
#define K2(x) if(x==1) SETBIT(PORTB,0); else CLRBIT(PORTB,0);
#define K3(x) if(x==1) SETBIT(PORTB,1); else CLRBIT(PORTB,1);
#define K4(x) if(x==1) SETBIT(PORTB,2); else CLRBIT(PORTB,2);
#define K5(x) if(x==1) SETBIT(PORTB,3); else CLRBIT(PORTB,3);

#define B4 GETBIT(PINB,4)
#define B5 GETBIT(PINB,5)
#define B6 GETBIT(PINB,6)
#define B7 GETBIT(PINB,7)

void KEYPAD_init(void);
uint8_t KEYPAD_read(void);
	



#endif /* KEYPAD_H_ */