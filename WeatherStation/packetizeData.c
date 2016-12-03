/*
 * Take all of the data that we sampled, and packetize it. Meaning that we send over a set packet of data.
 * A zero within the packet of data will represent that we did not sample and send the data.
 * This data will be put onto a circular buffer that takes in object/struct
 */
#include "packetizeData.h"
#include <stdlib.h>
#include <stdio.h>
#include "get_Data.h"
#include <stdlib.h>
#include "sendLog.h"
#define ERROR -1
#define GOOD 0;
#define



typedef enum PACKET_ITEM{
	TEMPERATURE = 5,
	BAROMETRIC_PRESSURE = 6,
	ALTITUDE = 7,
	DAYLIGHT_LEVEL = 8,
}ITEM;

/*
 * Fills the defualt packet to send over bluetooth.
 * Paramaters: w_Packet: Instance of a weather packet
 */
void Add_Item_To_Packet(Weather_Packet *w_Packet, ITEM item, uint16_t value){
	sendLog("Filling Weather Packet");
	//change to call itoa on these

	if(item == TEMPERATURE){
		w_Packet-> temperature = value;
	}
	else if (item == BAROMETRIC_PRESSURE){
		w_Packet-> barometric_Pressure = value;

	}
	else if (item == ALTITUDE){
		w_Packet-> altitude = value;

	}
	else if (item == DAYLIGHT_LEVEL){
		w_Packet-> daylight_Level = value;
	}
}
/*
 * Returns GOOD, if weather packet is full. GOOD = 0
 * Returns ERROR, if weather packet has yet to be filled. ERROR =-1
 */
int isFull(Weather_Packet *w_Packet){
	if((w_Packet-> temperature) != 0 && (w_Packet-> barometric_Pressure) != 0 && (w_Packet-> altitude) != 0 && (w_Packet-> daylight_Level) != 0){
		return GOOD;
	}
	else{
		return ERROR;
	}
}

//possibly add and identifier letting the computer know what kind of data it is. If the serial data has a * infront, then it is this kind of data.
int sendAPacket(Weather_Packet * w_Packet){
	sendLog("Sending Weather Packet");
	if((w_Packet-> barometric_Pressure) != 0 && (w_Packet-> altitude) != 0 && (w_Packet-> daylight_Level) != 0){//check if all values are not 0 inside w_Packet{
		uart_putchar('*');
		uart_putchar(w_Packet-> temperature);
		uart_putchar(w_Packet-> barometric_Pressure);
		uart_putchar(w_Packet-> altitude);
		uart_putchar(w_Packet-> daylight_Level);

		return GOOD;
	}
	else{
		return ERROR;
	}
}







