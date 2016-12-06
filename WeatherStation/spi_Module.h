
#include "msp.h"
#include "send_Log.h"

#ifndef SPI_MODULE_H_
#define SPI_MODULE_H_
#include "msp.h"
#define ERROR -1
#define SUCCESS 0
#define HIGH 1
#define LOW 0

extern int16_t rx_data;
void slaveSelect1(int state);
void slaveSelect2(int state);
void slaveSelect3(int state);

void configure_SPI_MODULE_BAROMETER(void);
void configure_SPI_MODULE_TEMP(void);
void configure_SPI_MODULE_HUMIDITY(void);
int16_t spi_putchar(void);

#endif /* SPI_MODULE_H_ */
