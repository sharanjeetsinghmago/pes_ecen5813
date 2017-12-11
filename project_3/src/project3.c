/**
 * @file project3.c
 * @brief Functions to drive the project3
 *
 * This implementation file contains functions to drive
 * the all the functionality using circular buffer in project 3.
 *
 * @author Sharanjeet Singh Mago
 * @date 9 December 2017
 *
 */

#include "project3.h"
#include "MKL25Z4.h"

/* Receive and transmit circular buffers */
CB_t RX_buffer;

CB_t logger_buff;

/* To check for 20 elements to process */
bool flag = false;

/* To check for 20 logs to flush */
bool log_flag = false ;

void project3(void)
{
	/* Initializing System Clock at mode 1 (48 Mhz core clock) */
	SystemInit();

	/* Configuring UART */
	UART_configure();

	/* Initialize UART and Logger buffer */
	CB_init(&logger_buff, 1000);
	CB_init(&RX_buffer, 25);

	/* Configuring RTC */
	RTC_CLKSRC_init();
	RTC_init();

	/* Configuring DMA */
	DMA_configure();

	Log_type x;
	x.logID = LOGGER_INITIALIZED;
	x.log_time = RTC_TSR;
	log_item(&x,&logger_buff);

	/* Configuring GPIO */
	GPIO_nrf_init();

	x.logID = GPIO_INITIALIZED;
	x.log_time = RTC_TSR;
	log_item(&x,&logger_buff);

	/* Configuring SPI */
	SPI_init();

	x.logID = SYSTEM_INITIALIZED;
	x.log_time = RTC_TSR;
	log_item(&x,&logger_buff);


	while(1)
	{
		if(flag == true)
		{
			dump_statistics();
		}

		if(log_flag == true)
		{
			char nline[] = "\n\r";
			log_string(nline);
			log_flush();
		}
	}
}



