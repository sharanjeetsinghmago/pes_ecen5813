/**
 * @file memory.h
 * @brief An abtraction for memory manupulation functions
 *
 * This header file provides the prototypes of the function for
 * various memory manupulation operations.
 *
 * @author Vipul Gupta
 * @date 29 September 2017
 *
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>

/**
 * @brief Moves the data from source to destination
 *
 * Given the source and destination pointers and the length of the data,
 * it will move the data from source to destination and return the 
 * pointer to the destination.
 *
 * @param src Pointer to the source
 * @param dst Pointer to the destination
 * @param length Size of the data in bytes
 *
 * @return Pointer to the destination
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies the data from source to destination
 *
 * Given the source and destination pointers and the length of the data,
 * it will copy the data from source to destination and return the 
 * pointer to the destination.
 *
 * @param src Pointer to the source
 * @param dst Pointer to the destination
 * @param length Size of the data in bytes
 *
 * @return Pointer to the destination
 */
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets the value of the data 
 *
 * Given the source pointer, the length of the data and the desired value,
 * it will set the specified length of data from source pointer with value 
 * provided and return the pointer to the source.
 *
 * @param src Pointer to the source
 * @param length Size of the data in bytes
 * @param value Value of the data to be set
 *
 * @return Pointer to the source
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets the value of the data as zero
 *
 * Given the source pointer and the length of the data, it will set the 
 * specified length of data from source pointer with value zero and 
 * return the pointer to the source.
 *
 * @param src Pointer to the source
 * @param length Size of the data in bytes
 *
 * @return Pointer to the source
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the order of all the bytes
 *
 * Given the source pointer and the length of the data, it will reverse the 
 * order of all the bytes starting from source and return the pointer to 
 * the source.
 *
 * @param src Pointer to the source
 * @param length Size of the data in bytes
 *
 * @return Pointer to the source
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocate data in dynamic memory
 *
 * Given the length of the data, it will allocate the specified length
 * of data in dynamic memory and return a pointer to the allocation is
 * successful or a NULL pointer if not successful.
 *
 * @param length Size of the data in bytes
 *
 * @return Pointer to the allocation (success) or a NULL pointer (failure)
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Deallocate or free a dynamic memory allocation
 *
 * Given the source pointer, it will deallocate the memory or free
 * a dynamic memory allocation.
 *
 * @param src Pointer to the source
 *
 * @return Void
 */
void free_words(int32_t * src);


#endif /* __MEMORY_H__ */