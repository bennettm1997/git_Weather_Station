#include <stdint.h>
#include "send_Log.h"
#include "system_Configure.h"
#include "msp.h"

#ifndef _powerMode_h
#define _powerModeData_h
/*In low power mode we will decrease the ADC sampling rate to a minimum. - Change the capture compare register to a lower value, to decrease the sampling rate.
 * In High power mode we will sample at the fastest rate we can within reason.
 *
 */

uint8_t BUTTON;
/*
 * Port 1 handler called when button is low/high
 */
void PORT1_IRQHandler(void);


/*
 * We did not get this finalized. The goal was to call check power over and over again to check the state. If the button went low during said time it would hold that position(boolean true/false) until the power state changed.
 */
extern void Check_Power(uint8_t BUTTON);
#endif
