#ifndef _powerMode_h
#define _powerModeData_h
#include <stdint.h>

void low_Power(void);
void high_Power(void);
void Power_Off(void);
void Power_On(void);
void PORT1_IRQHandler(void);
void Check_Power(uint8_t BUTTON);
#endif
