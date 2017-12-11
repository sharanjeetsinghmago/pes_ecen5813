/**
 * @file uart.c
 * @brief The implementation file for the uart driver
 *
 * This implementation file provides the function definitions for
 * implementing uart driver for the KL25Z platform.
 *
 * @author Vipul Gupta
 * @date 24 October 2017
 *
 */

#include "uart.h"
#include "circbuf.h"


extern CB_t RX_buffer, TX_buffer;

/* To check for buffer full */
extern bool flag, tx_flag;


UART_status UART_configure(void)
{
	/* Initializing System Clock at mode 1 (48 Mhz core clock) */
	SystemInit();

	/* Enable Port A */
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	/* Enable clock to UART0 */
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;

	/* UART TX and RX pins */
	PORTA_PCR1 |= PORT_PCR_MUX(0x02);
	PORTA_PCR2 |= PORT_PCR_MUX(0x02);

	/* Enabling UART0 Clock - MCGPLLCLK */
	SIM_SOPT2 |= (SIM_SOPT2_PLLFLLSEL(1) | SIM_SOPT2_UART0SRC(1));

	/* Disable UART */
	UART0_C2 |= (UART0_C2_TE(0) | UART0_C2_RE(0));

	/* BAUD_RATE = (BAUD_CLOCK / ((OSR+1)*BR))
	 * OSR -> Over sampling rate (default 16)
	 */
	uint32_t BR = BAUD_CLOCK / (BAUD_RATE * (OSR+1));

	/* 1 stop bit */
	UART0_BDH = (UART0_BDH_SBNS(0) | UART0_BDH_SBR(BR>>8));

	/* Baud rate prescaler [7-0] */
	UART0_BDL = UART0_BDL_SBR(BR & 0xFF);

	/* 8-Bit mode */
	UART0_C1 |= UART0_C1_M(0);

	/* Enable Rx Interrupts */
	UART0_C2 |= UART0_C2_RIE(1);

	/* Over sampling rate - 16 (default) */
	UART0_C4 |= UART0_C4_OSR(OSR);

	/* Enable the UART0 TX and RX */
	UART0_C2 |= (UART0_C2_TE(1) | UART0_C2_RE(1));

	/* Enable NVIC interrupt for UART0 */
	NVIC_EnableIRQ(UART0_IRQn);

	return uart_success;
}

UART_status UART_send(uint8_t * data)
{
	if(data == NULL)
		return uart_null_pointer;
	else
	{
		/* wait for transmit buffer to get empty */
		while(!(UART0_S1 & UART0_S1_TDRE_MASK));
		UART0_D = *data;
		return uart_success;
	}
}

UART_status UART_send_n(uint8_t * data, size_t length)
{
	if(data == NULL)
		return uart_null_pointer;
	else if(length == 0)
		return uart_no_length;
	else
	{
		size_t i;
		for(i = 0; i < length; i++)
		{
			/* wait for transmit buffer to get empty */
			while(!(UART0_S1 & UART0_S1_TDRE_MASK));
			UART0_D = *(data+i);
		}
		return uart_success;
	}
}

UART_status UART_receive(uint8_t * data)
{
	if(data == NULL)
		return uart_null_pointer;
	else
	{
		/* Wait for receive buffer to get data */
		while(!(UART0_S1 & UART0_S1_RDRF_MASK));
		*data = UART0_D;
		return uart_success;
	}
}

UART_status UART_receive_n(uint8_t * data, size_t length)
{
	if(data == NULL)
		return uart_null_pointer;
	else if(length == 0)
		return uart_no_length;
	else
	{
		size_t i;
		for(i = 0; i < length; i++)
		{
			/* Wait for receive buffer to get data */
			while(!(UART0_S1 & UART0_S1_RDRF_MASK));
			*(data+i) = UART0_D;
		}
		return uart_success;
	}
}


void UART0_IRQHandler(void)
{
	uint8_t data_r, data_t, len;

	/* Service the Rx interrupt */
	if(UART0_S1 & UART0_S1_RDRF_MASK)
	{
		data_r = UART0_D;

		UART_send(&data_r);

		CB_buffer_add_item(&RX_buffer, data_r);

		/* Take count of elements */
	    len = (uint8_t)RX_buffer.count;

	    /* Process after every 20 elements */
	    if(len == 20)
	    {
	    	/* Flag for processing */
	    	flag = true;
	    }
	    else
	    {
	    	flag = false;
	    }
	}

	else if((UART0_S1 & UART0_S1_TDRE_MASK) && tx_flag )
	{

		len = (uint8_t)TX_buffer.count;

		for(int i = 0; i < len; i++)
		{
			CB_buffer_remove_item(&TX_buffer, &data_t);
			UART_send(&data_t);
		}

		/* Disable TX Interrupt */
		UART0_C2 &= ~(UART0_C2_TIE(1));

		/* Stop Stats */
		tx_flag = false;
	}


}

