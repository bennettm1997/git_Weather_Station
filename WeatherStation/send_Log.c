#include "send_Log.h"
#include "msp.h"

/*
 * This function will just send a string of characters across UART-
 * We will need to add a handler for all of these logs -Python Script
 * The question mark is our logging identifier. This allows our to recognize Logging versus Data
 */
void sendLog(char strng[]){
	uart_putchar('?'); //Logging identifier
	uint_8 length = 100;
	uint_8 i = 0;
	for(i = 0; i<length; i++){
		uart_putchar(strng[i]);
	}
}
