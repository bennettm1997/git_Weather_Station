#include "msp.h"
#include "send_Log.h"

#ifndef SPI_MODULE_H_
#define SPI_MODULE_H_
#define ERROR -1
#define SUCCESS 0
#define HIGH 1
#define LOW 0

<<<<<<< HEAD
int16_t rx_data;//rx buffer data.

/*
 * Sets slave select1 pin to high/low depending on what state is. State = 1 Pin 6.0 is high. State = 0 Pin 6.0 is low
 */
void slaveSelect1(int state);

/*
 * Sets slave select2 pin to high/low depending on what state is. State = 1 Pin 3.2 is high. State = 0 Pin 3.2 is low
 */
=======
int16_t rx_data;
void slaveSelect1(void);
>>>>>>> refs/remotes/origin/master
void slaveSelect2(int state);

/*
 * Sets slave select3 pin to high/low depending on what state is. State = 1 Pin 3.3 is high. State = 0 Pin 3.3 is low
 */
void slaveSelect3(int state);


/*
 * Sets up the SPI module for the barometer IC.
 */
void configure_SPI_MODULE_BAROMETER(void);

/*
 * Sets up the SPI module for the Temp IC.
 */
void configure_SPI_MODULE_TEMP(void);
/*
 * Sets up the SPI module for the humidity IC.
 */
void configure_SPI_MODULE_HUMIDITY(void);
<<<<<<< HEAD

/*
 * Putchar - not a good name. Recieve the data.
 */
int16_t spi_putchar(void);
=======
//extern void EUSCIB0_IRQHandler(void);
>>>>>>> refs/remotes/origin/master

#endif /* SPI_MODULE_H_ */
