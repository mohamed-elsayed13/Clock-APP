/*
 * Clock_APP.c
 *
 * Created: 16/09/2022 11:46:22 AM
 * Author : Mohamed Elsayed
 */ 

#include "SEVEN_SEG.h"
#include "Timer2.h"
#include "TIMER0.h"
#include "LCD.h"
#include "KEYPAD.h"
void LCD_update(void);
void OVR_ISR0(void);
void OVR_ISR2(void);
uint8_t seconds=0;
uint8_t minutes=0;
uint8_t hours=0;
uint8_t key=0;
uint8_t flag=0;
int main(void)
{
	Timer2_OVR_ISR=OVR_ISR2;
	timer0_ovf_isr=OVR_ISR0;
	Timer2_normal_init();
	TIMER0_normaMode_init();
	SEVEN_SEG_init();
	KEYPAD_init();
    LCD_init();
	while (1) 
    {
	
	if(KEYPAD_read()=='C'){
		key=KEYPAD_read();
		while(KEYPAD_read()==key);
		flag=1;
		while(KEYPAD_read()!='C'){	
			key=KEYPAD_read();
			while(KEYPAD_read()==key);
			if(KEYPAD_read()=='+'){
				key=KEYPAD_read();
				while(KEYPAD_read()==key);
				if(hours==23) hours=0;
				hours++;
				LCD_update();
			}
			else if(KEYPAD_read()=='-'){
				key=KEYPAD_read();
				while(KEYPAD_read()==key);
			    if(hours==0) hours=23;
				hours--;
				LCD_update();
			}	
			}	
		while(KEYPAD_read()=='C');
		while(KEYPAD_read()!='C'){
			key=KEYPAD_read();
			while(KEYPAD_read()==key);
			if(KEYPAD_read()=='+'){
				key=KEYPAD_read();
				while(KEYPAD_read()==key);
				if(minutes==59) minutes=0;
				minutes++;
				LCD_update();
			}
			else if(KEYPAD_read()=='-'){
				key=KEYPAD_read();
				while(KEYPAD_read()==key);
				if(minutes==0) minutes=59;
				minutes--;
				LCD_update();
			}	
		}	
		flag=0;
		LCD_write_command(1);
		while(KEYPAD_read()=='C');
	}
	else if(flag==0){	
	LCD_update();
	}
    
	}
}

void LCD_update(void){
	LCD_write_command(0x80);
	LCD_write_num(hours);
	LCD_write_command(0x82);
	LCD_write_char(':');
	LCD_write_num(minutes);
	LCD_write_command(0x85);
	LCD_write_char(':');
	LCD_write_num(seconds);
}
void OVR_ISR2(void){
	static uint8_t counter=0;
	if(flag==0){
	counter++;
	if(counter==61){
		counter=0;
		seconds++;
		if(seconds==60){
			seconds=0;
			minutes++;
			if(minutes==60){
				minutes=0;
				hours++;
				if(hours==24){
					hours=0;
				}
			}
		}
	}
	}
}
void OVR_ISR0(void){
	static uint8_t counter=0;
	counter++;
	switch(counter){
	case 1:
	SEVEN_SEG_write(seconds/10,1);
	break;
	case 2:
	SEVEN_SEG_write(seconds%10,2);
	break;
	case 3:
	SEVEN_SEG_write(minutes/10,3);
	break;
	case 4:
	SEVEN_SEG_write(minutes%10,4);
	break;
	case 5:
	SEVEN_SEG_write(hours/10,5);
	break;
	case 6:
	SEVEN_SEG_write(hours%10,6);counter=0;
	break;
	}
}