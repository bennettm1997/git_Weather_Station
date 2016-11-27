#include "msp.h"
#include "core_cm4.h"
#include "system_Configure.h"

/*
Configure_Pins sets all the pins to the correct orientation, whether it is input/ouput etc.
/* 
void configure_Pins(){
//Set pins to enable buttons

}
/* 
This is where we will configure the ADC to sample properly. -Might not be necessary
*/
extern void configure_ADC(void){
/*

	while(REF_A->CTL0 & REF_A_CTL0_GENBUSY);// IF the reference generator is busy, WAIT
	REF_A->CTL0 = REF_A_CTL0_VSEL_0 | REF_A_CTL0_ON; // Enable internal 1.2V ref
	REF_A->CTL0 &= ~REF_A_CTL0_TCOFF;            // Turn on Temperature Sensor

	// Configure ADC - Pulse sample mode; ADC14SC trigger
	// ADC ON, temperature sample period>30us
	ADC14->CTL0 |= ADC14_CTL0_SHT0_5 | ADC14_CTL0_ON | ADC14_CTL0_SHP;
	ADC14->CTL1 |= ADC14_CTL1_RES__14BIT | ADC14_CTL1_TCMAP;     // Conf internal temp sensor channel, set resolution
	ADC14->MCTL[0] = ADC14_MCTLN_VRSEL_0|ADC14_MCTLN_INCH_22 ;     // Map Temp Analog channel to MEM0/MCTL0, set 3.3v re


	//ADC14->MCTL[0] =  ADC14_MCTLN_INCH_22;   A  // Map Temp Analog channel to MEM0/MCTL0, set 3.3v ref
	ADC14->IER0 = ADC14_IER0_IE0;      // Enable MCTL0/MEM0 Interrupts OR EQUALS??

	while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY));
	// Wait for ref generator to settle
	ADC14->CTL0 |= ADC14_CTL0_ENC | ADC14_CTL0_SC;
	//Enable Conversions
	NVIC_EnableIRQ(ADC14_IRQn);      // Enable ADC int in NVIC module
	 */
}
/*
Configures our Clocks and sets the DCO clock to 1.5Mhz
*/
void configure_clocks(void)
{
	CS->KEY = 0x695A; 					//Unlock cs module for register access
	CS->CTL0 = 0; 						// reset tuning parameters
	CS->CTL0 |= CS_CTL0_DCORSEL_0;	     // 1.5MHz
	CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
	CS->KEY = 0;						//lock module
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
	UCA0CTLW0 & ~UCSPB;					//one stop bit
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
/*
This function calls all of our other configure functions to minimize function calling within the main
*/
void configure_All(){
	configure_Pins();
	configure_ADC();
	configure_clocks();
	configure_serial_port();
}


