#include "send_Log.h"
#include "msp.h"

/*
 * This function will just send a string of characters across UART- this is slightly buggy as it truncates some of the string data
 * We will need to add a handler for all of these logs
 * -How do we discern what kind of log it is. Possibly change all of the return values for success to different values. Each value is mapped to a certain log.
 */
void sendLog(char strng[]){
	uart_putchar('?'); //Logging identifier
	uint_8 length = 100;
	uint_8 i = 0;
	for(i = 0; i<length; i++){
		uart_putchar(strng[i]);
	}
}

