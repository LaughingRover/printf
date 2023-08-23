#include "main.h"
#include <stdlib.h>

#define NULL ((void *)0)

/**
 * handle_hexadecimal_specifier - writes unsigned hexadecimal to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_hexadecimal_specifier(va_list args, FormatContext *context)
{
	unsigned int num = va_arg(args, unsigned int);
	char rem[22]; /* Assuming a 64-bit integer can have  20 digits */
	int i = 0, digit;

	if (num == 0)
	{
		/* handle zero case */
		write_buffer('0', context);
		return (0);
	}

	/* convert num to charater array */
	while (num != 0)
	{
		digit = num % 16;

		if (digit >= 10)
			rem[i++] = 'a' + (digit - 10);
		else
			rem[i++] = '0' + digit;
		num /= 16;
	}
	/* reverse rem array to get actual number */
	for (i-- ; i >= 0 ; i--)
	{
		write_buffer(rem[i], context);
	}

	return (0);
}

/**
 * handle_hexa_upper_specifier - writes unsigned hexadecimal to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Description: writes the letters in uppercase
 * Return: on success 0
 */
int handle_hexa_upper_specifier(va_list args, FormatContext *context)
{
	unsigned int num = va_arg(args, unsigned int);
	char rem[22]; /* Assuming a 64-bit integer can have at most 20 digits */
	int i = 0, digit;

	if (num == 0)
	{
		/* Handle zero case */
		write_buffer('0', context);
		return (0);
	}



	while (num != 0)
	{
		digit = num % 16;

		if (digit >= 10)
			rem[i++] = 'A' + (digit - 10);
		else
			rem[i++] = '0' + digit;
		num /= 16;
	}

	for (i-- ; i >= 0 ; i--)
	{
		write_buffer(rem[i], context);
	}
	return (0);
}

/**
 * handle_octal_specifier - writes unsigned octal to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On successs 0
 */
int handle_octal_specifier(va_list args, FormatContext *context)
{
	unsigned int num = va_arg(args, unsigned int);
	char rem[22]; /* Assuming a 64-bit integer can have at most 20 digits */
	int i = 0;

	if (num == 0)
	{
		/* Handle zero case */
		write_buffer('0', context);
		write_buffer('0', context);
		return (0);
	}

	if (num)
	{
		while (num != 0)
		{
			*(rem + i++) = (num % 8) + '0';
			num /= 8;
		}

		for (i-- ; i >= 0 ; i--)
		{
			write_buffer(*(rem + i), context);
		}
	}

	return (0);
}

