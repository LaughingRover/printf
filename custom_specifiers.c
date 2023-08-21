#include "main.h"
#include <stdio.h>

#define NULL ((void *)0)

/**
 * print_binary - converts unsigned integer to binary
 * @args: argument list
 * @num_of_printed_chars: amount of printed characters
 * @buf_ptr: pointer to local buffer
 *
 * Description: print binary numbers to output and increase the
 * num_of_printed_chars by 1 for each printed character
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int print_binary(va_list args, int *num_of_printed_chars, char *buf_ptr)
{
	int num = va_arg(args, int);
	(void)num_of_printed_chars;
	(void)buf_ptr;

	if (num < 0 || num_of_printed_chars == NULL)
		return (1);

	if (*num_of_printed_chars < 1023)
	{
		/**
		 * TODO:
		 * Binary integer conversion goes here
		 */
		_printf("Helper function to convert to and print binary numbers ");
	}

	return (0);
}

/**
 * print_mod_string - prints a modified string
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int print_mod_string(va_list args, int *num_of_printed_chars, char *buf_ptr)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		return (1);

	while (*str != '\0' && *num_of_printed_chars < 1023)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			*buf_ptr = '\\';
			buf_ptr++;
			*buf_ptr = 'x';
			buf_ptr++;

			/*Could be replaced with custom function to Convert to Hexadecimal*/
			sprintf(buf_ptr, "%02X", *str);

			buf_ptr += 2; /*Increase buf_ptr ptr by 2 (for the two hex numbers)*/
			*num_of_printed_chars += 4;
		}
		else
		{
			*buf_ptr = *str;
			buf_ptr++;
			(*num_of_printed_chars)++;
		}
		str++;
	}
	*buf_ptr = '\0';

	return (0);
}
