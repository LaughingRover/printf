#include "main.h"
#include <stdlib.h>

#define NULL ((void *)0)

/**
 * handle_character_specifier - writes the character c to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On success 1 else -1
 */
int handle_character_specifier(va_list args, FormatContext *context)
{
	char c = va_arg(args, int);

	if (!c)
		return (1);

	write_buffer(c, context);

	return (0);
}

/**
 * handle_string_specifier - writes string to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_string_specifier(va_list args, FormatContext *context)
{
	const char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
		write_buffer(*(str++), context);

	return (0);
}

/**
 * handle_integer_specifier - writes integer to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_integer_specifier(va_list args, FormatContext *context)
{
	int num = va_arg(args, int), i = 0;
	char rem[22] ; /* Assuming a 64-bit integer  can have at most 20 digits */
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	if (num == 0)
	{
		/* handle zero case */
		write_buffer('0', context);
		return (0);
	}

	if (num)
	{
		/* convert integer to character array */
		while (num != 0)
		{
			rem[i++] = (num % 10) + '0';
			num = num / 10;
		}

		if (is_negative)
		{
			write_buffer('-', context);
		}

		/* reverse rem array to get actual number*/
		for (i-- ; i >= 0 ; i--)
		{
			write_buffer(rem[i], context);
		}
	}

	return (0);
}

/**
 * handle_mem_addr_specifier - writes memory address to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_mem_addr_specifier(va_list args, FormatContext *context)
{
	void *addr = va_arg(args, void *);

	if (addr == NULL)
		return (1);

	/*  Unused variable*/
	(void)addr;

	write_buffer('0', context);
	write_buffer('x', context);
	/*Write the hex representation of the address to buffer*/

	return (0);
}

/**
 * handle_uint_specifier - writes unsigned integer to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_uint_specifier(va_list args, FormatContext *context)
{
	unsigned int num = va_arg(args, unsigned int);
	char rem[22]; /* Assuming a 64-bit integer can have at most 20 digits */
	int i = 0;

	if (num == 0)
	{
		/* Handle zero case */
		write_buffer('0', context);
		return (0);
	}

	if (num)
	{
		while (num != 0)
		{
			rem[i++] = (num % 10) + '0';
			num /= 10;
		}

		/* reverse rem array to get actual number */
		for (i-- ; i >= 0 ; i--)
		{
			write_buffer(rem[i], context);
		}

	}

	return (0);
}
