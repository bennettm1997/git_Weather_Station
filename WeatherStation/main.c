
#include "msp.h"
#include "system_Configure.h"
#include "packetizeData.h"
#include "send_Log.h"
#include "powerMode.h"
void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    __enable_interrupt(); //enable global interrupts
    configure_All(); //change to configure all later

    /*
     *
     * We will need a button interrupt handler for this. Continusously checking for button presses will use a lot of resources
     *
#DEFINE BUTTONPUSHLOW 1;
#DEFINE BUTTONPUSHHIGH 1;
#DEFINE BUTTONPUSHOFF  1;
    BUTTON = BUTTONPUSHLOW;
    while(BUTTON == BUTTONPUSHLOW){
    	low_Power();
    	Check_Power();
    }
    while(BUTTON == BUTTONPUSHHIGH){
    	high_Power();
    	Check_Power();
    }
    while(BUTTON == BUTTONPUSHOFF){
    	return 0;
    }
    */


}

