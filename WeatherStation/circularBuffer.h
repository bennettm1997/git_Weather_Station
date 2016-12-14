#include <stdint.h>
#include "msp.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef _circularBuffer_h
#define _circularBuffer_h

typedef struct CircBuf_t{
	volatile uint16_t * head; // Pointer to first item
	volatile uint16_t * tail; // Pointer to last item
	volatile uint32_t num_items; // Number of items in buffer
	volatile uint32_t length; // Max number of items the buffer can hold
	uint16_t * buffer; // Pointer to beginning of buffer in heap
	} CircBuf;



/*
	 * Parameters:
	 * Length- Takes a 32 bit integer value representing the size of the FIFO.
	 * *buf represents a buffer object that was instantiated.
	 * Use: creates a buffer of size length. This function then allocates the necessary amount of memory.
	 * Return type: Void
	 *
	 */
void InitializeBuffer(CircBuf * buf, uint32_t length);

/*
 * Recursive
 * Clear buffer takes in our buffer and clears each individual element one at a time.
 */
uint32_t ClearBuffer(CircBuf * buf);

/*
 * This function deletes the circular buffer and frees the allocated memory.
 */
void DeleteBuffer(CircBuf * buf);

/*
 * Check for when the buffer is full. If the buffer is full we will return a -1.
 */

uint32_t BufferFull(CircBuf * buf);


uint32_t BufferEmpty(CircBuf * buf);
/*
 * This function adds an item to the circular buffer.
 * We need to change this to take in our Packetize data struct
 */

uint32_t AddItemToBuffer(CircBuf * buf, uint16_t item);

uint32_t RemoveItemFromBuffer(CircBuf * buf);

#endif
