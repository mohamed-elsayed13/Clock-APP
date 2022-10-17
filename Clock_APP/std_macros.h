/*
 * std_macros.h
 *
 * Created: 22/09/10 4:58:54 PM
 *  Author: abo_a
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#include <avr/io.h>	//this file include all register address macros like DDRA
#define F_CPU 16000000UL	//set the frequency of microcontroller
#include <util/delay.h>	//this header include all delay function like _delay_ms
#include <avr/interrupt.h>	//this header is necessary when you deal with interrupt

#define SETBIT(REG,BIT) (REG |= 1<<BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1<<BIT))
#define TOGBIT(REG,BIT) (REG ^= 1<<BIT)
#define GETBIT(REG,BIT) ((REG >> BIT) & 1)

#endif /* STD_MACROS_H_ */