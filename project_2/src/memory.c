/**
 * @file memory.c
 * @brief The implementation file for memory manupulation functions
 *
 * This implementation file provides the function definitions for
 * various memory manupulation operations.
 *
 * @author Vipul Gupta
 * @date 29 September 2017
 *
 */


#include "../include/common/memory.h"
#include <stdint.h>


memory_status my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t i;
	if(src == NULL || dst == NULL)
		return INVALID_POINTER_EQUALS_NULL;
	else if(src < dst)
	{
		for(i = 1; i <= length; i++)
		{
			*(dst + length - i) = *(src + length - i);
		}
	}
	else
	{
		for(i = 0; i < length; i++)
		{
			*(dst+i) = *(src+i);
		}
	}
	return SUCCESS;
}

memory_status my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t i;

	if(src == NULL || dst == NULL)
		return INVALID_POINTER_EQUALS_NULL;

	for(i = 0; i < length; i++)
	{
		*(dst+i) = *(src+i);
	}
	return SUCCESS;
}

memory_status my_memset(uint8_t * src, size_t length, uint8_t value)
{
        size_t i;
	if(src == NULL )
		return INVALID_POINTER_EQUALS_NULL;
	else 
	{
		for(i = 0; i < length; i++)
		{
			*(src+i) = value;
		}
	}
	return SUCCESS;
}

memory_status my_memzero(uint8_t * src, size_t length)
{
  	size_t i;
	if(src == NULL )
		return INVALID_POINTER_EQUALS_NULL;
	
	else
	{
		for(i = 0; i < length; i++)
		{
			*(src+i) = 0x00;
		}	
	}
	return SUCCESS;
}

memory_status my_reverse(uint8_t * src, size_t length)
{
	size_t i;

	if(src == NULL)
		return INVALID_POINTER_EQUALS_NULL;
	
	
	else
	{
		/* Allocating a byte of memory for tmp variable */
		uint8_t * tmp = (uint8_t *)malloc(sizeof(uint8_t));
		
		for(i = 0; i < (length/2); i++)
		{
			*tmp = *(src + length - 1 - i);
			*(src + length - 1 - i) = *(src + i);
			*(src + i) = *tmp;
		}
		free(tmp);
		return SUCCESS;
	}
}

int32_t * reserve_words(size_t length)
{
	return (int32_t *)malloc(length);
}

void free_words(int32_t * src)
{
	free(src);
}
