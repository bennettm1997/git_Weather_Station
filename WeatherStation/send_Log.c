#include "send_Log.h"


/*
 * This function will just send a string of characters across UART-
 * We will need to add a handler for all of these logs -Python Script
 * The question mark is our logging identifier. This allows our to recognize Logging versus Data
 */
void sendLog(char strng[], uint16 length){
	uart_putchar('?'); //Logging identifier
	uint8_t i = 0;
	for(i = 0; i<length; i++){
		uart_putchar(strng[i]);
	}
}
