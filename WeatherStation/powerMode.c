#include "msp.h"
#include "powerMode.h"
#include "send_Log.h"
#include "system_Configure.h"


/*In low power mode we will decrease the ADC sampling rate to a minimum. - Change the capture compare register to a lower value, to decrease the sampling rate.
 * In High power mode we will sample at the fastest rate we can within reason.
 *
 */
#DEFINE BUTTONPUSHON = 3
#DEFINE	BUTTONPUSHHIGH = 2
#DEFINE	BUTTONPUSHLOW = 1
#DEFINE	BUTTONPUSHOFF = 0
uint8_t BUTTON;


void low_Power(void){
//set clock to have a frequency of 60 secs. and pull data at this time



	sendLog("Low Power Mode Enabled")
}
void high_Power(void){
	//set clock to have a frequency of 10 secs. and pull data at this time

	sendLog("High Power Mode Enabled")
}

void Power_Off(void){
	SLEEPDEEP |= BIT2;
}


void PORT1_IRQHandler(void){

	if(P1IFG & BIT6){
		BUTTON = BUTTONPUSHLOW;
	}
	else if(P1IFG & BIT7){
		BUTTON = BUTTONPUSHHIGH;
	}
	else if(P1IFG & BIT5){
		BUTTON = BUTTONPUSHOFF;
	}
	return BUTTON;
}

void PORT4_IRQHandler(void){
	if(P4IFG & BIT1){
		BUTTON = BUTTONPUSHON;
	}
	return BUTTON;
}

//We will need a button interrupt handler for this function
void Check_Power(uint8_t BUTTON){
	if(BUTTON == BUTTONPUSHLOW){
		low_Power();
	}
	else if(BUTTON == BUTTONPUSHHIGH){
		high_Power();
	}
	else if(BUTTON == BUTTONPUSHOFF){
		Power_Off();
	}
	else if(BUTTON == BUTTONPUSHON){
		Configure_all;
		low_Power();
	}
}


