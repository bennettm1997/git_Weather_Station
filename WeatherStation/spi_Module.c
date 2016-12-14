#include "spi_Module.h"



//pin 6.0 state 1 for high 0 for low
//Code inside here was test code to get the project working. It didnt work.
void slaveSelect1(void){
	sendLog("Changing to Slave Select 1",26);
	P6DIR |= BIT0;
	//if(state == HIGH){
		P6OUT &= ~BIT0;
		rx_data = 0;
		int i = 0;
		for(i = 0; i<500; i++);
		while(!(UCB0IFG & UCTXIFG));
		UCB0TXBUF = 0x0F;
		sendLog("Test 1", 6);
		for(i = 0; i<500; i++);
		while(!(UCB0IFG & UCRXIFG));//block until transmitter is ready
		rx_data = (UCB0RXBUF << 8);//load data onto buffer
		for(i = 0; i<500; i++);
		while(!(UCB0IFG & UCTXIFG));
		UCB0TXBUF = 0xFF;
		sendLog("Test 2", 6);
		for(i = 0; i<500; i++);
		while(!(UCB0IFG & UCRXIFG));//block until transmitter is ready
		rx_data |= UCB0RXBUF;//load data onto buffer
		P6OUT |= BIT0;
	/*}
	else if(state == LOW){// Sets pin Low
		P6OUT &= ~BIT0;
	}*/
}

//pin 3.2 state 1 for high 0 for low
void slaveSelect2(int state){
	sendLog("Changing to Slave Select 2",26);
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
	sendLog("Changing to Slave Select 3",26);
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

	//UCB0CTLW0 &= ~UCSPB;					//one stop bit
	UCB0CTLW0 |= UCSSEL_2;				//SMCLK
	UCB0BR0 = 2; 						//set baud rate
	UCB0BR1 = 0;


	NVIC_EnableIRQ(EUSCIB0_IRQn);


}
/*
 * Configures the SPI module for reading temperature.
 */
void configure_SPI_MODULE_TEMP(void){
	UCB0CTL1 |= UCSWRST;// Put eUSCI in reset

	UCB0CTL0 = 0;
	UCB0CTL0 = UCCKPL | UCMST | UCSYNC | UCMSB;
	UCB0CTL1 |= UCSSEL_2;

	UCB0CTLW0 &= ~UC7BIT;				// 8 bit data

	UCB0CTLW0 |= UCMODE_0;				//SPI ACTIVE LOW

	UCB0BR0 = 2; 						//set baud rate
	UCB0BR1 = 0;

	UCB0CTL1 &= ~UCSWRST;

	UCB0IE |= BIT0 | BIT1;

	P1SEL0 |= BIT5;//SCLK
	P1SEL1 &= ~BIT5;

	P1SEL0|=BIT7;//MISO
	P1SEL1 &= ~BIT7;

	P1SEL0|=BIT6;//MOSI
	P1SEL1 &= ~BIT6;

	NVIC->ISER[0] = 1 << ((EUSCIB0_IRQn) & 31);

}


/*
 * Configures the SPI module for reading humidity.
 */
void configure_SPI_MODULE_HUMIDITY(void){
	UCB0CTLW0 |= UCSWRST;// Put eUSCI in reset

	UCB0CTLW0 |= UCPEN;					//select Frame parameters and clock source; parity disabled
	UCB0CTLW0 |=UCMSB;					//MSB first

	UCB0CTLW0 &= ~UC7BIT;				// 8 bit data
	UCB0CTLW0 |= UCMODE_2;				//SPI ACTIVE LOW

	UCB0CTLW0 |= UCMST;

	//UCB0CTLW0 &= ~UCSPB;					//one stop bit
	UCB0CTLW0 |= UCSSEL_2;				//SMCLK
	UCB0BR0 = 26; 						//set baud rate
	UCB0BR1 = 0;

	NVIC_EnableIRQ(EUSCIB0_IRQn);

}

/*extern void EUSCIB0_IRQHandler(void){
	rx_data = 0;
	while(!(UCB0IFG & UCTXIFG));
	UCB0TXBUF = 0x7F;
	sendLog("Test 1", 6);
	while(!(UCB0IFG & UCRXIFG));//block until transmitter is ready
	rx_data = (UCB0RXBUF << 8);//load data onto buffer
	while(!(UCB0IFG & UCTXIFG));
	UCB0TXBUF = 0x7F;
	sendLog("Test 2", 6);
	while(!(UCB0IFG & UCRXIFG));//block until transmitter is ready
	rx_data |= UCB0RXBUF;//load data onto buffer
}*/
