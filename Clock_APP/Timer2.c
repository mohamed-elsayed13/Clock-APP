/*
 * Timer2.c
 *
 * Created: 8/30/2022 11:46:40 AM
 *  Author: Mohamed Elsayed 
 */ 
#include "Timer2.h"
void(*Timer2_OVR_ISR)(void);
void(*Timer2_COMP_ISR)(void);

/*****************************************************************************
* Function Name: Timer2_normal_init
* Purpose      : init timer in normal mode with 1024 prescaler
* Parameters   : void
* Return value : void
*****************************************************************************/
void Timer2_normal_init(void){
	SETBIT(TCCR2,FOC2);
	SETBIT(TCCR2,CS20);
	SETBIT(TCCR2,CS21);
	SETBIT(TCCR2,CS22);
	SETBIT(TIMSK,TOIE2);
	SETBIT(SREG,7);		//sei();	
}

/*****************************************************************************
* Function Name: Timer2_compare_init
* Purpose      : init timer in compare mode with 1024 prescaler
* Parameters   : void
* Return value : void
*****************************************************************************/
void Timer2_compare_init(uint8_t oc){
	SETBIT(TCCR2,FOC2);
	SETBIT(TCCR2,WGM21);
	SETBIT(TCCR2,CS20);
	SETBIT(TCCR2,CS21);
	SETBIT(TCCR2,CS22);
	OCR2=oc;
	SETBIT(TIMSK,OCIE2);
	SETBIT(SREG,7);		//sei();
}
/*****************************************************************************
* Function Name: Frequency_gen_init
* Purpose      : init timer in normal mode with 1024 prescaler
* Parameters   : void
* Return value : void
*****************************************************************************/
void Timer2_freqgen_init(uint8_t oc){
	SETBIT(TCCR2,FOC2);
	SETBIT(TCCR2,CS20);
	SETBIT(TCCR2,CS21);
	SETBIT(TCCR2,CS22);
	SETBIT(TCCR2,WGM21);
	SETBIT(TCCR2,COM20);
	SETBIT(DDRD,7);
	OCR2=oc;
}
ISR(TIMER2_OVF_vect){
	Timer2_OVR_ISR();
}
ISR(TIMER2_COMP_vect){
	Timer2_COMP_ISR();
}