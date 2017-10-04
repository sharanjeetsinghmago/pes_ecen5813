/**
 * @file platform.h 
 * @brief This file is for selecting various platforms
 * 
 * This file is used for complile time switch between different 
 * platforms
 *
 * @author Vipul Gupta
 * @date 3 October 2017
 *
 */

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

/* PLATFORM KL25Z (Freedom board) */
#if defined (KL25Z)
	#include "MKL25Z4.h"
	//#define printf(...)
#endif


/* PLATFORM BBB (Beagle Bone Black) */
//#elif defined (BBB)
//

/* PLATFORM HOST */
//#else
//


#endif  /* __PLATFORM_H__ */