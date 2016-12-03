#ifndef _circularBuffer_h
#define _circularBuffer_h
#include <stdint.h>
typedef struct CircBuf_t{
	volatile uint16_t * head; // Pointer to first item
	volatile uint16_t * tail; // Pointer to last item
	volatile uint32_t num_items; // Number of items in buffer
	volatile uint32_t length; // Max number of items the buffer can hold
	uint16_t * buffer; // Pointer to beginning of buffer in heap
	} CircBuf;

void InitializeBuffer(CircBuf * buf, uint32_t length);

uint32_t ClearBuffer(CircBuf * buf);

void DeleteBuffer(CircBuf * buf);

uint32_t BufferFull(CircBuf * buf);

void PrintBuf(CircBuf *buf);

uint32_t BufferEmpty(CircBuf * buf);

uint32_t AddItemToBuffer(CircBuf * buf, uint16_t item);

uint32_t RemoveItemFromBuffer(CircBuf * buf);

#endif
