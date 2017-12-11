/**
 * @file gpio.h
 * @brief An abtraction of gpio module functions
 *
 * This header file provides the prototypes of function for
 * implementing gpio for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 29 November 2017
 *
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MKL25Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define CHIP_ENA			(1 << 5)	/* Chip Enable */
#define CHIP_SEL			(1 << 0)	/* Chip Select */

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/**
 * @brief Configure and initialize the GPIO module
 *
 * It configures and initializes the GPIO module.
 *
 */
void GPIO_nrf_init();


#endif	/* __GPIO_H__ */
