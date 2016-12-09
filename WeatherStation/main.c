
#include "msp.h"
#include "system_Configure.h"
#include "packetizeData.h"
#include "send_Log.h"
#include "powerMode.h"
#include "spi_Module.h"
#include "send_Log.h"
#include "get_Data.h"
void main(void)
{

    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    __enable_interrupt(); //enable global interrupts
    configure_All(); //change to configure all later
    configure_SPI_MODULE_TEMP();
    /*
    slaveSelect1(1);
    slaveSelect2(1);
    slaveSelect3(1);
    */
    get_All_Data_Fast();
}
