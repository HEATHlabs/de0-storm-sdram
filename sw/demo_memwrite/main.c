#include "../lib/storm_core.h"
#include "../lib/storm_soc_basic.h"
#include "../lib/io_driver.c"
#include "../lib/utilities.c"
#include "../lib/uart.c"

#define SDRAM_ADDR 0x1000000
#define PATTERN 0x5A5A5A5A
#define MEMCELLS 1
#define BASE_ADDRESS  (volatile datum *) SDRAM_ADDR
// +------------------------------+
// |    Simple Program Demo       |
// +------------------------------+

typedef unsigned long datum;
unsigned long int qbytes_to_long ( unsigned char *buffer )
{
	unsigned char d = buffer[0];
	unsigned char c = buffer[1];
	unsigned char b = buffer[2];
	unsigned char a = buffer[3];
	unsigned long n;


	n = a|(b<<8)|(c<<16)|(d<<24);
	return n;
}

/* ---- Main function ---- */
int main(void)
{
	unsigned long temp;
	char str_ptr[10];
	int index;
	unsigned int volatile * address = (unsigned int volatile*) SDRAM_ADDR;
	// unsigned long volatile  * address = BASE_ADDRESS;
	// Intro
	// str_ptr[0]=0x00;
	// str_ptr[1]=0x00;
	// str_ptr[2]=0x0a;
	// str_ptr[3]=0x30;
	// temp = qbytes_to_long(str_ptr);
	// long_to_hex_string(temp, str_ptr, 8);
	// uart0_printf(str_ptr);
	// uart0_printf("\r\n");
	uart0_printf("Demo program\r\n\r\n");
	temp=get_syscpreg((char)6);
	long_to_hex_string(temp, str_ptr, 8);
	uart0_printf("System Control-6: ");
	uart0_printf(str_ptr);
	uart0_printf("\n\r");
	set_syscpreg(0x00080080,(char)6);
	temp=get_syscpreg((char)6);
	long_to_hex_string(temp, str_ptr, 8);
	uart0_printf("System Control-6: ");
	uart0_printf(str_ptr);
	uart0_printf("\n\r");
	
	
	
	

		*address = PATTERN;
	
	for (index=0; index<4; index++){
		temp = *address++;
		long_to_hex_string(temp, str_ptr, 8);
		uart0_printf(str_ptr);
		uart0_printf("\n\r");
	}
	uart0_printf("\r\n");
	uart0_printf("Demo End\r\n\r\n");
	
	}



	
	
