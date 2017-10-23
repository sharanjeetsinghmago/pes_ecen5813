/**
 * @file circbuf.h
 * @brief An abtraction for circular buffer structure and functions 
 *
 * This header file provides the structures, enumerations and function for
 * implementing circular buffer data structure.
 *
 * @author Vipul Gupta
 * @date 17 October 2017
 *
 */

#ifndef __CIRCBUF_H__
#define __CIRCBUF_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


/**
 * @brief Structure for the circular buffer data structure
 * 
 * Structure for various members of the circular buffer data structure.
 *
 */
typedef struct CB_t
{
	uint8_t * ptr;				/* Allocated memory pointer */
	uint8_t * head;				/* Pointer to add data item */
	uint8_t * tail;				/* Pointer to remove data item */
	size_t length;		    	/* Number of items allocated to the buffer */
	size_t count;		    	/* Current item count in the buffer */

} CB_t;

/**
 * @brief Enumeration for the status conditions of circular buffer
 *
 * Status information about the circular buffer functions.
 *
 */
typedef enum CB_status
{
	success = 0,                        /* No error or Success */
    buffer_full = 1,                    /* Buffer is full */
    buffer_empty = 2,                   /* Buffer is empty */
    null_pointer = 3,                   /* Returned a null pointer */
    no_length = 4,                      /* No length returned */
    allocation_failed = 5,        		/* buffer allocation failed */
    out_of_count = 6					/* Data access greater then count */

} CB_status;


/**
 * @brief Add the data item to the circular buffer
 *
 * Given the pointer to the circular buffer and the data to added,
 * it adds the data item to the circular buffer and returns an 
 * enumeration that specifies the status condition of the function call.
 *
 * @param buff Pointer to the circular buffer
 * @param data Data to be added to the buffer
 *
 * @return Status condition of the function call
 */
CB_status CB_buffer_add_item(CB_t * buff, uint8_t data);

/**
 * @brief Remove the data item to the circular buffer
 *
 * Given the pointer to the circular buffer and the pointer to the data
 * to removed, it removes the data item to the circular buffer and returns
 * an enumeration that specifies the status condition of the function call.
 *
 * @param buff Pointer to the circular buffer
 * @param data Pointer to the variable to store the removed data
 *
 * @return Status condition of the function call
 */
CB_status CB_buffer_remove_item(CB_t * buff, uint8_t * data);

/**
 * @brief To check whether the circular buffer is full
 *
 * Given the pointer to the circular buffer to be checked, it checks
 * if the buffer is full and returns an enumeration that specifies the
 * status condition of the circular buffer or an error code.
 *
 * @param buff Pointer to the circular buffer
 *
 * @return Status condition of the circular buffer or an error code
 */
CB_status CB_is_full(CB_t * buff);

/**
 * @brief To check whether the circular buffer is empty
 *
 * Given the pointer to the circular buffer to be checked, it checks
 * if the buffer is empty and returns an enumeration that specifies the
 * status condition of the circular buffer or an error code.
 *
 * @param buff Pointer to the circular buffer
 *
 * @return Status condition of the circular buffer or an error code
 */
CB_status CB_is_empty(CB_t * buff);

/**
 * @brief To peek and store a particular data in the circular buffer
 *
 * Given the pointer to the circular buffer, position from the head of 
 * the buffer to peek into and the pointer to the data, it stores the
 * data being peeked and returns an enumeration that specifies the status
 * condition of the circular buffer or an error code.
 * Position 0 corresponds to the newest element.
 *
 * @param buff Pointer to the circular buffer
 * @param position Position from the head of the buffer to peek into 
 * @param data Pointer to the data
 *
 * @return Status condition of the circular buffer or an error code
 */
CB_status CB_peek(CB_t * buff, size_t position, uint8_t * data);

/**
 * @brief Initialize the circular buffer
 *
 * Given the pointer to the circular buffer and the length of the buffer
 * to be reserved, it initializes the circular buffer and returns an 
 * enumeration that specifies the status condition of the circular buffer.
 *
 * @param buff Pointer to the circular buffer
 * @param length Length of the buffer
 *
 * @return Status condition of the function call
 */
CB_status CB_init(CB_t * buff, size_t length);

/**
 * @brief Destroy the circular buffer
 *
 * Given the pointer to the circular buffer, it destroys the circular 
 * buffer and returns an enumeration that specifies the status condition
 * of the circular buffer.
 *
 * @param buff Pointer to the circular buffer
 *
 * @return Status condition of the function call
 */
CB_status CB_destroy(CB_t * buff);



#endif 	/* __CIRCBUF_H__ */
