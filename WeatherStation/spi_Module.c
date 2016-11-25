#include "spi_Module.h"
#define ERROR -1
#define SUCCESS 0
#define HIGH 1
#define LOW 0


//pin 6.0 state 1 for high 0 for low
int slaveSelect1(int state){
	P6DIR |= BIT0;
	if(state == HIGH){
		P6OUT |= BIT0;
	}
	else if(state == LOW){
		P6OUT &= ~BIT0;
	}
}

//pin 3.2 state 1 for high 0 for low
int slaveSelect2(int state){
	P3DIR |= BIT2;
	if(state == HIGH){
		P3OUT |= BIT2;
	}
	else if(state == LOW){
		P3OUT &= ~BIT2;
	}
}

//pin 3.3 state 1 for high 0 for low
int slaveSelect3(int state){
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
int MISO(){
	P4OUT &= ~BIT1; //set to input
	
	//This is the input data
	//You will have to figure out how the data is sent across the IC's and what they mean. LSB first or MSB..
	
	
	
	
}
int MOSI(){

}
int configure_SPI_Clock(){
//oscillate the SPI CLOCK PIN at the frequency that is decided upon (1kHZ)
//create a new timer at 1khz
//add the timer interrupt handler -- this will actually flip the pin
}


