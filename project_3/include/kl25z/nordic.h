/**
 * @file nordic.h
 * @brief An abtraction of nordic functions
 *
 * This header file provides the prototypes of function for
 * implementing nordic driver for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 3 Decemeber 2017
 *
 */

#ifndef __NORDIC_H_
#define __NORDIC_H_

#include "spi.h"
#include "gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* SPI Commands */
#define READ_CMD	(0x00)
#define WRITE_CMD	(0x20)
#define FLUSH_TX	(0xE1)
#define FLUSH_RX	(0xE2)
#define NOP			(0xFF)		/* No operation */

/* Register map */
#define CONFIG_REG	(0x00)
#define RF_CH_REG	(0x05)
#define RF_SETP_REG	(0x06)
#define STATUS_REG	(0x07)
#define TX_ADDR		(0x10)
#define FIFO_STATUS	(0x17)

#define NRF_CHIP_ENABLE()	(GPIOD_PSOR |= GPIO_PSOR_PTSO(CHIP_ENA))
#define	NRF_CHIP_DISABLE()	(GPIOD_PCOR |= GPIO_PCOR_PTCO(CHIP_ENA))
#define NRF_CHIP_SEL_ON()	(GPIOD_PCOR |= GPIO_PCOR_PTCO(CHIP_SEL))
#define NRF_CHIP_SEL_OFF()	(GPIOD_PSOR |= GPIO_PSOR_PTSO(CHIP_SEL))

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/**
 * @brief Read the register and return the value
 *
 * Given the register address, it reads it and returns the value.
 *
 * @param reg Register address
 *
 * @return Value of the register
 */
uint8_t nrf_read_register(uint8_t reg);

/**
 * @brief Write to the register with the given value
 *
 * Given the register address and the value, it writes to it.
 *
 * @param reg Register address
 * @param value Value to be written
 *
 */
void nrf_write_register(uint8_t reg, uint8_t value);

/**
 * @brief Read the status register and return the value
 *
 * It reads the status register and returns the value.
 *
 * @return Value of the status register
 */
uint8_t nrf_read_status(void);

/**
 * @brief Write to the config register with the given value
 *
 * Given the configuration value, it writes to the config register.
 *
 * @param value Configuration value to be written
 *
 */
void nrf_write_config(uint8_t config);

/**
 * @brief Read the config register and return the value
 *
 * It reads the config register and returns the value.
 *
 * @return Value of the config register
 */
uint8_t nrf_read_config(void);

/**
 * @brief Read the RF setup register and return the value
 *
 * It reads the RF setup register and returns the value.
 *
 * @return Value of the RF setup register
 */
uint8_t nrf_read_rf_setup(void);

/**
 * @brief Write to the RF setup register with the given value
 *
 * Given the configuration value, it writes to the RF setup register.
 *
 * @param value Configuration value to be written
 *
 */
void nrf_write_rf_setup(uint8_t config);

/**
 * @brief Read the RF channel register and return the value
 *
 * It reads the RF channel register and returns the value.
 *
 * @return Value of the RF channel register
 */
uint8_t nrf_read_rf_ch(void);

/**
 * @brief Write to the RF channel register with the given value
 *
 * Given the configuration value, it writes to the RF channel register.
 *
 * @param channel Channel frequency value to be written
 *
 */
void nrf_write_rf_ch(uint8_t channel);

/**
 * @brief Read the Tx Address
 *
 * Given the pointer to the Tx Address variable, it reads the Tx address
 * and updates it.
 *
 * @param tx_addr Pointer to the Tx address variable
 *
 */
void nrf_read_TX_ADDR(uint8_t * tx_addr);

/**
 * @brief Write the Tx Address to the device
 *
 * Given the pointer to the Tx Address variable, it writes the Tx address
 * from device and updates it.
 *
 * @param tx_addr Pointer to the Tx address variable
 *
 */
void nrf_write_TX_ADDR(uint8_t * tx_addr);

/**
 * @brief Read the FIFO status register
 *
 * It reads the FIFO status register and returns the value.
 *
 * @return Value of the FIFO status register
 */
uint8_t nrf_read_fifo_status(void);

/**
 * @brief Send the Flush Tx command
 *
 * It send the Flush Tx command to the device.
 *
 */
void nrf_flush_tx_fifo(void);

/**
 * @brief Send the Flush Rx command
 *
 * It send the Flush Rx command to the device.
 *
 */
void nrf_flush_rx_fifo(void);


#endif /* __NORDIC_H_ */
