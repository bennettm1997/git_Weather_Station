#include "spi_Module.h"
#define ERROR -1
#define SUCCESS 0
#define HIGH 1
#define LOW 0


//pin 6.0 state 1 for high 0 for low
int slaveSelect1(int state){
	P6DIR |= BIT0;
	if(state = HIGH){
		P6OUT |= BIT0;
	}
	else if(state = LOW){
		P6OUT &= ~BIT0;
	}
}

//pin 3.2 state 1 for high 0 for low
int slaveSelect2(int state){
	P3DIR |= BIT2;
	if(state = HIGH){
		P3OUT |= BIT2;
	}
	else if(state = LOW){
		P3OUT &= ~BIT2;
	}
}

//pin 3.3 state 1 for high 0 for low
int slaveSelect3(int state){
	P3DIR |= BIT3;
	if(state = HIGH){
		P3OUT |= BIT3;
	}
	else if(state = LOW){
		P3OUT &= ~BIT3;
	}
}

int MISO(){

}
int MOSI(){

}
int configure_SPI_Clock(){

}

