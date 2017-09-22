/**
 * @file hw3_ptr.c
 * @brief To demonstrate the pointer math.
 *
 * This file demonstrates various operations on data array elements
 * using pointer math.
 *
 * @author Vipul Gupta
 * @date 21 September 2017
 *
 */


#include <stdio.h>

int main()
{
	unsigned char arr[8];
	arr[0] = 0xEE;
	arr[1] = 0x12;
	arr[2] = 0x77;
	arr[3] = 0xBE;
	arr[4] = 0x66;
	arr[5] = 0x54;
	arr[6] = 0x33;
	arr[7] = 0xF0;

	unsigned char * ptr = arr;

	printf("---------------------------------------\n");
	printf("Data set before pointer math operations\n");
	printf("---------------------------------------\n");

	
	for(int i = 0; i < 8; i++)
	{
		printf("Address:  %d	%x\n", (100 + i), *(ptr+i) );
	}
	

	*ptr = (0xF1 & 127);
	ptr++;
	*ptr += 17;
	ptr += 2;
	*ptr = 15/4;
	ptr--;
	*ptr >>= 4;
	ptr = (arr+5);
	*ptr = ((1<<5) | (4<<2));
	*(arr+7) = 22;

	ptr = arr;

	printf("--------------------------------------\n");
	printf("Data set after pointer math operations\n");
	printf("--------------------------------------\n");
	
	for(int i = 0; i < 8; i++)
	{
		printf("Address:  %d	%x\n", (100 + i), *(ptr+i) );
	}

	return 0;
}