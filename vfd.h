#define SET_POS 	0x10
#define RESET 		0x1f


//	initialize the display
void vfd_init(void);

// send a byte to the display
void vfd_send(int data);
int vfd_putchar(char c);

// send a ASCII string to the display
void vfd_send_string(char* str);

// set the cursor position
void vfd_set_pos(int pos);

// set the cursor mode, 0 = off, 1 = on, 2 = blink
void vfd_set_cursor(int c);

// reset the display
void vfd_reset(void);

// set the brightness of the display. (1=20%,2=40%,2=60%,4=100%)
void vfd_set_brightness(int b);

