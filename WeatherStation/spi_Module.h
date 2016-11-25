/*
 * spi_Module.h
 *
 *  Created on: Nov 25, 2016
 *      Author: berkt
 */

#ifndef SPI_MODULE_H_
#define SPI_MODULE_H_
int slaveSelect1(int state);
int slaveSelect2(int state);
int slaveSelect3(int state);
int MISO();
int MOSI();
int configure_SPI_Clock();
#endif /* SPI_MODULE_H_ */
