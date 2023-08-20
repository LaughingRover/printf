#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - produce output according to format
 * @format: list of arguments passed to the function
 *
 * Return: number of characters printed (excluding the null byte used to end
 * output to strings)
 */
int _printf(const char *format, ...)
{
	size_t i;
	int num_of_printed_chars = 0;
	char buffer[1024]; /*Local buffer to minimize write calls*/
	va_list args;

	if (format == NULL)
		return (1);

	/*Initialize buffer*/
	for (i = 0; i < sizeof(buffer); i++)
		buffer[i] = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			handle_specifier(*(++format), &num_of_printed_chars,
					args, buffer);
		}
		else
		{
			_putchar(*format);
			++num_of_printed_chars;
		}
		format++;
	}

	va_end(args);
	return (num_of_printed_chars);
}

/**
 * handle_specifier - prints to output based on specified format
 * @fmt: format to print
 * @args: variable arguments
 * @num_of_printed_chars: total number of printed chars
 * @buffer: local buffer to minimize write calls
 *
 * Return: void
 */
void handle_specifier(char fmt,
		int *num_of_printed_chars, va_list args, char buffer[])

{
	switch (fmt)
	{
	case '%':
		_putchar(fmt);
		++(*num_of_printed_chars);
		break;
	case 'c':
		_putchar(va_arg(args, int));
		++(*num_of_printed_chars);
		break;
	case 's':
		print_string(va_arg(args, char *),
				num_of_printed_chars, buffer);
		break;
	case 'b':
		dec_to_bin(va_arg(args, int), num_of_printed_chars);
		break;
	case 'S':
		print_mod_string(va_arg(args, char *),
				num_of_printed_chars, buffer);
		break;
	default:
		_putchar('%');
		_putchar(fmt);
		++(*num_of_printed_chars);
	}
}

/**
 * print_string - prints a string
 * @str: string to print
 * @num_of_printed_chars: total number of printed chars
 * @buffer: local buffer to minimize write calls
 */
void print_string(char *str, int *num_of_printed_chars, char buffer[])
{
	char *buf = buffer;

	if (str == NULL)
	{
		_printf("(null)");
	}
	else
	{
		while (*str != '\0')
		{
			*(buf++) = *(str++);
			(*num_of_printed_chars)++;
		}
		*buf = '\0';
		write(STDOUT_FILENO, buffer, *num_of_printed_chars);
	}
}

