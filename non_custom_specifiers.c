#include "main.h"
#include <stdlib.h>

#define NULL ((void *)0)

/**
 * handle_character_specifier - writes the character c to buffer
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 0.
 */
int handle_character_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr)
{
	char c = va_arg(args, int);

	if (!c)
		exit(1);

	/*Prevent buffer overflow*/
	if (*num_of_printed_chars < BUFSIZE - 1)
	{
		*(buf_ptr++) = c;
		(*num_of_printed_chars)++;
	}

	return (0);
}

/**
 * handle_string_specifier - writes string to buffer
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 0.
 */
int handle_string_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
		exit(2);
	}

	/*Prevent buffer overflow*/
	while (*str != '\0' && *num_of_printed_chars < BUFSIZE - 1)
	{
		*(buf_ptr++) = *(str++);
		(*num_of_printed_chars)++;
	}

	return (0);
}

/**
 * handle_integer_specifier - writes integer to buffer
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 0.
 */
int handle_integer_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr)
{
	int num = va_arg(args, int);
	int i = 0, j = 0;
	char *rem = malloc(20);

	if (rem == NULL)
		exit(3);

	if (num < 0)
	{
		num = -num;
		*(buf_ptr++) = '-';
		(*num_of_printed_chars)++;
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
		/*Prevent buffer overflow*/
		if (*num_of_printed_chars < BUFSIZE - 1)
		{
			*((buf_ptr++) + j++) = *(rem + i);
			(*num_of_printed_chars)++;
		}
	}

	free(rem);
	return (0);
}

/**
 * handle_mem_addr_specifier - writes memory address to buffer
 * @args: argument list
 * @num_of_printed_chars: total number of printed chars
 * @buf_ptr: pointer to local buffer
 *
 * Return: On success 0.
 */
int handle_mem_addr_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr)
{
	void *addr = va_arg(args, void *);

	if (addr == NULL)
		exit(6);

	/*Unused variable*/
	(void)addr;

	/*Prevent buffer overflow*/
	if (*num_of_printed_chars < BUFSIZE - 1)
	{
		*(buf_ptr++) = '0'; 
		*(buf_ptr++) = 'x';
		(*num_of_printed_chars)++;
		/*Write the hex representation of the address to buffer*/
	}

	return (0);
}
