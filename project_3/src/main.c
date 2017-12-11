/**
 * @file main.c
 * @brief The main file for executing project deliverables.
 *
 * This main file provides the function calls for projects.
 *
 * @author Vipul Gupta
 * @date 29 October 2017
 *
 */


#include "project1.h"
#include "project2.h"
#include "project3.h"

int main(void)
{

#ifdef PROJECT1
	project1();
#endif

#ifdef PROJECT2
	project2();
#endif

#ifdef PROJECT3
	project3();
#endif	

}