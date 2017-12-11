/*
 * profiler.c
 *
 *  Created on: 09-Dec-2017
 *      Author: SHARANJEET
 */

#include "profiler.h"

uint32_t start,end,latency;

uint8_t * src;

uint8_t * dst;

void Profiler_init()
{
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->LOAD |= SysTick_LOAD_RELOAD_Msk;
}


void profile_frdm()
{


	size_t length=5000;
	uint8_t value=5;

	src = (uint8_t *)malloc(sizeof(uint8_t)*length);

	dst = (uint8_t *)malloc(sizeof(uint8_t)*length);

	start = SysTick->VAL;

	//memset(src, value, length);
	//my_memset( src, length, value);

	my_memmove(src, dst, length);

	//memmove(dst,src,length);

	end = SysTick->VAL;

	latency = start - end;

	value = 10;
}


int8_t dmatest_memmove1()
{
  int i;
  uint8_t * set;
  uint8_t * ptra;
  uint8_t * ptrb;

  set = (uint8_t*) malloc(1000);

  if (! set )
  {
    return 0;
  }

  ptra = &set[0];
  ptrb = &set[500];

  /* Initialize the set to test values */
  for( i = 0; i < 1000; i++)
  {
    set[i] = 0x0a;
  }

  memmove_dma(ptra, ptrb, 500);

  //memset_dma(ptra, 16, 0xA0);

  //memzero_dma(ptra, 24);

  free( (void *) set );
}
