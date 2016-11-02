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




/* ---- Main function ---- */
int main(void)
{
	int temp;



	// Intro
	uart0_printf("\r\n\r\nSTORM SoC Basic Configuration\r\n");
	uart0_printf("Demo program + 2nd UART\r\n\r\n");
	while (1) {
		//uart0_printf("Press any key!\r\n");
		_outbyte('A'); //ascii 41
		_outbyte('m');//ascii 6d
		_outbyte('b'); //ascii 62
		_outbyte('e'); //ascii 65
		_outbyte('r'); //ascii 72
		_outbyte(' '); //ascii 20
		_outbyte('U'); //ascii 55
		_outbyte('A'); //ascii 41
		_outbyte('R'); //ascii 52
		_outbyte('T'); //ascii 54
		// echo received char
	}
}
