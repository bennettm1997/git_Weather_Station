#ifndef _packetizeData_h
#define _packetizeData_h
#include <stdint.h>
#include "system_Configure.h"
#include "msp.h"
#include <stdlib.h>
#include <stdio.h>
#include "get_Data.h"
#include <stdlib.h>
#include "send_Log.h"


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
		uint16_t humidity;
	}Weather_Packet;
typedef enum PACKET_ITEM{
		TEMPERATURE = 5,
		BAROMETRIC_PRESSURE = 6,
		HUMIDITY = 7,
	}ITEM;
void Add_Item_To_Packet(Weather_Packet *w_Packet, ITEM item, int16_t value);
uint8_t sendAPacket(Weather_Packet * w_Packet);
int itoa(int value,char *ptr);
#endif
