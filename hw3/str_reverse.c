/**
 * @file str_reverse.c
 * @brief Revrese string function.
 *
 * This file prints the size of the architecture data.
 *
 * @author Vipul Gupta
 * @date 21 September 2017
 *
 */



#include <stdio.h>
#include <string.h>



/**
* @brief Reverse the string
*
* Given a pointer to a string and its length, this function will
* reverse the string using pointer arithmetic.
*
* @param str Pointer to a string
* @param length Length of the string
*
* @return char Return '0' if the function is successful and return '1'
* if the function fails.              .
*/
char reverse(char * str, int length)
{
    int i;
    if( str == NULL | length < 0 | strlen(str) != length )
    {
        /*Return a non-zero value on fail*/
        return '1';
    }
    else
    {
        for( i = 0; i < (length / 2); i++ )
        {
            char tmp;
            tmp = *(str + i);
            *(str + i) = *(str + length - i - 1);
            *(str + length - i - 1) = tmp;
        }
        /*Return a zero value on success*/
        return '0';
    }
}

int main()
{

    char my_string[] = "This is a string.";
    //int l = strlen(even_string);
    int str_length = 17;

    reverse(my_string, str_length);
    printf("%s", my_string);
    printf("\n");

    char my_string1[] = "some NUMmbers12345";
    str_length = 17;

    reverse(my_string1, str_length);
    printf("%s", my_string1);
    printf("\n");

    char my_string2[] = "Does it reverse \n\0\t correctly?";
    str_length = 30;

    reverse(my_string2, str_length);
    printf("%s", my_string2);
    printf("\n");

    return 0;
}