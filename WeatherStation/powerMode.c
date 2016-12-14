
#include "powerMode.h"



/*In low power mode we will decrease the ADC sampling rate to a minimum. - Change the capture compare register to a lower value, to decrease the sampling rate.
 * In High power mode we will sample at the fastest rate we can within reason.
 *
 */
#define BUTTONPUSHON  3
#define	BUTTONPUSHHIGH  2
#define	BUTTONPUSHLOW  1
#define	BUTTONPUSHOFF  0

extern void PORT1_IRQHandler(void){
	if(P1IFG & BIT4){
		BUTTON = BUTTONPUSHLOW;
		P1IFG &= ~BIT4;
	}
	else if(P1IFG & BIT1){
		BUTTON = BUTTONPUSHHIGH;
		P1IFG &= ~BIT1;
	}
}


int stateLow = 0;
int stateHigh = 0;
void Check_Power(uint8_t BUTTON){
	while(BUTTON == BUTTONPUSHLOW){//button is low
		stateHigh = 0;
		if(stateLow == 0){
			sendLog("Low Power Mode Enabled",22);//log

		}
		stateLow = 1;
		get_All_Data_Slow();
	}
	while(BUTTON == BUTTONPUSHHIGH){//while button is high
		stateLow = 0;
		if(stateHigh == 0){
			sendLog("High Power Mode Enabled",23);//log
		}
		stateHigh = 1;
		get_All_Data_Fast();
	}


}


