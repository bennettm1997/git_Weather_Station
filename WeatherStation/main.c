
#include "msp.h"
#include "system_Configure.h"
#include "packetizeData.h"
#include "send_Log.h"
void main(void)
{
	hi
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    __enable_interrupt(); //enable global interrupts
    configure_All(); //change to configure all later


    Weather_Packet packet;
    fill_Packet(&packet);
    sendLog("What is the sq rtts");
    int i;
    //tests sending data over bluetooth
    for(i = 0; i<10; i++){
    	sendAPacket(&packet);//sends the packet
    }

}

