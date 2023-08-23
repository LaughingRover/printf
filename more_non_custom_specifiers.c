#include "main.h"
#include <stdlib.h>

#define NULL ((void *)0)

/**
 * handle_hexadecimal_specifier - writes unsigned hexadecimal to buffer
 * @args: argument list
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 *
 * Return: On success 0.
 */
int handle_hexadecimal_specifier(va_list args, char buffer[], size_t *buf_index)
{
	unsigned int num = va_arg(args, unsigned int);
	char *rem = malloc(sizeof(unsigned int));
	int i = 0, digit;

	if (rem == NULL)
		exit(5);

	/* convert num to charater array */
	while (num != 0)
	{
		digit = num % 16;

		if (digit >= 10)
			*(rem + i++) = 'a' + (digit - 10);
		else
			*(rem + i++) = '0' + digit;
		num /= 16;
	}
	/* reverse rem array to get actual number */
	for (i-- ; i >= 0 ; i--)
	{
		write_buffer(*(rem + i), buffer, buf_index);
	}
	free(rem);
	return (0);
}

/**
 * handle hexa_upper_specifier - writes unsigned hexadecimal to buffer
 * @args: argument list
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 * Description: writes the letters in uppercase
 *
 * Return: on success 0
 */
int handle_hexa_upper_specifier(va_list args, char buffer[], size_t *buf_index)
{
	unsigned int num = va_arg(args, unsigned int);
	char *rem = malloc(sizeof(unsigned int));
	int i = 0, digit;

	if (rem == NULL)
		exit(7);

	while (num != 0)
	{
		digit = num % 16;

		if (digit >= 10)
			*(rem + i++) = 'A' + (digit - 10);
		else
			*(rem + i++) = '0' + digit;
		num /= 16;
	}

	for (i-- ; i >= 0 ; i--)
	{
		write_buffer(*(rem + i), buffer, buf_index);
	}
	free(rem);
	return (0);
}

/**
 * handle_octal_specifier - writes unsigned octal to buffer
 * @args: argument list
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 *
 * Return: On successs 0
 */
int handle_octal_specifier(va_list args, char buffer[], size_t *buf_index)
{
	unsigned int num = va_arg(args, unsigned int);
	char *rem = malloc(sizeof(unsigned int));
	int i = 0;

	if (rem == NULL)
		exit(6);

	if (num)
	{
		while (num != 0)
		{
			*(rem + i++) = (num % 8) + '0';
			num /= 8;
		}

		for (i-- ; i >= 0 ; i--)
		{
			write_buffer(*(rem + i), buffer, buf_index);
		}
	}
	free(rem);
	return (0);
}

