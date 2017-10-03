/**
 * @file debug.c
 * @brief The function definition for debugging/print functions
 *
 * This implementation file provides the function definition
 * for complie time switching and using print function for debugging.
 *
 * @author Vipul Gupta
 * @date 2 October 2017
 *
 */

#include "debug.h"

void print_memory(uint8_t * start, uint32_t length)
{
	/* Compile time switch: Flag VERBOSE */
#ifdef VERBOSE
	uint32_t i;
	printf("=============\n");
	for(i = 0; i < length; i++)
	{
		printf(" %x \n", *(start+i));
	}
	printf("=============\n");
#endif
}