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
	sendLog("Changing to Slave Select 3");
	P3DIR |= BIT3;
	if(state == HIGH){
		P3OUT |= BIT3;
	}
	else if(state == LOW){
		P3OUT &= ~BIT3;
	}
}


/*
 * Configures the SPI module for reading barometric pressure.
 */
void configure_SPI_MODULE_BAROMETER(void){
	UCB0CTLW0 |= UCSWRST;// Put eUSCI in reset

	UCB0CTLW0 &= ~UCPEN;					//select Frame parameters and clock source; parity disabled
	UCB0CTLW0 |=UCMSB;					//MSB first

	UCB0CTLW0 &= ~UC7BIT;				// 8 bit data
	UCB0CTLW0 |= UCMODE_2;				//SPI ACTIVE LOW

	UCB0CTLW0 |= UCMST;

	UCB0CTLW0 &= ~UCSPB;					//one stop bit
	UCB0CTLW0 |= UCSSEL_2;				//SMCLK
	UCB0BR0 = 26; 						//set baud rate
	UCB0BR1 = 0;

}
/*
 * Configures the SPI module for reading temperature.
 */
void configure_SPI_MODULE_TEMP(void){
	UCB0CTLW0 |= UCSWRST;// Put eUSCI in reset

	UCB0CTLW0 &= ~UCPEN;					//select Frame parameters and clock source; parity disabled
	UCB0CTLW0 |=UCMSB;					//MSB first

	UCB0CTLW0 &= ~UC7BIT;				// 8 bit data
	UCB0CTLW0 |= UCMODE_2;				//SPI ACTIVE LOW

	UCB0CTLW0 |= UCMST;

	UCB0CTLW0 &= ~UCSPB;					//one stop bit
	UCB0CTLW0 |= UCSSEL_2;				//SMCLK
	UCB0BR0 = 26; 						//set baud rate
	UCB0BR1 = 0;

}


/*
 * Configures the SPI module for reading humidity.
 */
void configure_SPI_MODULE_HUMIDITY(void){
	UCB0CTLW0 |= UCSWRST;// Put eUSCI in reset

	UCB0CTLW0 &= ~UCPEN;					//select Frame parameters and clock source; parity disabled
	UCB0CTLW0 |=UCMSB;					//MSB first

	UCB0CTLW0 &= ~UC7BIT;				// 8 bit data
	UCB0CTLW0 |= UCMODE_2;				//SPI ACTIVE LOW

	UCB0CTLW0 |= UCMST;

	UCB0CTLW0 &= ~UCSPB;					//one stop bit
	UCB0CTLW0 |= UCSSEL_2;				//SMCLK
	UCB0BR0 = 26; 						//set baud rate
	UCB0BR1 = 0;

}

int16_t spi_putchar(void){
	rx_data = 0;
	while(!(UCB0IFG & UCRXIFG));//block until transmitter is ready
	rx_data = UCB0RXBUF;//load data onto buffer
	return rx_data;
}


