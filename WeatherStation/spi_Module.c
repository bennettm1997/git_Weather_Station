#include "spi_Module.h"


//pin 6.0 state 1 for high 0 for low
void slaveSelect1(int state){
	sendLog("Changing to Slave Select 1");
	P6DIR |= BIT0;
	if(state == HIGH){
		P6OUT |= BIT0;
	}
	else if(state == LOW){// Sets pin Low
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

void SPI_MODULE_IRQ_HANDLER(void){
	//What we actually do when the interupt is enabled.
		if(TA0CCTL0 & CCIFG){
			P4OUT |= BIT3;
		}
	TA0CCTL0 &=~CCIFG;
}
/*
 * Configures the SPI module for reading barometric pressure.
 */
void configure_SPI_MODULE_BAROMETER(void){
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
/*
 * Configures the SPI module for reading temperature.
 */
void configure_SPI_MODULE_TEMP(void){
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


/*
 * Configures the SPI module for reading humidity.
 */
void configure_SPI_MODULE_HUMIDITY(void){
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




