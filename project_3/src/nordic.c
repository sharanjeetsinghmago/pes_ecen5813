/**
 * @file nordic.c
 * @brief The implementation file for the nordic driver functions
 *
 * This implementation file provides the function definitions for
 * implementing nordic driver for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 3 December 2017
 *
 */

#include "nordic.h"


uint8_t nrf_read_register(uint8_t reg)
{
	NRF_CHIP_ENABLE();
	NRF_CHIP_SEL_ON();

	uint8_t cmd = ((reg) | READ_CMD);

	SPI_write_byte(cmd);

	uint8_t r_data = 0;
	r_data = SPI_read_byte();

	NRF_CHIP_SEL_OFF();
	NRF_CHIP_DISABLE();

	return r_data;
}

void nrf_write_register(uint8_t reg, uint8_t value)
{
	NRF_CHIP_ENABLE();
	NRF_CHIP_SEL_ON();

	uint8_t cmd = ((reg) | WRITE_CMD);

	SPI_write_byte(cmd);

	SPI_write_byte(value);

	NRF_CHIP_SEL_OFF();
	NRF_CHIP_DISABLE();

}

uint8_t nrf_read_status()
{
	return nrf_read_register(STATUS_REG);
}

void nrf_write_config(uint8_t config)
{
	nrf_write_register(CONFIG_REG, config);
}

uint8_t nrf_read_config()
{
	return nrf_read_register(CONFIG_REG);
}

uint8_t nrf_read_rf_setup()
{
	return nrf_read_register(RF_SETP_REG);
}

void nrf_write_rf_setup(uint8_t config)
{
	nrf_write_register(RF_SETP_REG, config);
}

uint8_t nrf_read_rf_ch()
{
	return nrf_read_register(RF_CH_REG);
}

void nrf_write_rf_ch(uint8_t channel)
{
	nrf_write_register(RF_CH_REG, channel);
}

void nrf_read_TX_ADDR(uint8_t * tx_addr)
{
	NRF_CHIP_ENABLE();
	NRF_CHIP_SEL_ON();

	uint8_t i;
	uint8_t cmd = ((TX_ADDR) | READ_CMD);

	SPI_write_byte(cmd);

	for(i = 0; i < 5; i++)
	{
		*(tx_addr + i) = SPI_read_byte();
	}

	NRF_CHIP_SEL_OFF();
	NRF_CHIP_DISABLE();
}

void nrf_write_TX_ADDR(uint8_t * tx_addr)
{
	NRF_CHIP_ENABLE();
	NRF_CHIP_SEL_ON();

	uint8_t i;
	uint8_t cmd = ((TX_ADDR) | WRITE_CMD);

	SPI_write_byte(cmd);

	for(i = 0; i < 5; i++)
	{
		SPI_write_byte(*(tx_addr + i));
	}

	NRF_CHIP_SEL_OFF();
	NRF_CHIP_DISABLE();

}

uint8_t nrf_read_fifo_status(void)
{
	return nrf_read_register(FIFO_STATUS);
}

void nrf_flush_tx_fifo(void)
{
	NRF_CHIP_ENABLE();
	NRF_CHIP_SEL_ON();

	SPI_write_byte(FLUSH_TX);

	NRF_CHIP_SEL_OFF();
	NRF_CHIP_DISABLE();
}

void nrf_flush_rx_fifo(void)
{
	NRF_CHIP_ENABLE();
	NRF_CHIP_SEL_ON();

	SPI_write_byte(FLUSH_RX);

	NRF_CHIP_SEL_OFF();
	NRF_CHIP_DISABLE();
}

