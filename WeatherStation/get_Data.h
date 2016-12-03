/*
 * get_Data.h
 *
 *  Created on: Nov 24, 2016
 *      Author: Bennett
 */

#ifndef GET_DATA_H_
#define GET_DATA_H_
#include "msp.h"
#include "spi_Module.h"

uint8_t get_Temperature();
uint8_t get_Barometric_Pressure(void);
void get_All_Data_Slow(void);
void get_All_Data_Fast(void);

#endif /* GET_DATA_H_ */
