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

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t i;
	if(src == dst)
		return dst;
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
}

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t i;

	if(src == dst)
		return dst;
	for(i = 0; i < length; i++)
	{
		*(dst+i) = *(src+i);
	}
	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	size_t i;
	for(i = 0; i < length; i++)
	{
		*(src+i) = value;
	}
	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	size_t i;
	for(i = 0; i < length; i++)
	{
		*(src+i) = 0x00;
	}
	return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
	size_t i;

	/* Allocating a byte of memory for tmp variable */
	uint8_t * tmp = (uint8_t *)malloc(sizeof(uint8_t));
	
	for(i = 0; i < (length/2); i++)
	{
		*tmp = *(src + length - 1 - i);
		*(src + length - 1 - i) = *(src + i);
		*(src + i) = *tmp;
	}
	free(tmp);
	return src;
}

int32_t * reserve_words(size_t length)
{
	return (int32_t *)malloc(length);
}

void free_words(int32_t * src)
{
	free(src);
}