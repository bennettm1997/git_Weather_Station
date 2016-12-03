#include "msp.h"
#include "powerMode.h"
#include "send_Log.h"


/*In low power mode we will decrease the ADC sampling rate to a minimum. - Change the capture compare register to a lower value, to decrease the sampling rate.
 * In High power mode we will sample at the fastest rate we can within reason.
 *
 */
typedef enum POW_CHK_t{
	BUTTONPUSHHIGH = 1,
	BUTTONPUSHLOW = -1,
	BUTTONPUSHOFF = 0 ;
}POW_CHK;

void low_Power(void){
//set clock to have a frequency of 60 secs. and pull data at this time



	sendLog("Low Power Mode Enabled")
}
void high_Power(void){
	//set clock to have a frequency of 10 secs. and pull data at this time

	sendLog("High Power Mode Enabled")
}
//We will need a button interrupt handler for this function
POW_CHK Check_Power(void){
	if(BUTTON == BUTTONPUSHLOW){
		return BUTTONPUSHLOW;
	}
	if(BUTTON == BUTTONPUSHHIGH){
		return BUTTONPUSHHIGH;
	}
	if(BUTTON == BUTTONPUSHOFF){
		return BUTTONPUSHOFF;
	}
}


