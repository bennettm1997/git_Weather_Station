

#ifndef SPI_MODULE_H_
#define SPI_MODULE_H_
#include "msp.h"


int slaveSelect1(int state);
int slaveSelect2(int state);
int slaveSelect3(int state);
int MISO(void);
int MOSI(void);
int configure_SPI_Clock(void);
void SPI_MODULE_IRQ_HANDLER(void);
#endif /* SPI_MODULE_H_ */
