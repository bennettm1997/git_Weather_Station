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



/*
 * Fills the defualt packet to send over bluetooth.
 * Paramaters: w_Packet: Instance of a weather packet
 */
void Add_Item_To_Packet(Weather_Packet *w_Packet, ITEM item, int16_t value){
	sendLog("Filling Weather Packet",22);

	if(item == TEMPERATURE){
		w_Packet-> temperature = value;
	}
	else if (item == BAROMETRIC_PRESSURE){
		w_Packet-> barometric_Pressure = value;

	}
	else if (item == HUMIDITY){
		w_Packet-> humidity = value;

	}
}
/*
 * Returns GOOD, if weather packet is full. GOOD = 0
 * Returns ERROR, if weather packet has yet to be filled. ERROR =-1
 */


//possibly add and identifier letting the computer know what kind of data it is. If the serial data has a * infront, then it is this kind of data.
uint8_t sendAPacket(Weather_Packet * w_Packet){
	sendLog("Sending Weather Packet",22);
	if((w_Packet-> barometric_Pressure) != 0 && (w_Packet-> temperature) != 0 && (w_Packet-> humidity) != 0){//check if all values are not 0 inside w_Packet{
		uart_putchar('*');
		itoa(w_Packet-> temperature);
		uart_putchar('\n');
		itoa(w_Packet-> barometric_Pressure);
		uart_putchar('\n');
		itoa(w_Packet-> humidity);
		uart_putchar('\n');
		return GOOD;

	}
	else{
		return ERROR;
	}
}

void clear_Packet(Weather_Packet * w_Packet){
		w_Packet-> temperature = 0;
		w_Packet-> barometric_Pressure = 0;
		w_Packet-> humidity = 0;
}


/*Function return size of string and convert signed  *
 *integer to ascii value and store them in array of  *
 *character with NULL at the end of the array        */
// This function was found online : Not ours.
void itoa(int16_t num){
	uint8_t p_hold = 0;
	uint8_t p_hold2 = 0;
	uint8_t p_hold3 = 0;
	if(num < 0){
		uart_putchar('-');
		num = num * -1;
	}
	if(num < 10){
		p_hold = num + 48;
		uart_putchar(p_hold);
	}
	else if((num >= 10) && (num < 100)){
		p_hold = (num % 10) + 48;
		p_hold2 = (num / 10) + 48;
		uart_putchar(p_hold2);
		uart_putchar(p_hold);
	}
	else if ((num>=100) && (num<1000)){
		p_hold = (num % 10) + 48;
		p_hold2 = (num / 100) + 48;
		p_hold3 = ((num % 100) / 10) + 48;
		uart_putchar(p_hold2);
		uart_putchar(p_hold3);
		uart_putchar(p_hold);
	}
}


