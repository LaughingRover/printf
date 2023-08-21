#include "main.h"
#include <stdio.h>

#define NULL ((void *)0)

/**
 * print_binary - converts unsigned integer to binary
 * @n: integer to convert
 * @num_of_printed_chars: amount of printed characters
 *
 * Description: print binary numbers to output and increase the
 * num_of_printed_chars by 1 for each printed character
 *
 * Return: 0 if succesful, 1 if failed
 */
int print_binary(int n, int *num_of_printed_chars)
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

/**
 * print_mod_string - prints a modified string
 * @str: string to print
 * @num_of_printed_chars: total number of printed chars
 * @buffer: local buffer to minimize write calls
 */
void print_mod_string(char *str, int *num_of_printed_chars, char buffer[])
{
	char *buf = buffer;

	if (str == NULL)
		return;

	while (*str != '\0')
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			*buf = '\\';
			buf++;
			*buf = 'x';
			buf++;

			/*Could be replaced with custom function to Convert to Hexadecimal*/
			sprintf(buf, "%02X", *str);

			buf += 2; /*Increase buf ptr by 2 (for the two hex numbers)*/
			*num_of_printed_chars += 4;
		}
		else
		{
			*buf = *str;
			buf++;
			(*num_of_printed_chars)++;
		}
		str++;
	}
	*buf = '\0';

	write(STDOUT_FILENO, buffer, *num_of_printed_chars);
}

