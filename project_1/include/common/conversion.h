/**
* @file conversion.h
* @brief An abstraction for data manipulation functions
*
* This header file provides the prototypes of the function for
* various data manipulation operations.
*
* @author Sharanjeet Singh Mago
* @date 30 September 2017
*
*/

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

/**
* @brief Converts data from a standard integer type to ASCII string
*
* Given the data, destination pointer and the base of the data,
* it will convert the data from standard integer to ASCII string,
* store it in the pointer and return the length of converted data.
*
* @param data Number to be converted
* @param ptr Pointer to the converted string
* @param base Base of the input data
*
* @return Length of the converted data
*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
* @brief Converts the data from an ASCII string to an integer
*
* Given the pointer to the data, number of digits and the base of the data,
* it will convert the data from ASCII string to an integer and return
* the converted number.
*
* @param ptr Pointer to the string to be converted
* @param digits Number of digits
* @param base Base of the data
*
* @return Converted number
*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
* @brief Convert from big endian to little endian
*
* Given the pointer to the data and the length of the data,
* it will convert the data from big endian to little endian
* and returns error if the conversion fails.
*
* @param data Pointer to the input data
* @param length Size of the data
*
* @return Error if conversion fails
*/
int8_t big_to_little32(uint32_t * data, uint32_t length);

/**
* @brief Convert from little endian to big endian
*
* Given the pointer to the data and the length of the data,
* it will convert the data from little endian to big endian
* and returns error if the conversion fails.
*
* @param data Pointer to the input data
* @param length Size of the data
*
* @return Error if conversion fails
*/
int8_t little_to_big32(uint32_t * data, uint32_t length);


#endif /* __MEMORY_H__ */
