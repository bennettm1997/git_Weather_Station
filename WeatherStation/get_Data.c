#include "get_Data.h"
#include "spi_Module.h"
#include "send_Log.h"


uint8_t iTEMP = 0;
uint8_t iHUMIDITY = 0;
uint8_t iBAROMETER = 0;

typedef enum PACKET_ITEM{
	TEMPERATURE = 5,
	BAROMETRIC_PRESSURE = 6,
	HUMIDITY = 7,
}ITEM;
/*
CHECK THE DATA SHEETS TO MAKE SURE WE ARE SENDING THE CORRECT SIGNALS, Some of the IC's pins are
active high and some are active low.
*/
/*
	Tells the temperature sensor to send temperature data
	Recieves the temperature data
	Performs math to convert its ADC value to a temperature
	Returns the temperature in the form of an integer
*/
//Wake up Slave Select for this IC; output on a pin connected to the slave select.
void get_Temperature(void){
	slaveSelect1(HIGH); //sets slave select
	sendLog("Sampling Temperature Data");
	slaveSelect1(LOW); ////sets low to tell the IC it is no longer being used.
}
/*
Wake the Barometer IC up and get a data sample. Perform the math to convert the ADC data to an integer
representation of the barometric pressure.
*/
void get_Barometric_Pressure(void){
	slaveSelect2(HIGH);//Active low chip
	sendLog("Sampling Barometric Pressure Data");

	slaveSelect2(LOW);//sets low to tell the IC it is no longer being used.

}

void get_Humidity(void){
	slaveSelect3(HIGH);
	sendLog("Sampling Humidity Data");


	slaveSelect3(LOW); //sets low to tell the IC it is no longer being used.
}

/*
 * Tell the MSP when to sample temp, pressure, etc. This will just call the get functions at the specific time intervals.
 * Creates a new timer. Use as many capture compare registers as needed. We do not need seperate instances
 * of timers, just different Capture compare values.
*/
Weather_Packet wPacket; //creates the instance of our weather packet
void get_All_Data_Fast(void){

	TA0CCTL0 |= CCIE; //Enable Capture compare interrupt

	TA0CTL |= TIMER_A_CTL_MC_1;  //up mode
	TA0CTL |= TASSEL_2; //SMCLCK
	TA0CTL |= TAIE; //Timer a interrupt enable
	//TA0CTL |= ID_2; This is the Divide by
	TA0CCR0 = 20000;
	TA0CCR1 = 40000;
	TA0CCR2 = 60000;

	int i = 0;

	while(iTEMP!= 1);
	Add_Item_To_Packet(&w_Packet, TEMPERATURE, getTemperature());
	for(i = 0; i<1000; i++);

	while(iBAROMETER != 1);
	Add_Item_To_Packet(&w_Packet, BAROMETRIC_PRESSURE, get_Barometric_Pressure());
	for(i = 0; i<1000; i++);

	while(iHUMIDITY != 1);
	Add_Item_To_Packet(&w_Packet, HUMIDITY, get_HUMIDITY());


	for(i = 0; i<1000; i++);//delay before send
	sendAPacket(&w_Packet);
	clear_Packet(&w_Packet);
}

//Tells the MSP when to sample data at specific time intervals. This will take data at slower intervals.
void get_All_Data_Slow(void){

}



void TA0_0_IRQHandler(void){//What we actually do when the interupt is enabled.
		if(TA0CCR0 & CCIFG){
			iTEMP = 1;
		}
		if(TA0CCR1 & CCIFG){
			iBAROMETER = 1;
		}
		if(TA0CCR2 & CCIFG){
			iHUMIDITY = 1;
		}
		TA0CCTL0 &=~CCIFG;
}


