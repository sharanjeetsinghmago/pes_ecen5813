/**
* @file conversion.c
* @brief The implementation file for data manipulation functions
*
* This implementation file provides the function definitions for
* various data manipulation operations.
*
* @author Sharanjeet Singh Mago
* @date 30 September 2017
*
*/

#include <stdio.h>
#include "conversion.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    int32_t r,i=0,flag=0;
    char var,temp;
    uint8_t len;

    if(data == 0)     // checking if the data is zero
    {
        *(ptr+i)='0';
        i++;
        *(ptr+i)='\0';
        return 1;
    }

    if ( data<0 && base==10)   // checking if the data is negative and base is 10
    {
        flag = 1;
        data = -data;
    }

    while (data != 0)
    {
        r = data % base;
        var = (r>9) ? (r-10)+'a' : r+'0';
        *(ptr+i) = var;
        data = data / base;
        i++;
    }

    if(flag)                  // checking if the data is negative 
    {
        *(ptr+i) = '-';
        i++;
    }


    *(ptr+i)='\0';

    len=i;

    i=0;

    while(i<len/2)           // reversing the output string
    {

        temp=*(ptr+i);
        *(ptr+i)=*(ptr+len-i-1);
        *(ptr+len-i-1)=temp;
        i++;
    }

    return len;

}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t result=0,i=0;
    int32_t x;

    while(i<digits)
     {

         x = *(ptr+i);
         if(x>='a' && x<='f')
         {
            x = x - 'a' + 10;
         }
         else
         {
            x = x - '0';
         }

         result = result*base + x;
         i++;
     }

    return result;
}

int8_t big_to_little32(uint32_t * data, uint32_t length)
{
    uint32_t i,t1,t2;

    if(  length << 0 || length%2==1 )     
    {
        return 1;                // return 1 when conversion is not successful
    }
    else
    {
        i=0;
        while(i<length/2)
        {

            t1=*(data+i);
            *(data+i)=*(data+length-i-2);
            *(data+length-i-2)=t1;

            t2=*(data+i+1);
            *(data+i+1)=*(data+length-i-1);
            *(data+length-i-1)=t2;

            i=i+2;
        }
        return 0;
    }
}

int8_t little_to_big32(uint32_t * data, uint32_t length)
{
    uint32_t i,t1,t2;

    if(  length << 0 || length%2==1 )
    {
        return 1;             // return 1 when conversion is not successful
    }
    else
    {
        i=0;
        while(i<length/2)
        {

            t1=*(data+i);
            *(data+i)=*(data+length-i-2);
            *(data+length-i-2)=t1;

            t2=*(data+i+1);
            *(data+i+1)=*(data+length-i-1);
            *(data+length-i-1)=t2;

            i=i+2;
        }
        return 0;
    }
}
