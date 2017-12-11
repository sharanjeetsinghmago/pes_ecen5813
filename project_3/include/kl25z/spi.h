/**
 * @file spi.h
 * @brief An abtraction of spi module functions
 *
 * This header file provides the prototypes of function for
 * implementing spi for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 29 November 2017
 *
 */

#ifndef __SPI_H__
#define __SPI_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MKL25Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define NOP_CMD			(0xFF)		/* No operation command */

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/**
 * @brief Configure and initialize the SPI module
 *
 * It configures and initializes the SPI module.
 *
 */
void SPI_init();

/**
 * @brief Read a byte from the SPI0 module
 *
 * It reads a data byte from the SPI0 data register after the command
 * has been written and returns it.
 *
 * @return Data byte read
 */
uint8_t SPI_read_byte(void);

/**
 * @brief Write a byte to the SPI0 module
 *
 * It writes a data byte to the SPI0 data register and returns
 * the response byte sent on the SPI module
 *
 * @return Response data byte
 */
uint8_t SPI_write_byte(uint8_t byte);

/**
 * @brief Send multiple data bytes to the SPI0 module
 *
 * Given a pointer to the data bytes and the length, it writes multiple
 * bytes to the SPI0 data register.
 * the response byte sent on the SPI module
 *
 * @return void
 */
void SPI_send_packet(uint8_t * p, size_t length);

/**
 * @brief Blocks until receive buffer has received some data
 *
 * It blocks the program flow until the receive buffer has received
 * the data.
 *
 * @return void
 */
void SPI_flush(void);

#endif	/* __SPI_H__ */
