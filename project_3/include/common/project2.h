/**
 * @file project2.h
 * @brief Prototype functions to drive the project2
 *
 * This header file contains prototype functions to drive
 * the uart functionality using circular buffer.
 *
 * @author Vipul Gupta
 * @date 27 October 2017
 *
 */

#ifndef __PROJECT2_H__
#define __PROJECT2_H__

#include "uart.h"
#include "circbuf.h"
#include "conversion.h"
#include "stdint.h"
#include <stdbool.h>

/**
 * @brief Driver function for the project
 *
 * It initializes the UART and Circular buffer and a loop to
 * drive the microcontroller.
 *
 */
void project2(void);

/**
 * @brief Processes the data and updates the count of elements
 *
 * It processes the data every 20 elements and updates the count
 * and the table to printed in the TX circular buffer.
 *
 */
void dump_statistics(void);


#endif	/* __PROJECT2_H__ */
