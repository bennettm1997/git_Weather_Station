/*
 * Take all of the data that we sampled, and packetize it. Meaning that we send over a set packet of data.
 * A zero within the packet of data will represent that we did not sample and send the data.
 * This data will be put onto a circular buffer that takes in object/struct
 */
#include "packetizeData.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1
#define GOOD 0




void Add_Item_To_Packet(Weather_Packet *w_Packet, ITEM item, int16_t value){
	sendLog("Filling Weather Packet",22);//logging identifier

	if(item == TEMPERATURE){//if item is said to be temp
		w_Packet-> temperature = value;//load item onto packet
	}
	else if (item == BAROMETRIC_PRESSURE){//if item is said to be barometric pressure.
		w_Packet-> barometric_Pressure = value;//load item onto packet.

	}
	else if (item == HUMIDITY){//if item is said to be barometric pressure
		w_Packet-> humidity = value;//load item onto packet

	}
}



uint8_t sendAPacket(Weather_Packet * w_Packet){
	sendLog("Sending Weather Packet",22);//logging
	if((w_Packet-> barometric_Pressure) != 0 && (w_Packet-> temperature) != 0 && (w_Packet-> humidity) != 0){//check if all values are not 0 inside w_Packet{
		uart_putchar('*');//logging identifier
		uart_putchar('\n');
		itoa(w_Packet-> temperature);//sends temp ascii
		uart_putchar('\n');
		itoa(w_Packet-> barometric_Pressure);//sends barometric pressure ascii
		uart_putchar('\n');
		itoa(w_Packet-> humidity);//sends humidity ascii
		uart_putchar('\n');
		uart_putchar('}');//end log
		return GOOD;

	}
	else{
		return ERROR;//not used: for timing issues.
	}
}

void clear_Packet(Weather_Packet * w_Packet){
		w_Packet-> temperature = 0;
		w_Packet-> barometric_Pressure = 0;
		w_Packet-> humidity = 0;
}

void itoa(int16_t num){
	uint8_t p_hold = 0;
	uint8_t p_hold2 = 0;
	uint8_t p_hold3 = 0;
	if(num == 1)uart_putchar(1);
	if(num < 0){
		uart_putchar('-');
		num = num * -1;
	}
	if(num < 10){
		p_hold = num + 48;//48 ascii offset
		uart_putchar(p_hold);
	}
	else if((num >= 10) && (num < 100)){//tens place
		p_hold = (num % 10) + 48;
		p_hold2 = (num / 10) + 48;
		uart_putchar(p_hold2);
		uart_putchar(p_hold);
	}
	else if ((num>=100) && (num<1000)){//thousands place
		p_hold = (num % 10) + 48;
		p_hold2 = (num / 100) + 48;
		p_hold3 = ((num % 100) / 10) + 48;
		uart_putchar(p_hold2);
		uart_putchar(p_hold3);
		uart_putchar(p_hold);
	}
}


