
#include "msp.h"
#include "system_Configure.h"


void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    __enable_interrupt(); //enable global interrupts
    configure_All(); //change to configure all later
    while(1){
    uart_putchar_n("Why not run", 11);
    }
}

