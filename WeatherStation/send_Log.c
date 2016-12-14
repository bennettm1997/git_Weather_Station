#include "send_Log.h"


//Sends log across UART.
void sendLog(char strng[], uint16_t length){
	uart_putchar('?'); //Logging identifier
	uint8_t i = 0;
	for(i = 0; i<length; i++){
		uart_putchar(strng[i]);
	}
	uart_putchar('\n');
}
