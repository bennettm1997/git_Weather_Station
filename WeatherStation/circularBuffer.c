
#define FULL -1
/*
 * Parameters:
 * Length- Takes a 32 bit integer value representing the size of the FIFO.
 * *buf represents a buffer object that was instantiated.
 * Use: creates a buffer of size length. This function then allocates the necessary amount of memory.
 * Return type: Void
 *
 */
void InitializeBuffer(CircBuf * buf, uint32_t length)
{
	buf->buffer = (uint8_t*)malloc(length);
	if(buf->buffer == NULL)
	{
	  return;
	}
	buf->head = buf-> buffer;
	buf->tail = buf-> buffer;
	buf->length = length;
	buf->num_items = 0;
}
/*
 * Recursive
 * Clear buffer takes in our buffer and clears each individual element one at a time.
 */
int ClearBuffer(CircBuf * buf)
{
	if(buf->head != buf->tail)//check for when the head of the buffer is not the same as the tail. IE not empty.
	{
		uint8_t currentItem = RemoveItemFromBuffer(buf);
		return currentItem;
	}
	else
	{
		return 0;
	}
}
/*
 * This function deletes the circular buffer and frees the allocated memory.
 */
void DeleteBuffer(CircBuf * buf)
{
	free(buf);
}
/*
 * Check for when the buffer is full. If the buffer is full we will return a -1.
 */
int BufferFull(CircBuf * buf)
{
	if(buf->num_items == buf->length)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
int BufferEmpty(CircBuf * buf)
{
	if(buf->head == buf->tail)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
/*
 * This functio adds an item to the circular buffer.
 * We need to change this to take in our Packetize data struct
 */
int AddItemToBuffer(CircBuf * buf, uint8_t item)
{
	int8_t err = BufferFull(buf);
	if(err == 0)
	{
		uint8_t temp = *(buf->head);
		*(buf->head) = item;
		buf->head = buf->head + 1;
		buf->num_items ++;
	}
	else
	{
		return err;
	}
}
/*
 * This function removes removes an item from the Buffer. FIFO
 */
int RemoveItemFromBuffer(CircBuf * buf)
{
	int8_t err = BufferEmpty(buf);
	if(err == 0)
	{
		uint8_t temp = *(buf->tail);
		uint8_t tail_1 = buf->tail;
		buf->tail = buf->tail + 1;
		tail_1 = 0;
		buf->num_items --;
		return y;
	}
	else
	{
		return err;
	}
}