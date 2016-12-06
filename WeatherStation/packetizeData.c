/*
 * Take all of the data that we sampled, and packetize it. Meaning that we send over a set packet of data.
 * A zero within the packet of data will represent that we did not sample and send the data.
 * This data will be put onto a circular buffer that takes in object/struct
 */
#include "packetizeData.h"

#define ERROR -1
#define GOOD 0



/*
 * Fills the defualt packet to send over bluetooth.
 * Paramaters: w_Packet: Instance of a weather packet
 */
void Add_Item_To_Packet(Weather_Packet *w_Packet, ITEM item, int16_t value){
	sendLog("Filling Weather Packet");

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
	sendLog("Sending Weather Packet");
	char *ITOA_PTR = 0;
	if((w_Packet-> barometric_Pressure) != 0 && (w_Packet-> temperature) != 0 && (w_Packet-> humidity) != 0){//check if all values are not 0 inside w_Packet{
		uart_putchar('*');
		uart_putchar(itoa((w_Packet-> temperature), ITOA_PTR));
		uart_putchar(itoa((w_Packet-> barometric_Pressure),ITOA_PTR));
		uart_putchar(itoa((w_Packet-> humidity),ITOA_PTR));
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

