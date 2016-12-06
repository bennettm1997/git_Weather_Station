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
#define GOOD 0


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
	char *ITOA_PTR;
	if((w_Packet-> barometric_Pressure) != 0 && (w_Packet-> altitude) != 0 && (w_Packet-> daylight_Level) != 0){//check if all values are not 0 inside w_Packet{
		uart_putchar('*');
		uart_putchar(itoa((w_Packet-> temperature), ITOA_PTR);
		uart_putchar(itoa((w_Packet-> barometric_Pressure),ITOA_PTR);
		uart_putchar(itoa((w_Packet-> altitude),ITOA_PTR);
		uart_putchar(itoa((w_Packet-> daylight_Level),ITOA_PTR);
		return GOOD;
	}
	else{
		return ERROR;
	}
}



/*Function return size of string and convert signed  *
 *integer to ascii value and store them in array of  *
 *character with NULL at the end of the array        */
// This function was found online : Not ours.
int itoa(int value,char *ptr)
     {
        int count=0,temp;
        if(ptr==NULL)
            return 0;
        if(value==0)
        {
            *ptr='0';
            return 1;
        }

        if(value<0)
        {
            value*=(-1);
            *ptr++='-';
            count++;
        }
        for(temp=value;temp>0;temp/=10,ptr++);
        *ptr='\0';
        for(temp=value;temp>0;temp/=10)
        {
            *--ptr=temp%10+'0';
            count++;
        }
        return count;
     }

