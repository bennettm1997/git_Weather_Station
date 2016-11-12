/*
 * Take all of the data that we sampled, and packetize it. Meaning that we send over a set packet of data.
 * A zero within the packet of data will represent that we did not sample and send the data.
 * This data will be put onto a circular buffer that takes in object/struct
 */
#include "packetizeData.h"
#include <stdlib.h>
#include <stdio.h>


struct Packet_Data{
	uint16_t temperature;
	uint16_t barometric_Pressure;
	uint16_t altitude;
	uint16_t daylight_Level;
}Weather_Packet;



