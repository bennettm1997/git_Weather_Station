#include "spi_Module.h"
#define ERROR -1
#define SUCCESS 0
#define HIGH 1
#define LOW 0


//pin 6.0 state 1 for high 0 for low
void slaveSelect1(int state){
	sendLog("Changing to Slave Select 1");
	P6DIR |= BIT0;
	if(state == HIGH){
		P6OUT |= BIT0;
	}
	else if(state == LOW){
		P6OUT &= ~BIT0;
	}
}

//pin 3.2 state 1 for high 0 for low
void slaveSelect2(int state){
	sendLog("Changing to Slave Select 2");
	P3DIR |= BIT2;
	if(state == HIGH){
		P3OUT |= BIT2;
	}
	else if(state == LOW){
		P3OUT &= ~BIT2;
	}
}

//pin 3.3 state 1 for high 0 for low
void slaveSelect3(int state){
	sendLog("Changing to Slave Select 3")
	P3DIR |= BIT3;
	if(state == HIGH){
		P3OUT |= BIT3;
	}
	else if(state == LOW){
		P3OUT &= ~BIT3;
	}
}

//this is what will recieve the data
//pin 4.1 input
//check the voltage on the input pins (might not be high enough) if it is not reading values
void MISO(void){
	P4OUT &= ~BIT1; //set to input
	
	//This is the input data
	//You will have to figure out how the data is sent across the IC's and what they mean. LSB first or MSB..
}
/*
Master Out Slave In Line. This may not be necessary for our peripherals. 
This line communicates the data from the master(msp432) to the slave devices (peripheral IC chips)
*/
void MOSI(void){

}
void configure_SPI_Clock(void){
//oscillate the SPI CLOCK PIN at the frequency that is decided upon (1kHZ)
//create a new timer at 1khz
//add the timer interrupt handler -- this will actually flip the pin
	((*((volatile uint16_t *)(0x40000012)))) =3000;//Our multiplier. 37000 Iterations with the correct stepdown enables us to output a 5hz waveform
	TA0CCTL0 = TAIE | CCIE;//Capture compare interrupt enable and Timer A Interrupt Enable
	TA0CTL = (TIMER_A_CTL_MC_1 | TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_IE | TIMER_A_CTL_ID__2);//Enabling the correct macros to use a timer interrupt
	TA0R = 0;//This clears Timer A
	NVIC_EnableIRQ(TA0_0_IRQn);//This enables the NVIC for A0 Timer
}

void SPI_MODULE_IRQ_HANDLER(void){
	//What we actually do when the interupt is enabled.
		if(TA0CCTL0 & CCIFG){
			P4OUT |= BIT3;
		}
	TA0CCTL0 &=~CCIFG;
}

void configure_SPI_MODULE(void){
	UCA1CTLW0 |= UCSWRST;// Put eUSCI in reset

	UCA1CTLW0 & ~UCPEN;					//select Frame parameters and clock source; parity disabled
	UCA1CTLW0 |=UCMSB;					//MSB first

	UCA1CTLW0 &	~UC7BIT;				// 8 bit data
	UCA1CTLW0 |= UCMODE_2;				//SPI ACTIVE LOW

	UCA1CTLW0 |= UCMST;

	UCA1CTLW0 & ~UCSPB;					//one stop bit
	UCA1CTLW0 |= UCSSEL_2;				//SMCLK
	UCA1BR0 = 26; 						//set baud rate
	UCA1BR1 = 0;





}




