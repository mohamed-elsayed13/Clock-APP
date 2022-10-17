/*
 * Timer2.h
 *
 * Created: 8/30/2022 11:47:02 AM
 *  Author: Mohamed Elsayed
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "STD_MACROS.h"
extern  void(*Timer2_OVR_ISR)(void);
extern  void(*Timer2_COMP_ISR)(void);

void Timer2_normal_init(void);
void Timer2_compare_init(uint8_t);
void Timer2_freqgen_init(uint8_t oc);
#endif /* TIMER2_H_ */