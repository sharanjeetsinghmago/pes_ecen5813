/**
 * @file dma.c
 * @brief The implementation file for the dma module
 *
 * This implementation file provides the function definitions for
 * implementing dma module for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 20 November 2017
 *
 */

#include "dma.h"


DMA_status DMA_configure(void)
{
	/* Clock gate enabled for DMA */
	SIM_SCGC7 |= SIM_SCGC7_DMA(1);

	/* Control Register */
	DMA_DCR0 |= (DMA_DCR_D_REQ(0) | DMA_DCR_DMOD(0) | DMA_DCR_SMOD(0) |
				 DMA_DCR_ERQ(0) | DMA_DCR_EINT(1));

	/* Enable DMA Interrupt */
	NVIC_EnableIRQ(DMA0_IRQn);

	return dma_success;

}

DMA_status memmove_dma(uint8_t * src, uint8_t * dst, size_t length)
{
	if(src == NULL | dst == NULL)
		return dma_null_pointer;
	else if (src == dst | length == 0)
		return dma_success;

	/* Data overwrite condition (memory overlap) */
	else if (((dst - src) < length) && ((dst - src) > 0))
	{
		/* Transfer data in 2 steps
		 * First transfer data with overlap issue
		 * Then remaining data */

		size_t l = src + length - dst;

		memmove_dma(dst, (dst + length - l), l);
		memmove_dma(src, dst, (length - l));

	}
	else
	{

		/* Control Register */
		DMA_DCR0 |= (DMA_DCR_DSIZE(D_SIZE) | DMA_DCR_DINC(1) |
				 	 DMA_DCR_SSIZE(S_SIZE) | DMA_DCR_SINC(1));

		/* Source address reg */
		DMA_SAR0 = DMA_SAR_SAR(src);
		/* Destination address reg */
		DMA_DAR0 = DMA_DAR_DAR(dst);

		/* Byte control register - total no of bytes to be transfered */
		DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);

		/* Start DMA */
		DMA_DCR0 |= DMA_DCR_START(1);

		return dma_success;
	}
}

DMA_status memset_dma(uint8_t * src, size_t length, uint8_t value)
{
	if(src == NULL)
		return dma_null_pointer;
	else if (length == 0)
		return dma_success;

	else
	{
		/* Control Register - Source fixed to the value provided (8bit)*/
		DMA_DCR0 |= (DMA_DCR_DSIZE(D_SIZE) | DMA_DCR_DINC(1) |
					 DMA_DCR_SSIZE(1) | DMA_DCR_SINC(0));

		/* Setting value in a memory location */
		uint8_t * val = (uint8_t *)malloc(1);
		*val = value;

		/* Source address reg */
		DMA_SAR0 = DMA_SAR_SAR(val);
		/* Destination address reg */
		DMA_DAR0 = DMA_DAR_DAR(src);

		/* Byte control register - total no of bytes to be transfered */
		DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);

		/* Start DMA */
		DMA_DCR0 |= DMA_DCR_START(1);

		return dma_success;
	}
}

DMA_status memzero_dma(uint8_t * src, size_t length)
{
	if(src == NULL)
		return dma_null_pointer;
	else if (length == 0)
		return dma_success;

	else
	{
		/* Control Register - Source fixed to the value provided (8bit)*/
		DMA_DCR0 |= (DMA_DCR_DSIZE(D_SIZE) | DMA_DCR_DINC(1) |
					 DMA_DCR_SSIZE(1) | DMA_DCR_SINC(0));

		/* Setting value in a memory location */
		uint8_t * val = (uint8_t *)malloc(1);
		*val = 0x00;

		/* Source address reg */
		DMA_SAR0 = DMA_SAR_SAR(val);
		/* Destination address reg */
		DMA_DAR0 = DMA_DAR_DAR(src);

		/* Byte control register - total no of bytes to be transfered */
		DMA_DSR_BCR0 = DMA_DSR_BCR_BCR(length);

		/* Start DMA */
		DMA_DCR0 |= DMA_DCR_START(1);

		return dma_success;
	}
}

void DMA0_IRQHandler(void)
{
	/* Interrupt when data transfer has been completed */
	if(DMA_DSR_BCR0 & DMA_DSR_BCR_DONE_MASK)
	{
		/* Clear the interrupt source */
		DMA_DSR_BCR0 |= DMA_DSR_BCR_DONE(1);

	}

}