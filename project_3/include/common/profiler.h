/*
 * profiler.h
 *
 *  Created on: 09-Dec-2017
 *      Author: SHARANJEET
 */

#ifndef INCLUDES_PROFILER_H_
#define INCLUDES_PROFILER_H_

#include "MKL25Z4.h"
#include <stdint.h>
#include <string.h>
#include "memory.h"
#include "dma.h"

void Profiler_init();

void profile_frdm();

int8_t dmatest_memmove1();


#endif /* INCLUDES_PROFILER_H_ */
