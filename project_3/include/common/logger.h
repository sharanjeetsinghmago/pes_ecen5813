/*
 * logger.h
 *
 *  Created on: Dec 8, 2017
 *      Author: vipul
 */

#ifndef INCLUDES_LOGGER_H_
#define INCLUDES_LOGGER_H_


#include <stdint.h>
#include "circbuf.h"

/**
 * @brief Enumeration for the LogID of the logs
 *
 * Log IDs for different types of logs.
 *
 */
typedef enum Log_ID
{
	LOGGER_INITIALIZED,
	GPIO_INITIALIZED,
	SYSTEM_INITIALIZED,
	SYSTEM_HALTED,
	INFO,
	WARNING,
	ERROR,
	PROFILING_STARTED,
	PROFILING_RESULT,
	PROFILING_COMPLETED,
	DATA_RECEIVED,
	DATA_ANALYSIS_STARTED,
	DATA_ALPHA_COUNT,
	DATA_NUMERIC_COUNT,
	DATA_PUNCTUATION_COUNT,
	DATA_MISC_COUNT,
	DATA_ANALYSIS_COMPLETED,
	HEARTBEAT
}Log_ID;

/**
 * @brief Structure for the Log Type data structure
 *
 * Structure for various members of the Log Type data structure.
 *
 */
typedef struct Log_type
{
	Log_ID logID;
	uint32_t log_time;
	uint8_t len;
	uint8_t payload[30];
	uint8_t val;
//	uint8_t log_checksum;

} Log_type;

/**
 * @brief Log the given data to the logger buffer
 *
 * Given the pointer to the data to be logged
 * and the length of the data, it adds the elements one at a time
 * to the logger buffer.
 *
 * @param ptr Pointer to the data
 * @param len Length of the data
 */
void log_data(uint8_t * ptr, uint8_t len);

/**
 * @brief Log the given string to the logger buffer
 *
 * Given the pointer to the data to be logged,
 * it adds the elements one at a time to the logger buffer.
 *
 * @param str Pointer to the string
 */
void log_string(char * str);

/**
 * @brief Log the given integer to the logger buffer
 *
 * Given the integer to be logged it converts the integer to character
 * and adds the elements one at a time to the logger buffer.
 *
 * @param x Integer to be logged.
 */
void log_integer(uint32_t x);

/**
 * @brief Flush the logger buffer
 *
 *Flush the logger buffer by removing one element at a time
 *using UART for Freedom Board and printf() for BBB.
 */
void log_flush();

/**
* @brief Log Item to the logger buffer
*
* Given the pointer to the structure to the data and the buffer,
* it checks for the log ID and logs the elements of the structure
* to the buffer by using log_string and log_integer functions.
*
* @param data 	Pointer to the structure to be logged
* @param buffer Buffer to which the data has to be logged
*/
void log_item(Log_type * data, CB_t * buffer);


#endif /* INCLUDES_LOGGER_H_ */

