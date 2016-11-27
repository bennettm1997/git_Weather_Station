/*
 * spi_Module.h
 *
 *  Created on: Nov 24, 2016
 *      Author: Bennett
 */

#ifndef SPI_MODULE_H_
#define SPI_MODULE_H_
#include "msp.h"


int slaveSelect1(int state);
int slaveSelect2(int state);
int slaveSelect3(int state);
int MISO();
int MOSI();
int configure_SPI_Clock();
void SPI_MODULE_IRQ_HANDLER(void);

#endif /* SPI_MODULE_H_ */
