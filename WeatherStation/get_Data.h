/*
 * get_Data.h
 *
 *  Created on: Nov 24, 2016
 *      Author: Bennett
 */
#include "msp.h"
#include "spi_Module.h"
#include "send_Log.h"
#include "packetizeData.h"
#ifndef GET_DATA_H_
#define GET_DATA_H_


/*
	Tells the temperature sensor to send temperature data
	Recieves the temperature data
	Performs math to convert its ADC value to a temperature
	Returns the temperature in the form of an integer
*/
//Wake up Slave Select for this IC; output on a pin connected to the slave select.
int16_t get_Temperature(void);



/*
Wake the Barometer IC up and get a data sample. Perform the math to convert the ADC data to an integer
representation of the barometric pressure.
*/
uint16_t get_Barometric_Pressure(void);


/*
Wake the Barometer IC up and get a data sample. Perform the math to convert the ADC data to an integer
representation of the barometric pressure.
*/
uint16_t get_Humidity(void);

/*
 * Tells the MSP when to sample data at specific time intervals. This will take data at slower intervals.
 * Sets up the TA0 timer at a slow rate.
 */
void get_All_Data_Slow(void);

/*
 * Tells the MSP when to sample data at specific time intervals. This will take data at faster intervals.
 * Sets up the TA0 timer at a fast rate.
 */
void get_All_Data_Fast(void);
/*
 * Handler for the TA0 Handler. Gets called when the TA0CTL Gets called.
 */
void TA0_0_IRQHandler(void);
#endif /* GET_DATA_H_ */
