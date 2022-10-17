/*
 * SEVEN_SEG.h
 *
 * Created: 8/13/2022 12:53:05 PM
 *  Author: safifi
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_macros.h"

void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t data,uint8_t sev_num);

#define INIT_SEVEN_SEG_PINS DDRC |= 0b01111111; DDRD |=0b00111111;
#define PORT_DISABLE_ALL_SS PORTD = 0x00;
#define PORT_WRITE PORTC 

#define zero  0b01000000  //0gfedcba
#define one   0b01111001 
#define two   0b00100100 
#define three 0b00110000
#define four  0b00011001
#define five  0b00010010 
#define six   0b00000010
#define seven 0b01111000
#define eight 0b00000000 
#define nine  0b00010000 


#define EN0 SETBIT(PORTD,0);
#define EN1 SETBIT(PORTD,1);
#define EN2 SETBIT(PORTD,2);
#define EN3 SETBIT(PORTD,3);
#define EN4 SETBIT(PORTD,4);
#define EN5 SETBIT(PORTD,5);

#endif /* SEVEN_SEG_H_ */