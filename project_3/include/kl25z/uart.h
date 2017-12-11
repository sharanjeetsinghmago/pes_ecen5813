/**
 * @file uart.h
 * @brief An abtraction uart driver functions
 *
 * This header file provides the prototypes of function for
 * implementing uart driver for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 24 October 2017
 *
 */

#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MKL25Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define BAUD_RATE			(115200)	/* Baud Rate (115200, 57600, 38400) */
#define BAUD_CLOCK			(48000000)	/* System Clock 48 Mhz */
#define OSR					(15)		/* Over sampling Rate 16x default */



/*******************************************************************************
 * Variables
 ******************************************************************************/

typedef enum uart_t
{
	uart_success = 0,		/* Success */
	uart_null_pointer = 1,	/* Null pointer returned */
	uart_no_length = 2,		/* No length parameter */
	uart_config_fail = 3,	/* Configuration failed */

} UART_status;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/**
 * @brief Configure the UART as per the decided BAUD rate
 *
 * It configures the UART module as per the decided BAUD rate and
 * returns an enumeration that specifies the status condition of
 * the function call.
 *
 * @return Status condition of the UART function
 */
UART_status UART_configure(void);

/**
 * @brief Send the data byte on UART device
 *
 * Given the pointer to the data item to send, it sends the data byte
 * on a specific UART device and returns an enumeration that specifies
 * the status condition of the function call.
 *
 * @param data Pointer to the data
 *
 * @return Status condition of the UART function
 */
UART_status UART_send(uint8_t * data);

/**
 * @brief Send a block of data on UART device
 *
 * Given the pointer to a contiguous block of data items to send, it sends
 * the block of data on a specific UART device and returns an enumeration
 * that specifies the status condition of the function call.
 *
 * @param data Pointer to the block of data
 * @param length Length of the data block
 *
 * @return Status condition of the UART function
 */
UART_status UART_send_n(uint8_t * data, size_t length);

/**
 * @brief Receive the data byte on UART device
 *
 * Given the pointer to the data item to receive, it receives the data byte
 * on a specific UART device and returns an enumeration that specifies
 * the status condition of the function call.
 *
 * @param data Pointer to the data
 *
 * @return Status condition of the UART function
 */
UART_status UART_receive(uint8_t * data);

/**
 * @brief Receive a block of data on UART device
 *
 * Given the pointer to a contiguous block of data items to receive,
 * it receives the block of data on a specific UART device and
 * returns an enumeration that specifies the status condition of
 * the function call.
 *
 * @param data Pointer to the block of data
 * @param length Length of the data block
 *
 * @return Status condition of the UART function
 */
UART_status UART_receive_n(uint8_t * data, size_t length);

/**
 * @brief UART0 Interrupt routine
 *
 * This routine will be executed when an UART0 interrupt occurs.
 *
 */
void UART0_IRQHandler(void);


#endif 	/* __CIRCBUF_H__ */
