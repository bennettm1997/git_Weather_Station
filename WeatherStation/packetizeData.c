/*
 * Take all of the data that we sampled, and packetize it. Meaning that we send over a set packet of data.
 * A zero within the packet of data will represent that we did not sample and send the data.
 * This data will be put onto a circular buffer that takes in object/struct
 */
#include "packetizeData.h"
#include <stdlib.h>
#include <stdio.h>
#define ERROR -1
int sendAPacket(Weather_Packet * w_Packet){
	if(1){
		//uart_
	}
	else{
		return ERROR;
	}
}





