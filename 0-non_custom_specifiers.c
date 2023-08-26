#include "main.h"

#define NULL ((void *)0)

/**
 * handle_character_specifier - writes the character c to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On success 1 else -1
 */
int handle_character_specifier(FormatContext *context)
{
	char c = va_arg(context->args, int);

	if (!c)
		return (1);

	write_buffer(c, context);

	return (0);
}

/**
 * handle_string_specifier - writes string to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_string_specifier(FormatContext *context)
{
	const char *str = va_arg(context->args, char *);

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		/*Check if buffer is full*/
		if (context->buf_index >= (BUFSIZE - 1))
		{
			flush_buffer(context);
		}
		write_buffer(*(str++), context);
	}
	return (0);
}

/**
 * handle_integer_specifier - writes integer to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_integer_specifier(FormatContext *context)
{
	int num = 0, i = 0;
	char rem[20];

	if (context->flags == FLAG_PLUS)
		write_buffer('+', context);
	else if (context->flags == FLAG_SPACE)
		write_buffer(' ', context);

	num = modify_integer_length(context);

	if (num < 0)
	{
		num = -num;
		write_buffer('-', context);
	}

	/*convert integer to character array*/
	do {
		rem[i++] = (num % 10) + '0';
		num = num / 10;
	} while (num > 0);

	/*reverse rem array to get actual number*/
	for (i--; i >= 0 ; i--)
	{
		write_buffer(rem[i], context);
	}
	reset_flags_modifiers(context);

	return (0);
}

/**
 * handle_mem_addr_specifier - writes memory address to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_mem_addr_specifier(FormatContext *context)
{
	void *addr = va_arg(context->args, void *);

	if (addr == NULL)
		return (1);

	/*Unused variable*/
	(void)addr;

	write_buffer('0', context);
	write_buffer('x', context);
	/*Write the hex representation of the address to buffer*/

	return (0);
}

/**
 * handle_uint_specifier - writes unsigned integer to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_uint_specifier(FormatContext *context)
{
	unsigned int num = 0;
	char rem[22]; /* Assuming a 64-bit integer can have at most 21 digits */
	int i = 0;

	num = (unsigned int)modify_integer_length(context);

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

