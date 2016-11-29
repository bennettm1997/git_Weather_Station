#ifndef _packetizeData_h
#define _packetizeData_h
#include <stdint.h>
#include "system_Configure.h"


/*
 * Creates a struct type that holds 4 values,
 * Temperature: Holds the temperature value to send.
 * Barometric Pressure: Holds the Barometic Pressure as a 16 bit unsigned int
 * Altitude: Holds the Current Altitude as a 16 bit unsignted int
 * Daylight Level: ? Add later if we figure out the Daylight peripheral
 */
typedef	struct Packet_Data_t{
		uint16_t temperature;
		uint16_t barometric_Pressure;
		uint16_t altitude;
		uint16_t daylight_Level;
	}Weather_Packet;
void fill_Packet(Weather_Packet *w_Packet);
int sendAPacket(Weather_Packet * w_Packet);
#endif
