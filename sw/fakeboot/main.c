#include "../lib/storm_core.h"
#include "../lib/storm_soc_basic.h"
#include "../lib/io_driver.c"
#include "../lib/utilities.c"
#include "../lib/uart.c"


#define SDRAM_ADDR 0x1000000
#define PATTERN 0x5A5A5A5A
#define IMGSIZE 0x20
#define BASE_ADDRESS  (volatile datum *) SDRAM_ADDR

// +------------------------------+
// |    Simple Program Demo       |
// +------------------------------+
unsigned long int qbytes_to_long ( unsigned char buffer[10] )
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
	int temp;


	// Intro
	uart0_printf("\r\n\r\nSTORM SoC Basic Configuration\r\n");
	uart0_printf("Fakeboot program\r\n\r\n");
	while(data_pointer != IMGSIZE){
		uart0_scanf(buffer,4,0); // get word
		*data_pointer = qbytes_to_long(buffer); // store memory entry
		data_pointer = data_pointer + 1;
	}

	uart0_printf("Press any key!\r\n");

	// echo received char
	while(1){

	}

}
