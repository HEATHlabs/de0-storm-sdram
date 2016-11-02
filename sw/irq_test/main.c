#include "../newlib/storm_core.h"
#include "../newlib/storm_soc_basic.h"
#include "../newlib/io_driver.c"
#include "../newlib/utilities.c"
#include "../newlib/uart.c"

// +------------------------------+
// |    Simple Program Demo       |
// +------------------------------+

// This program uses the system timer to toggle LED(0) of the System IO
// port every second. Also a demo output to the terminal is made.
// Received UART transmission are echoed.

void print_irq() {
	//unsigned long reg0;
	unsigned int temp;
	char temp_string[10]="\0";

	temp = IC_IRQ0_STATUS;
	long_to_hex_string(temp, temp_string, 8);
	uart0_printf("IRQ Status: ");
	uart0_printf(temp_string);
	uart0_printf(" \r\n");

	temp = IC_IRQ0_RAWSTAT;
	long_to_hex_string(temp, temp_string, 8);
	uart0_printf("IRQ RAW Status: ");
	uart0_printf(temp_string);
	uart0_printf(" \r\n");
	
	temp = IC_IRQ0_ENABLESET;
	long_to_hex_string(temp, temp_string, 8);
	uart0_printf("IRQ EN SET Status: ");
	uart0_printf(temp_string);
	uart0_printf(" \r\n");
	
	temp = IC_IRQ0_ENABLECLR;
	long_to_hex_string(temp, temp_string, 8);
	uart0_printf("IRQ EN CLR Status: ");
	uart0_printf(temp_string);
	uart0_printf(" \r\n");
	
	temp = IC_INT_SOFTSET_0;
	long_to_hex_string(temp, temp_string, 8);
	uart0_printf("SW INT SET Status: ");
	uart0_printf(temp_string);
	uart0_printf(" \r\n");
	
	temp = IC_INT_SOFTCLEAR_0;
	long_to_hex_string(temp, temp_string, 8);
	uart0_printf("SW INT CLR Status: ");
	uart0_printf(temp_string);
	uart0_printf(" \r\n");
	
	temp = IC_FIRQ0_STATUS;
	long_to_hex_string(temp, temp_string, 8);
	uart0_printf("FIRQ Status: ");
	uart0_printf(temp_string);
	uart0_printf(" \r\n");
}
/* ---- IRQ: Timer ISR ---- */
/////////////////////////////////////////////////////////////
// steps to process interrupt
// 1) Clear interrupt in Peripheral IC_INT_SOFTCLEAR_0
// 2) clear interrupt in int controller IC_IRQ0_ENABLECLR
// 3) Do something
// 4) Re-enable interrupt IC_IRQ0_ENABLEST
/////////////////////////////////////////////////////////////
 void __attribute__ ((interrupt("IRQ"))) sw_int_proc(void)
	{
	io_disable_xint();
	IC_INT_SOFTCLEAR_0 = 0x1;
	IC_IRQ0_ENABLECLR = 0x1;
	
	uart0_printf("Software Interrupt!\r\n");
	IC_IRQ0_ENABLESET = 0x1;
	io_enable_xint(); // enable IRQ ----still works
	
	// toggle status led
	// set_syscpreg((get_syscpreg(SYS_IO) ^ 0x01), SYS_IO);
	// // acknowledge interrupt
	// //VICVectAddr = 0;
 }

// void ic_init () {
	// unsigned long reg0;
	// unsigned int temp;
	// unsigned char temp_string[9];
	
	// temp = IC_IRQ0_STATUS;
	
	// io_disable_xint();
	
	// temp = get_cmsr();
	// long_to_hex_string(temp, temp_string, 8);
	// uart0_printf("cmsr Status: ");
	// uart0_printf(temp_string);
	// uart0_printf("\r\n");
	
	// temp = IC_IRQ0_STATUS;
	// long_to_hex_string(temp, temp_string, 8);
	// uart0_printf("IC Status: ");
	// uart0_printf(temp_string);
	// uart0_printf("\r\n");
	
	// uart0_printf("Clearing Software Interrupt 0\n\r");
	// IC_INT_SOFTCLEAR_0 = 0xFFFFFFFF;
	// IC_IRQ0_ENABLECLR = 0x1;
	// IC_IRQ0_ENABLESET = 0x1;
	
	// temp = IC_IRQ0_STATUS;
	// long_to_hex_string(temp, temp_string, 8);
	// uart0_printf("IC Status: ");
	// uart0_printf(temp_string);
	// uart0_printf("\r\n");
	
	// temp = IC_IRQ0_RAWSTAT;
	// long_to_hex_string(temp, temp_string, 8);
	// uart0_printf("RAW Status: ");
	// uart0_printf(temp_string);
	// uart0_printf("\r\n");
	
	// temp = IC_INT_SOFTSET_0;
	// long_to_hex_string(temp, temp_string, 8);
	// uart0_printf("SOFTSET Status: ");
	// uart0_printf(temp_string);
	// uart0_printf("\r\n");
	
	// temp = get_cmsr();
	// long_to_hex_string(temp, temp_string, 8);
	// uart0_printf("cmsr Status: ");
	// uart0_printf(temp_string);
	// uart0_printf("\r\n");

	// io_enable_xint(); // enable IRQ ----still works
// }

void sw_int () {
	IC_INT_SOFTSET_0 = 0x1;
	uart0_printf("SW INTERUPT!\n\r");
	print_irq();
}
	
void enable_all_int() {
	IC_IRQ0_ENABLESET = 0xFFFFFFFF;
	uart0_printf("Enabling all Interrupts\n\r");
	print_irq();
}

void disable_all_int() {
	IC_IRQ0_ENABLECLR = 0xFFFFFFFF;
	uart0_printf("Disabling all Interrupts\n\r");
	print_irq();
}
/* ---- Main function ---- */
int main(void)
{
	//int temp;
	unsigned int temp;
	unsigned char temp_string[9]="\0";
	
	io_disable_xint();
	// timer init
	//not usingSTME0_CNT  = 0;
	//not using  STME0_VAL  = 50000000; // threshold value for 1s ticks
	// not using STME0_CONF = (1<<2) | (1<<1) | (1<<0); // interrupt en, auto reset, timer enable
	// not using timer  VICVectAddr0 = (unsigned long)timer0_isr;
	//VICVectCntl0 = (1<<5) | 0; // enable and channel select = 0 (timer0)
	//VICIntEnable = (1<<0); // enable channel 0 (timer0)
	
//	ic_init ();
	//uart0_printf("ic_init complete\n\r");
	//io_enable_xint(); // enable IRQ ----still works
	//uart0_printf("io_enable_xint complete\n\r");

	// Intro
	uart0_printf("\r\n\r\nSTORM SoC Basic Configuration\r\n");
	uart0_printf("Interupt Demo program+IRQ test\r\n\r\n");

	print_irq() ;
	
	uart0_printf("Press any key!\r\n");
	uart0_printf("s = print IRQ status\r\n");
	uart0_printf("i = Software Int\r\n");
	uart0_printf("e = Enable all Ints\r\n");
	uart0_printf("d = Disable all Ints\r\n");
	// echo received char


	while(1){
		temp = io_uart0_read_byte();


		if (temp != -1)
			io_uart0_send_byte(temp);
			if (temp == 's') { print_irq(); }
			if (temp == 'i') { sw_int (); }
			if (temp == 'e') { enable_all_int (); }
			if (temp == 'd') { disable_all_int ();}
	}

}
