#ifndef _packetizeData_h
#define _packetizeData_h
#include <stdint.h>
#include "system_Configure.h"

typedef	struct Packet_Data_t{
		uint16_t temperature;
		uint16_t barometric_Pressure;
		uint16_t altitude;
		uint16_t daylight_Level;
	}Weather_Packet;
int fill_Packet(Weather_Packet *w_Packet);
int sendAPacket(Weather_Packet * w_Packet);
#endif
