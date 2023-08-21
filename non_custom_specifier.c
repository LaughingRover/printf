#include "main.h"
#include <stdlib.h>
#include <unistd.h>

#define NULL ((void *)0)

/**
 * print_hex - prints hexadecimal integer
 * @num: integer to be printed
 * @num_of_printed_chars: total number of printed chars
 * @buffer: local buffer to minimize write calls
 */
void print_hex(unsigned int num, char fmt, int *num_of_printed_chars, char buffer[])
{
	char *buf = buffer;
	char *remainder = malloc(sizeof(size_t));
	char *rem_ptr = remainder;
	int i = 0, digit;

	if (remainder == NULL)
		return;

	if (fmt == 'x')
		fmt = 'a';
	else
		fmt = 'A';
		
	if (num)
	{
		/* convert num to character aray*/
		while (num != 0) 
		{
			digit = num % 16;
			if (digit >= 10)
				*(rem_ptr + i) = fmt + (digit - 10);
			else
				*(rem_ptr + i) = '0' + digit;
			num /= 16;
			i++;
		}
		/* reverse rem array to get actual number */
		for (i-- ; i >= 0 ; i--)
		{
			*(buf++) = *(rem_ptr + i);
			(*num_of_printed_chars)++;
		}
	}

	*buf = '\0';
	write(STDOUT_FILENO, buffer, *num_of_printed_chars);
	
	free(remainder);
}

/**
* print_un_int - prints an unsigned integer
* @num: number to be printed
* @num_of_printed_chars: total number of characters printed
* @buffer: local buffer to minimize write call
*/
void print_un_int(unsigned int num, int *num_of_printed_chars, char buffer[])
{
	char *buf = buffer;
	char *rem = malloc(sizeof(unsigned int));
	int i = 0, j = 0;

	if (rem == NULL)
		return;
	if (num)
	{
		while (num != 0)
		{
			*(rem + i) = (num % 10) + '0';
			num = num /10;
			i++;
		}
		for (i-- ; i >= 0 ; i--)
		{
			*(buf + j) = *(rem + i);
			j++;
			(*num_of_printed_chars)++;
		}
		*(buf + j + 1) = '\0';
		write (STDOUT_FILENO, buffer, *num_of_printed_chars);
	}
	free(rem);
}

