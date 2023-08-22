#include "main.h"

#define NULL ((void *)0)

/**
 * handle_binary_specifier - converts unsigned integer to binary
 * and writes to buffer
 * @args: argument list
 * @num_of_printed_chars: amount of printed characters
 * @buf_ptr: pointer to local buffer
 *
 * Description: print binary numbers to output and increase the
 * num_of_printed_chars by 1 for each printed character
 *
 * Return: On success 0.
 */
int handle_binary_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr)
{
	int num = va_arg(args, int);

	if (!num)
		exit(4);

	(void)num_of_printed_chars;
	(void)buf_ptr;

	if (num < 0 || num_of_printed_chars == NULL)
		return (-1);

	/*Prevent buffer overflow*/
	if (*num_of_printed_chars < BUFSIZE - 1)
	{
		/**
		 * TODO:
		 * Binary integer conversion goes here
		 */
	}

	return (0);
}

/**
 * handle_mod_string_specifier - writes modified string to buffer
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 0.
 */
int handle_mod_string_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		_printf("(null)");
		exit(5);
	}

	/*Prevent buffer overflow*/
	while (*str != '\0' && *num_of_printed_chars < BUFSIZE - 1)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			*(buf_ptr++) = '\\';
			*(buf_ptr++) = 'x';

			/*Replace with custom function to Convert to Hexadecimal*/
			#include <stdio.h>
			sprintf(buf_ptr, "%02X", *str);

			buf_ptr += 2; /*Increase buf_ptr ptr by 2 (for the two hex numbers)*/
			*num_of_printed_chars += 4;
		}
		else
		{
			*(buf_ptr++) = *str;
			(*num_of_printed_chars)++;
		}
		str++;
	}

	return (0);
}
