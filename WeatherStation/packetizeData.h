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

/*
	 * Fills the defualt packet to send over bluetooth.
	 * Paramaters: w_Packet: Instance of a weather packet
*/
void Add_Item_To_Packet(Weather_Packet *w_Packet, ITEM item, int16_t value);

/*
 * Takes the packet items: Barometric pressure, temperature, and humidity and if they are not 0. It first sends an identifier '*'.
 * Then sends each of the items in the packet as a string (ITOA) across uart(bluetooth).
 */
uint8_t sendAPacket(Weather_Packet * w_Packet);


/*
 * Clears the contents of the weather packet.
 */
void clear_Packet(Weather_Packet * w_Packet);


/*
 * Converts a 16 bit into into ascii data. Sends ascii across UART.
 */
void itoa(int16_t num);

#endif
