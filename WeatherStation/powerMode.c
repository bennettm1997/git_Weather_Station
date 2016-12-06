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

}
void high_Power(void){

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
int stateLow = 0;
int stateHigh = 0;
void Check_Power(uint8_t BUTTON){
	while(BUTTON == BUTTONPUSHLOW){
		stateHigh = 0;
		if(stateLow == 0){
			sendLog("Low Power Mode Enabled");
		}
		stateLow = 1;
		get_All_Data_Slow();
	}
	while(BUTTON == BUTTONPUSHHIGH){
		stateLow = 0;
		if(stateHigh == 0){
			sendLog("High Power Mode Enabled");
		}
		stateHigh = 1;
		get_All_Data_Fast();
	}
	while(BUTTON == BUTTONPUSHOFF){
		Power_Off();
	}
	while(BUTTON == BUTTONPUSHON){
		Configure_all;

	}
}


