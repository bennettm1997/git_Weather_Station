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
	((*((volatile uint16_t *)(0x40000012)))) =3000;//Our multiplier. 37000 Iterations with the correct stepdown enables us to output a 5hz waveform
	TA0CCTL0 = TAIE | CCIE;//Capture compare interrupt enable and Timer A Interrupt Enable
	TA0CTL = (TIMER_A_CTL_MC_1 | TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_IE | TIMER_A_CTL_ID__2);//Enabling the correct macros to use a timer interrupt
	TA0R = 0;//This clears Timer A
	NVIC_EnableIRQ(TA1_0_IRQn);//This enables the NVIC for A0 Timer


	sendLog("Low Power Mode Enabled")
}
void high_Power(void){
	//set clock to have a frequency of 10 secs. and pull data at this time
	((*((volatile uint16_t *)(0x40000012)))) =3000;//Our multiplier. 37000 Iterations with the correct stepdown enables us to output a 5hz waveform
	TA0CCTL0 = TAIE | CCIE;//Capture compare interrupt enable and Timer A Interrupt Enable
	TA0CTL = (TIMER_A_CTL_MC_1 | TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_IE | TIMER_A_CTL_ID__2);//Enabling the correct macros to use a timer interrupt
	TA0R = 0;//This clears Timer A
	NVIC_EnableIRQ(TA2_0_IRQn);//This enables the NVIC for A0 Timer

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

void TA1_IRQHandler(void){
	////set an if statement to raise a flag to send packet data
	if(TA0CCTL0 & CCIFG){
		SENDPACKET = TRUE;
	}
	TA0CCTL0 &=~CCIFG;
}

void TA2_IRQHandler(void){
	//set an if statement to raise a flag to send packet data
	if(TA0CCTL0 & CCIFG){
		SENDPACKET = TRUE;
	}
	TA0CCTL0 &=~CCIFG;
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


