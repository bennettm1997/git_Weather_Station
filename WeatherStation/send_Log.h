/*
 * send_Log.h
 *
 *  Created on: Nov 24, 2016
 *      Author: Bennett
 */
#include <stdio.h>
#include <string.h>
#include "msp.h"
#include "system_Configure.h"

#ifndef SEND_LOG_H_
#define SEND_LOG_H_

/*
 * This function will just send a string of characters across UART-
 * We will need to add a handler for all of these logs -Python Script
 * The question mark is our logging identifier. This allows our to recognize Logging versus Data.
 * Length is the length of the string(number of characters).
 */
void sendLog(char strng[], uint16_t length);

#endif /* SEND_LOG_H_ */
