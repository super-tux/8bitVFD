#include <avr/io.h>
#include <util/delay.h>

#include "vfd.h"
#include "defines.h"

#include <stdio.h>

FILE vfd_str = FDEV_SETUP_STREAM(vfd_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void) {
	DDRB = 0xff;
	DDRA = 0xff;
	// make busy pin input
	DDRB &= ~(1<<BUSY);
	PORTB = 0xff;
	PORTA = 0xff;

	stdout = &vfd_str;

	vfd_reset();
	vfd_send(0x14);

	printf("Hallo Welt!\n\rTime = ");
	for(long unsigned int i = 0; i < 4294967296; i++) {
		vfd_set_pos(47);
		printf("%02i:%02i:%02i:%02i",(int)(i/360000),(int)((i/6000)%60),(int)((i/100)%60),(int)(i%100));
		//_delay_ms(1);
	}


//	vfd_reset();	// reset
//	vfd_set_cursor(1);
//	vfd_send_string("Hallo Welt!\n\rfoobar ");
//	for(;;) {
//		for(int j = 0x20; j < 256; j+=20){
//			vfd_set_pos(20);
//			for(int i = j; i < j + 20; i++) {
//				vfd_send(i);
//				_delay_ms(100);
//			}
//		}
//	}
}
