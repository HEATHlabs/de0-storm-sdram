#include "../newlib/storm_core.h"
#include "../newlib/storm_soc_basic.h"
#include "../newlib/io_driver.c"
#include "../newlib/utilities.c"
#include "../newlib/uart.c"
#include "stdio.h"


// +------------------------------+
// |    Simple Program Demo       |
// +------------------------------+

//  Also a demo output to the terminal is made.
// Received UART transmission are echoed.

void init_current_time()
{
    /* Configure timer 0 */
    /* Counts down from this value and generates an interrupt every 1/100 seconds */
    TIMER0_LOAD  = 0xFF; // 16-bit, x 256
    TIMER0_CTRL  = 0xc8;  // enable[7], periodic[6], 

    /* Enable timer 0 interrupt */
   // *(unsigned int *) ( ADR_AMBER_IC_IRQ0_ENABLESET ) = 0x020;

    //current_time_g = malloc(sizeof(time_t));
    //current_time_g->milliseconds = 0;
   // current_time_g->seconds = 0;
}

void check_timer (int icount) 
{
	
	if ( TIMER0_VALUE < icount) {
		uart0_printf("timer under count\n\r");
		init_current_time();
	}

}

void uart1_print() {
		_outbyte('A'); //ascii 41
		_outbyte('m'); //ascii 6d
		_outbyte('b'); //ascii 62
		_outbyte('e'); //ascii 65
		_outbyte('r'); //ascii 72
		_outbyte(' '); //ascii 20
		_outbyte('U'); //ascii 55
		_outbyte('A'); //ascii 41
		_outbyte('R'); //ascii 52
		_outbyte('T'); //ascii 54
		_outbyte(' '); //ascii 20
}

/* ---- Main function ---- */
int main(void)
{
	int temp;
	init_current_time();
	// Intro
	uart0_printf("\r\n\r\nSTORM SoC Basic Configuration\r\n");
	uart0_printf("Demo program + Timer\r\n\r\n");
	uart1_print();
		while (1) {
		 //TIMER0_LOAD  = 1562;

		check_timer (50) ;
	}
}
