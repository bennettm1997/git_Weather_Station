#include "get_Data.h"
#include "spi_Module.h"
#include "send_Log.h"
/*
CHECK THE DATA SHEETS TO MAKE SURE WE ARE SENDING THE CORRECT SIGNALS, Some of the IC's pins are
active high and some are active low.
*/
	slaveSelect1(1); //sets slave select pin to high
	slaveSelect2(1);
	slaveSelect3(1);
/*
	Tells the temperature sensor to send temperature data
	Recieves the temperature data
	Performs math to convert its ADC value to a temperature
	Returns the temperature in the form of an integer
*/
//Wake up Slave Select for this IC; output on a pin connected to the slave select.
void get_Temperature(){
	sendLog("Sampling Temperature Data");
	slaveSelect1(0); //sets slave select pin to low
	MISO();
	slaveSelect1(1);
}
/*
Wake the Barometer IC up and get a data sample. Perform the math to convert the ADC data to an integer
representation of the barometric pressure.
*/ 
void get_Barometric_Pressure(void){
	sendLog("Sampling Barometric Pressure Data");
	slaveSelect2(0); //sets slave select pin to low
	MISO();
	slaveSelect2(1);

}

void get_Humidity(){
	sendLog("Sampling humidity Data");
		slaveSelect2(0); //sets slave select pin to low
		MISO();
		slaveSelect2(1);

}

/*
 * Tell the MSP when to sample temp, pressure, etc. This will just call the get functions at the specific time intervals.
 * Creates a new timer. Use as many capture compare registers as needed. We do not need seperate instances
 * of timers, just different Capture compare values.
*/
void get_All_Data_Fast(void){

}

//Tells the MSP when to sample data at specific time intervals. This will take data at slower intervals.
void get_All_Data_Slow(void){

}

