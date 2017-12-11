/**
 * @file dma.h
 * @brief An abtraction of dma functions
 *
 * This header file provides the prototypes of function for
 * implementing dma for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 20 November 2017
 *
 */

#ifndef __DMA_H__
#define __DMA_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MKL25Z4.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DMA_TX_SIZE			(1)		/* Transfer size ( 1, 2 or 4 bytes) */

#ifdef DMA_TX_SIZE
#if (DMA_TX_SIZE == 1)
#define DMA_D				(1)
#elif (DMA_TX_SIZE == 2)
#define DMA_D				(2)
#elif (DMA_TX_SIZE == 4)
#define DMA_D				(0)
#endif
#endif

#define D_SIZE				(DMA_D)	/* 0 = 32-bit, 1 = 8-bit, 2 = 16-bit */
#define S_SIZE				(DMA_D) /* 0 = 32-bit, 1 = 8-bit, 2 = 16-bit */

/*******************************************************************************
 * Variables
 ******************************************************************************/

typedef enum DMA_status
{
	dma_success			=	0,		/* Successful operation */
	dma_fail			=	1,		/* FAIL!! */
	dma_null_pointer 	=	2,		/* Null pointer passed */

} DMA_status;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/**
 * @brief Configure the DMA module
 *
 * It configures the DMA module as and returns an enumeration that
 * specifies the status condition of the function call.
 *
 * @return Status condition of the DMA function
 */
DMA_status DMA_configure(void);

/**
 * @brief Moves the data from source to destination using DMA module
 *
 * Given the source and destination pointers and the length of the data,
 * it will move the data from source to destination and returns an
 * enumeration that specifies the status condition of the function call.
 *
 * @param src Pointer to the source
 * @param dst Pointer to the destination
 * @param length Size of the data block in bytes
 *
 * @return Status condition of the DMA function
 */
DMA_status memmove_dma(uint8_t * src, uint8_t * dst, size_t length);


/**
 * @brief Sets the value of the data block with the value specified
 *
 * Given the source pointer, the length of the data and the desired value,
 * it will set the specified length of data from source pointer with value
 * provided and returns an enumeration that specifies the status condition
 * of the function call.
 *
 * @param src Pointer to the source
 * @param length Size of the data block in bytes
 * @param value Value of the data to be set
 *
 * @return Status condition of the DMA function
 */
DMA_status memset_dma(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets the value of the data block with the value zero
 *
 * Given the source pointer and the length of the data,
 * it will set the specified length of data from source pointer with value
 * zero and returns an enumeration that specifies the status condition
 * of the function call.
 *
 * @param src Pointer to the source
 * @param length Size of the data block in bytes
 *
 * @return Status condition of the DMA function
 */
DMA_status memzero_dma(uint8_t * src, size_t length);

/**
 * @brief DMA0 Interrupt routine
 *
 * This routine will be executed when an DMA0 interrupt occurs.
 * After the completion of transfer, interrupt will be generated.
 *
 */
void DMA0_IRQHandler(void);



#endif	/* __DMA_H__ */
