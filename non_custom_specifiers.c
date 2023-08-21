#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define NULL ((void *)0)

/**
 * print_character - writes the character c to stdout
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int print_character(va_list args, int *num_of_printed_chars, char *buf_ptr)
{
	char c = va_arg(args, int);

	if (*num_of_printed_chars < 1023)
	{
		*(buf_ptr++) = c;
		(*num_of_printed_chars)++;
	}

	return (0);
}

/**
 * print_string - prints a string
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 0.
 */
int print_string(va_list args, int *num_of_printed_chars, char *buf_ptr)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		_printf("(null)");
		return (1);
	}
	else
	{
		/*Prevent overflow*/
		while (*str != '\0' && *num_of_printed_chars < 1023)
		{
			*(buf_ptr++) = *(str++);
			(*num_of_printed_chars)++;
		}
		*buf_ptr = '\0';
	}

	return (0);
}

/**
 * print_int - prints an integer
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int print_int(va_list args, int *num_of_printed_chars, char *buf_ptr)
{
	int num = va_arg(args, int);
	char *rem = malloc(20);
	int i = 0, j = 0;

	if (num < 0)
	{
		num = -num;
		*(buf_ptr++) = '-';
	}
	/* convert integer to character array */
	while (num != 0)
	{
		*(rem + i) = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	/*reverse rem array to get actual number*/
	for (i--; i >= 0; i--)
	{
		if (*num_of_printed_chars < 1023)
		{
			*(buf_ptr + j) = *(rem + i);
			j++;
			(*num_of_printed_chars)++;
		}
	}
	*(buf_ptr + j + 1) = '\0';

	free(rem);
	return (0);
}

/**
 * print_mem_address - prints the address of a memory
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int print_mem_address(va_list args, int *num_of_printed_chars, char *buf_ptr)
{
	void *addr = va_arg(args, void *);

	/*Unused variable*/
	(void)addr;
	(void)buf_ptr;
	(void)(*num_of_printed_chars);

	if (*num_of_printed_chars < 1023)
	{
		_printf("0x");
		/*Print the hex representation of the address*/
	}

	return (0);
}
