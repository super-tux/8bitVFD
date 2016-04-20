#define F_CPU 8000000UL

// UART baud rate
#define UART_BAUD  9600

// VFD port connections
#define WR 0
#define A0 1
#define CS 2
#define BUSY 3
#define DPort PORTA

/* Whether to read the busy flag, or fall back to
   worst-time delays. */
#define USE_BUSY_BIT 1

// dispaly control sequences
//#define clear	0x0C
//#define home	0x0B
//#define cursor_blink	0X13
//#define cursor_noblink	0x13
//#define cursor_off		0x15
