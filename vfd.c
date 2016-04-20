#include "defines.h"

#include <util/delay.h>
#include <avr/io.h>
#include <string.h>

#include "vfd.h"

void setPinB(int pin, int state) {
	if(state == 0) {
		PORTB &= ~(1<<pin);
	} else {
		PORTB |= (1<<pin);
	}
}

void waitForLow(int pin) {
	while(PINB & (1<<pin)) {};
}

void vfd_send(int data) {
	setPinB(A0, 0);
	DPort = data;
	_delay_us(100);
	setPinB(CS, 0);
	setPinB(WR, 0);
	//waitForLow(BUSY);
	setPinB(WR, 1);
	setPinB(CS, 1);
}

int vfd_putchar(char c) {
	vfd_send(c);
	return 0;
}

//void vfd_send_string(char* str) {
//	int len = strlen(str);
//	for(int i = 0; i < len; i++){
//		vfd_send(str[i]);
//	}
//}
//
void vfd_set_pos(int pos) {
	vfd_send(SET_POS);
	vfd_send(pos);
}
//
//void vfd_set_cursor(int c) {
//	switch(c){
//	case 0:
//		vfd_send(0x14);
//		break;
//	case 1:
//		vfd_send(0x13);
//		break;
//	}
//}
//
//void vfd_set_brightness(int b) {
//	int br;
//	switch(b){
//	case 1:
//		br = 0x20;
//		break;
//	case 2:
//		br = 0x40;
//		break;
//	case 3:
//		br = 0x60;
//		break;
//	default:
//		br = 0xff;
//	}
//	vfd_send(0x01);
//	vfd_send(br);
//}

void vfd_reset(void) {
	vfd_send(RESET);
	_delay_ms(10);
}
