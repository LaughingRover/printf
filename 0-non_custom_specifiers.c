#include "main.h"

#define NULL ((void *)0)

/**
 * handle_character_specifier - writes the character c to buffer
 * @args: argument list
 * @context: data store for formatting options and arguments
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
 * @context: data store for formatting options and arguments
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
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_integer_specifier(va_list args, FormatContext *context)
{
	int num = 0, i = 0;
	int length_modifier = context->length_modifier;
	char rem[20];

	if (context->flags == FLAG_PLUS)
		write_buffer('+', context);
	else if (context->flags == FLAG_SPACE)
		write_buffer(' ', context);

	if (length_modifier == LENGTH_MODIFIER_NONE)
		num = va_arg(args, int);
	else if (length_modifier == LENGTH_MODIFIER_LONG)
		num = va_arg(args, long int);
	else if (length_modifier == LENGTH_MODIFIER_SHORT)	/*Using typecast*/
		num = (int)(short int)va_arg(args, int);		/*to avoid promotion*/

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
	for (; i >= 0 ; i--)
	{
		write_buffer(rem[i], context);
	}
	reset_flags_modifiers(context);

	return (0);
}

/**
 * handle_mem_addr_specifier - writes memory address to buffer
 * @args: argument list
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_mem_addr_specifier(va_list args, FormatContext *context)
{
	void *addr = va_arg(args, void *);

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
 * @args: argument list
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_uint_specifier(va_list args, FormatContext *context)
{
	unsigned int num = va_arg(args, unsigned int);
	char *rem = malloc(sizeof(unsigned int));
	int i = 0;

	if (rem == NULL)
		return (-1);

	if (num)
	{
		while (num != 0)
		{
			*(rem + i++) = (num % 10) + '0';
			num /= 10;
		}

		/* reverse rem array to get actual number */
		for (i-- ; i >= 0 ; i--)
		{
			write_buffer(*(rem + i), context);
		}

	}
	free(rem);
	return (0);
}
