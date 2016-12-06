#ifndef _powerMode_h
#define _powerModeData_h
#include <stdint.h>
#include "send_Log.h"
#include "system_Configure.h"
#include "msp.h"

void low_Power(void);
void high_Power(void);
void Power_Off(void);
void PORT1_IRQHandler(void);
void PORT4_IRQHandler(void);
void TA1_IRQHandler(void);
void TA2_IRQHandler(void);
void Check_Power(uint8_t BUTTON);
#endif
