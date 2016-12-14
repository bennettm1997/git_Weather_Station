#include "system_Configure.h"



/*
Configures our Clocks and sets the DCO clock to 1.5Mhz
*/
void configure_clocks(void)
{
	CS->KEY = 0x695A; 					//Unlock cs module for register access
	CS->CTL0 = 0; 						// reset tuning parameters
	CS->CTL0 |= CS_CTL0_DCORSEL_0;	     // 1.5MHz
	CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
	CS->KEY = 0;//lock module
	//SLEEPDEEP &= ~BIT2;
}
/*
Configures our serial port for Bluetooth transmission

Port 1.2 and 1.3 are acting as our TXD and RXD pins. This is the EUSCI SPI 
P1.2: UCA0RXD
P1.3: UCA0TXD
*/
void configure_serial_port(){
	//configure UART pins, set 2 UART pin as a primary function
	P1SEL0 |= BIT2;
	P1SEL1 &= ~BIT2;
	P1SEL0 |= BIT3;
	P1SEL1 &= ~BIT3;
	
	//configure UART
	UCA0CTLW0 |= UCSWRST;                // Put eUSCI in reset
	UCA0CTLW0 & ~UCPEN;					//select Frame parameters and clock source; parity disabled
	UCA0CTLW0 & ~UCMSB;					//lsb first
	UCA0CTLW0 &	~UC7BIT;				// 8 bit data
	UCA0CTLW0 |= UCMODE_0;				//UART mode
	//UCA0CTLW0 & ~UCSPB;					//one stop bit
	UCA0CTLW0 |= UCSSEL_2;				//SMCLK
	UCA0BR0 = 156; 						//set baud rate, to 1.5MHZ
	UCA0BR1 = 0;
	UCA0CTLW0 &= ~UCSWRST;				// Initialize eUSCI
	UCA0IE |= BIT0; //Enable USCI_A0 TX interrupts
	NVIC->ISER[0] = 1 << ((EUSCIA0_IRQn) & 31);  //Enable eUSCIA0 interrupt in NVIC
}
/*
uart_putchar takes in an 8 bit integer and if the transmitter is ready, data is loaded onto the Tx buffer, to send across UART.
*/

void uart_putchar(uint8_t tx_data){
	while(!(UCA0IFG & UCTXIFG));//block until transmitter is ready
	UCA0TXBUF = tx_data;//load data onto buffer
}
void uart_putchar_n(uint8_t * data, uint32_t length){
	int i;
	for(i = 0; i<length; i++){
		uart_putchar(*data);
        data++;
	}
}
void configure_pins(){
	//Configures 1.7 Switch

	P1DIR &=~BIT1;//Changes to be input
	P1REN |= BIT1;//Pullup vs Pulldown resistor
	P1OUT|= BIT1;
	P1IES |= BIT1;//Interrupt Edge Select
	P1IFG &= ~BIT1;//Clears any pending port interrupt flags
	P1IE |= BIT1;//This actually enables the pin to be an interrupt


	P1DIR &=~BIT4;// See aboves this is for switch 1.6 same thing
	P1REN |= BIT4;
	P1OUT|= BIT4;
	P1IES |= BIT4;
	P1IFG &= ~BIT4;
	P1IE |= BIT4;//check

	NVIC_EnableIRQ(PORT1_IRQn);
	//NVIC_EnableIRQ(PORT4_IRQn);//Enables the NVIC interrupt vector table for port 1
}
/*
This function calls all of our other configure functions to minimize function calling within the main
*/
void configure_All(){
	configure_clocks();
	configure_serial_port();
	configure_pins();
}
