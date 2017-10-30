/**
 * @file circbuf.c
 * @brief The implementation file for circular buffer data structure
 *
 * This implementation file provides the function definitions for
 * implememting and using circular buffer.
 *
 * @author Vipul Gupta
 * @date 17 October 2017
 *
 */


#include "../include/common/circbuf.h"


CB_status CB_buffer_add_item(CB_t * buff, uint8_t data)
{
	if(buff == NULL)
		return null_pointer;
	/* If head is one less than tail => buffer full */
	else if (buff->count == buff->length)
		return buffer_full;
	else
	{
		/* add data item */
		(*(buff->head)) = data;
		/* increment head */
		/* if head is wrapping up => make it point to the base */
		if(((buff->head) + 1) == ((buff->ptr) + buff->length))
			buff->head = buff->ptr;
		else
			(buff->head) += 1;
		/* update count */
		buff->count += 1;

		return success;
	}
}

CB_status CB_buffer_remove_item(CB_t * buff, uint8_t * data)
{
	if(buff == NULL)
		return null_pointer;
	/* If head = tail => buffer empty */
	else if (buff->count == 0)
		return buffer_empty;
	else
	{
		/* remove and store the data item to the variable */
		*data = *(buff->tail);
		/* increment tail */
		/* if tail is wrapping up => make it point to the base */
		if(((buff->tail) + 1) == ((buff->ptr) + buff->length))
			buff->tail = buff->ptr;
		else
			(buff->tail) += 1;
		/* update count */
		buff->count -= 1;

		return success;
	}
}

CB_status CB_is_full(CB_t * buff)
{
	if(buff == NULL)
		return null_pointer;
	/* If head is one less than tail => buffer full */
	else if (buff->count == buff->length)
		return buffer_full;
	else
		return success;
}

CB_status CB_is_empty(CB_t * buff)
{
	if(buff == NULL)
		return null_pointer;
	/* If head = tail => buffer empty */
	else if (buff->count == 0)
		return buffer_empty;
	else
		return success;
}

CB_status CB_peek(CB_t * buff, size_t position, uint8_t * data)
{
	if(buff == NULL)
		return null_pointer;
	else if(buff->count == 0)
		return buffer_empty;
	else if(position >= buff->count)
		return out_of_count;
	else
	{
		/* Head is above the tail (Not wrapped around) */
		if(((buff->head) - (buff->tail)) > 0)
		{
			*data = *((buff->head - position - 1));
			return success;
		}

		else /* Head is below or equal to tail (Wrapped around) */
		{
			if((buff->head - position - 1) >= buff->ptr)
				*data = *(buff->head - position - 1);
			else
				*data = *(buff->length + buff->head - position - 1);
			return success;
		}
	}
}

CB_status CB_init(CB_t * buff, size_t length)
{
	/* Allocating length bytes for the buffer */
	buff->ptr = (uint8_t *)malloc(length * (sizeof(uint8_t)));
	if(buff->ptr == NULL)
		return allocation_failed;
	// Check for no length returned
	else
	{
		/* Initialize all the members with no data element in buffer */
		buff->length = length;
		buff->head = buff->ptr;
		buff->tail = buff->ptr;
		buff->count = 0;
		return success;
	}
}

CB_status CB_destroy(CB_t * buff)
{
	free(buff->ptr);
	return success;
}
