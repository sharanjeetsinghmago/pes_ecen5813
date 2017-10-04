/**
 * @file debug.h
 * @brief An abtraction for debugging/print functions
 *
 * This header file provides the prototype for complie time
 * switching and using print function for debugging.
 *
 * @author Vipul Gupta
 * @date 2 October 2017
 *
 */

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdint.h>
#include <stdio.h>

/**
 * @brief Prints the hex output of the bytes
 *
 * Given a pointer to a memory location and the length of bytes,
 * it will print the hex output of bytes when VERBOSE flag is enabled.
 *
 * @param start Pointer to the memory
 * @param length Length of bytes
 *
 */
void print_memory(uint8_t * start, uint32_t length);

#endif /* __DEBUG_H__ */
