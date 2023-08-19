#include <stdarg.h>
#include <string.h>
#include <unistd.h>
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
	int num_of_printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			handle_specifier(*(++format), args,
					&num_of_printed_chars);
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
 * handle_specifier - handler to print to output based on specified format
 * @fmt: format to print
 * @args: variable arguments
 * @num_of_printed_chars: total number of characters printed
 *
 * Return: void
 */
void handle_specifier(char fmt, va_list args, int *num_of_printed_chars)
{
	char *str;

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
		str = va_arg(args, char *);
		write(STDOUT_FILENO, str, strlen(str));
		(*num_of_printed_chars) += strlen(str);
		break;
	case 'b':
		dec_to_bin(va_arg(args, int), num_of_printed_chars);
		break;
	default:
		_putchar('%');
		_putchar(fmt);
		++(*num_of_printed_chars);
	}
}

