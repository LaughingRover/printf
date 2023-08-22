#include "main.h"
#include <stdlib.h>

#define NULL ((void *)0)

/**
 * handle_character_specifier - writes the character c to buffer
 * @args: argument list
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 *
 * Return: On success 1 else -1
 */
int handle_character_specifier(va_list args, char buffer[], size_t *buf_index)
{
	char c = va_arg(args, int);

	if (!c)
		exit(-1);

	write_buffer(c, buffer, buf_index);

	return (0);
}

/**
 * handle_string_specifier - writes string to buffer
 * @args: argument list
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 *
 * Return: On success 0.
 */
int handle_string_specifier(va_list args, char buffer[], size_t *buf_index)
{
	const char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
		write_buffer(*(str++), buffer, buf_index);

	return (0);
}

/**
 * handle_integer_specifier - writes integer to buffer
 * @args: argument list
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 *
 * Return: On success 0.
 */
int handle_integer_specifier(va_list args, char buffer[], size_t *buf_index)
{
	int num = va_arg(args, int), i = 0;
	char *rem = malloc(20);

	if (rem == NULL)
		exit(3);

	if (num < 0)
	{
		num = -num;
		write_buffer('-', buffer, buf_index);
	}

	/* convert integer to character array */
	while (num != 0)
	{
		*(rem + i++) = (num % 10) + '0';
		num = num / 10;
	}

	/*reverse rem array to get actual number*/
	for (i--; i >= 0; i--)
	{
		write_buffer(*(rem + i), buffer, buf_index);
	}

	free(rem);
	return (0);
}

/**
 * handle_mem_addr_specifier - writes memory address to buffer
 * @args: argument list
 * @buffer: pointer to local buffer
 * @buf_index: buffer index
 *
 * Return: On success 0.
 */
int handle_mem_addr_specifier(va_list args, char buffer[], size_t *buf_index)
{
	void *addr = va_arg(args, void *);

	if (addr == NULL)
		exit(6);

	/*Unused variable*/
	(void)addr;

	write_buffer('0', buffer, buf_index);
	write_buffer('x', buffer, buf_index);
	/*Write the hex representation of the address to buffer*/

	return (0);
}
