/*
 * Take all of the data that we sampled, and packetize it. Meaning that we send over a set packet of data.
 * A zero within the packet of data will represent that we did not sample and send the data.
 * This data will be put onto a circular buffer that takes in object/struct
 */
#include "packetizeData.h"
#include <stdlib.h>
#include <stdio.h>
#include "get_Data.h"
#define ERROR -1
#define GOOD 0;


int fill_Packet(Weather_Packet *w_Packet){
	w_Packet-> temperature = get_Temperature();
	w_Packet-> barometric_Pressure = 1;
	w_Packet-> altitude = 2;
	w_Packet-> daylight_Level = 3;
	return 0;
}
int isFull(Weather_Packet *w_Packet){
	if((w_Packet-> temperature) != 0 && (w_Packet-> barometric_Pressure) != 0 && (w_Packet-> altitude) != 0 && (w_Packet-> daylight_Level) != 0){
		return GOOD;
	}
	else{
		return ERROR;
	}
}
int sendAPacket(Weather_Packet * w_Packet){
	if((w_Packet-> temperature) != 0 && (w_Packet-> barometric_Pressure) != 0 && (w_Packet-> altitude) != 0 && (w_Packet-> daylight_Level) != 0){//check if all values are not 0 inside w_Packet{
		uart_putchar(w_Packet-> temperature);
		uart_putchar(w_Packet-> barometric_Pressure);
		uart_putchar(w_Packet-> altitude);
		uart_putchar(w_Packet-> daylight_Level);
	}
	else{
		return ERROR;
	}
	return 0;
}





