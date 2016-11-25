
#include "msp.h"

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
    __enable_interrupt(); //enable global interrupts
}

