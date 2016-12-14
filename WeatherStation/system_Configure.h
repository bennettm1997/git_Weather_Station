/*
 * system_Configure.h
 *
 *  Created on: Nov 24, 2016
 *      Author: Bennett
 */
#include "msp.h"
#include "core_cm4.h"

#ifndef SYSTEM_CONFIGURE_H_
#define SYSTEM_CONFIGURE_H_

/*
Configures our Clocks and sets the DCO clock to 1.5Mhz
*/
void configure_clocks(void);

/*
Configures our serial port for Bluetooth transmission
Port 1.2 and 1.3 are acting as our TXD and RXD pins. This is the EUSCI SPI
P1.2: UCA0RXD
P1.3: UCA0TXD
*/
void configure_serial_port();
/*
 * Configures remaining pins to the correct orientation.
 */
void configure_pins();

/*
 * Calls all the configure functions at once for simplicity.
 */
void configure_All();


#endif /* SYSTEM_CONFIGURE_H_ */
