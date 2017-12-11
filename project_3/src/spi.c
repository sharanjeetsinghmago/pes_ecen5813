/**
 * @file spi.c
 * @brief The implementation file for the spi module
 *
 * This implementation file provides the function definitions for
 * implementing spi module for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 29 November 2017
 *
 */

#include "spi.h"

void SPI_init(void)
{
	/* Enable Clock to SPI  */
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;

	/* Control Reg | MSB first | Master Mode */
	SPI0_C1 = (SPI_C1_SPE_MASK | SPI_C1_MSTR_MASK | SPI_C1_CPHA(0));

	/* Baud Rate divisor - 512 | Buad rate prescaler - 4 | SPI Baud Rate: 20.48kHz */
	SPI0_BR |= (SPI_BR_SPR(0x08) | SPI_BR_SPPR(0x03));

}

uint8_t SPI_read_byte(void)
{
	/* Wait for Tx buffer to get empty */
	while(!(SPI0_S & SPI_S_SPTEF_MASK));

	SPI0_D = NOP_CMD;

	SPI_flush();

	uint8_t rd = 0;

	/* Return from buffer */
	rd = SPI0_D;

	return rd;

}

uint8_t SPI_write_byte(uint8_t byte)
{
	/* Wait for Tx buffer to get empty */
	while(!(SPI0_S & SPI_S_SPTEF_MASK));

	/* Write data to reg */
	SPI0_D = byte;

	SPI_flush();

	uint8_t rd = 0;

	/* Read from buffer */
	rd = SPI0_D;

	return rd;
}

void SPI_send_packet(uint8_t * p, size_t length)
{
	for(int i = 0; i < length; i++)
	{
		while(!(SPI0_S & SPI_S_SPTEF_MASK));

		/* Write data to reg */
		SPI0_D = *(p+i);

	}
}

void SPI_flush(void)
{
	/* Wait for buffer to get data from MISO */
	while(!(SPI0_S & SPI_S_SPRF_MASK));
}

