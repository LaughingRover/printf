#include "main.h"

#define NULL ((void *)0)

/**
 * handle_hexadecimal_specifier - writes unsigned hexadecimal to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_hexadecimal_specifier(FormatContext *context)
{
	unsigned int num = 0;
	char rem[18]; /* Assuming a 64-bit integer can have 16 hex digits */
	int i = 0, digit;

	num = (unsigned int)modify_integer_length(context);

	/*convert num to charater array*/
	do {
		digit = num % 16;

		if (digit >= 10)
			rem[i++] = 'a' + (digit - 10);
		else
			rem[i++] = '0' + digit;
		num /= 16;
	} while (num > 0);

	if (context->flags == FLAG_HASH)
	{
		write_buffer('0', context);
		write_buffer('x', context);
	}

	/* reverse rem array to get actual number */
	for (i--; i >= 0; i--)
	{
		write_buffer(rem[i], context);
	}

	return (0);
}

/**
 * handle_hexa_upper_specifier - writes unsigned hexadecimal to buffer
 * @context: data store for formatting options and arguments
 *
 * Description: writes the letters in uppercase
 * Return: on success 0
 */
int handle_hexa_upper_specifier(FormatContext *context)
{
	unsigned int num = 0;
	char rem[18]; /* Assuming a 64-bit integer can have 16 hex digits */
	int i = 0, digit;

	num = (unsigned int)modify_integer_length(context);

	/*convert num to charater array*/
	do {
		digit = num % 16;

		if (digit >= 10)
			rem[i++] = 'A' + (digit - 10);
		else
			rem[i++] = '0' + digit;
		num /= 16;
	} while (num > 0);

	if (context->flags == FLAG_HASH)
	{
		write_buffer('0', context);
		write_buffer('X', context);
	}

	for (i--; i >= 0; i--)
	{
		write_buffer(rem[i], context);
	}

	return (0);
}

/**
 * handle_octal_specifier - writes unsigned octal to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On successs 0
 */
int handle_octal_specifier(FormatContext *context)
{
	unsigned int num = 0;
	char rem[24]; /*Assuming a 64-bit integer can have 22 octal digits*/
	int i = 0;

	num = (unsigned int)modify_integer_length(context);

	/*convert num to charater array*/
	do {
		rem[i++] = (num % 8) + '0';
		num /= 8;
	} while (num > 0);

	if (context->flags == FLAG_HASH)
		write_buffer('0', context);

	for (i--; i >= 0; i--)
	{
		write_buffer(rem[i], context);
	}

	return (0);
}

