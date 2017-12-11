/**
 * @file project2.c
 * @brief Functions to drive the project2
 *
 * This implementation file contains functions to drive
 * the uart functionality using circular buffer.
 *
 * @author Vipul Gupta
 * @date 29 October 2017
 *
 */

#include "project2.h"
#include "MKL25Z4.h"

/* Receive and transmit circular buffers */
CB_t RX_buffer,TX_buffer;

/* To check for 20 elements to process */
bool flag = false;
/* To check when to print statistics */
bool tx_flag = false;

/* To store the count */
int32_t alp=0, num=0, punc=0, misc=0;


void dump_statistics(void)
{

	/* To store the ASCII value of count */
	uint8_t alp1[4], num1[4], punc1[4], misc1[4];

	/* Temporary variable to collect data */
	uint8_t tmp1 = 0;

	char CR = '\r';			// for formatting

	/* Process 20 elements */
	for(int i=0; i<20; i++)
	{
		CB_buffer_remove_item(&RX_buffer, &tmp1);

		/* Alphabets */
		if(tmp1>='a' && tmp1<='z' || tmp1>='A' && tmp1<='Z')
		{
			alp++;
		}
		/* Numbers */
		else if(tmp1>='0' && tmp1<='9')
		{
			num++;
		}
		/* Punctuations */
		else if((tmp1>='!' && tmp1<='/') || (tmp1>=':' && tmp1<='@') || (tmp1>='[' && tmp1<='`') || (tmp1>='{' && tmp1<='~'))
		{
			punc++;
		}
		/* Miscellaneous */
		else
		{
			misc++;
		}
	}


	char stats[] = "\rStatistics";

	for(int i=0; i < 11; i++)
	{
		CB_buffer_add_item(&TX_buffer, stats[i]);
	}

	char alph[] = "\rAlphabets = ";

	for(int i=0; i < 13; i++)
	{
		CB_buffer_add_item(&TX_buffer, alph[i]);
	}

	int l;
    l = my_itoa(alp, &alp1, 10);

    for(int i = 0; i < l; i++)
    {
    	CB_buffer_add_item(&TX_buffer, alp1[i]);
    }

	char nums[] = "\rNumbers = ";

	for(int i = 0; i < 11; i++)
	{
		CB_buffer_add_item(&TX_buffer,nums[i]);
	}

	l = my_itoa(num, &num1, 10);

	for(int i = 0; i < l; i++)
	{
		CB_buffer_add_item(&TX_buffer, num1[i]);
	}

	char puncs[] = "\rPunctuations = ";

	for(int i = 0; i < 16; i++)
	{
		CB_buffer_add_item(&TX_buffer, puncs[i]);
	}

	l = my_itoa(punc, &punc1, 10);

	for(int i = 0; i < l; i++)
	{
		CB_buffer_add_item(&TX_buffer, punc1[i]);
	}

	char miscs[]="\rMiscellaneous = ";

	for(int i = 0; i < 17; i++)
	{
		CB_buffer_add_item(&TX_buffer, miscs[i]);
	}

	l = my_itoa(misc, &misc1, 10);

	for(int i = 0; i < l; i++)
	{
		CB_buffer_add_item(&TX_buffer, misc1[i]);
	}

	CB_buffer_add_item(&TX_buffer, CR);

	flag = false;

	/* Ready to print statistics */
	tx_flag = true;

	/* Enable TX Interrupt */
	UART0_C2 |= UART0_C2_TIE(1);

}


void project2(void)
{
	UART_configure();

	CB_init(&RX_buffer,25);
	CB_init(&TX_buffer,120);

	while(1)
	{
		if(flag == true)
		{
			dump_statistics();
		}
	}
}
