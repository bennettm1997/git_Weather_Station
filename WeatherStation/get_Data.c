#include "get_Data.h"

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
int get_Temperature(){
	//Wake up Slave Select for this IC; output on a pin connected to the slave select.

	return 10;//change to temp and add return -1 for error
}
/*
Wake the Barometer IC up and get a data sample. Perform the math to convert the ADC data to an integer
representation of the barometric pressure.
*/ 
int get_Barometric_Pressure(void){


}
//Tell the MSP when to sample temp, pressure, etc. This will just call the get functions at the
//specific time intervals.
int get_All_Data_Fast(void){
//creates a new timer. Use as many capture compare registers as needed. We do not need seperate instances
	//of timers, just different Capture compare values.

}

//Tells the MSP when to sample data at specific time intervals. This will take data at slower intervals.
int get_All_Data_Slow(void){

}

