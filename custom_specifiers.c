#include "main.h"

#define NULL ((void *)0)

/**
 * dec_to_bin - converts unsigned integer to binary
 * @n: integer to convert
 * @num_of_printed_chars: amount of printed characters
 *
 * Description: print binary numbers to output and increase the
 * num_of_printed_chars by 1 for each printed character
 *
 * Return: 0 if succesful, 1 if failed
 */
int dec_to_bin(int n, int *num_of_printed_chars)
{
	(void)num_of_printed_chars;

	if (n < 0 || num_of_printed_chars == NULL)
		return (1);

	/**
	 * TODO:
	 * Binary integer conversion goes here
	 */

	_printf("Helper function to convert to and print binary numbers ");
	return (0);
}

