#include "main.h"

#define NULL ((void *)0)

/**
 * handle_binary_specifier - converts unsigned integer to binary
 * and writes to buffer
 * @args: argument list
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 *
 * Description: print binary numbers to output and increase the
 * num_of_printed_chars by 1 for each printed character
 *
 * Return: On success 0.
 */
int handle_binary_specifier(va_list args, char buffer[], size_t *buf_index)
{
	int num = va_arg(args, int);

	UNUSED(buffer);

	if (!num)
		exit(4);

	if (num < 0)
		return (-1);

	/*Prevent buffer overflow*/
	if (*buf_index < (BUFSIZE - 1))
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
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 *
 * Return: On success 0.
 */
int handle_mod_string_specifier(va_list args, char buffer[], size_t *buf_index)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		_printf("(null)");

	/*Prevent buffer overflow*/
	while (*str != '\0' && *buf_index < (BUFSIZE - 1))
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			write_buffer('\\', buffer, buf_index);
			write_buffer('x', buffer, buf_index);

			/*Replace with custom function to Convert to Hexadecimal*/
		}
		else
		{
			write_buffer(*str, buffer, buf_index);
		}
		str++;
	}

	return (0);
}
