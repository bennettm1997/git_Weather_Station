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


uint16_t get_Temperature(void);
uint16_t get_Barometric_Pressure(void);
uint16_t get_Humidity(void);
void get_All_Data_Slow(void);
void get_All_Data_Fast(void);
void TA0_0_IRQHandler(void);
#endif /* GET_DATA_H_ */
