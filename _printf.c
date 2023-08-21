#include <stdlib.h>
#include "main.h"

/**
 * _printf - produce output according to format
 * @format: list of arguments passed to the function
 *
 * Return: number of characters printed (excluding the null byte used to end
 * output to strings) Else return -1 on failure
 */
int _printf(const char *format, ...)
{
	size_t i;
	int num_of_printed_chars = 0;
	char buffer[1024]; /*Local buffer to minimize write calls*/
	char *buf_ptr = buffer;
	va_list args;
	specifier_function spec_func;

	if (format == NULL)
		return (1);

	/*Initialize buffer*/
	for (i = 0; i < sizeof(buffer); i++)
		buffer[i] = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(++format) != '%')
		{
			spec_func = get_specifier_func(*format);
			if (spec_func == NULL)
				return (num_of_printed_chars);

			spec_func(args, &num_of_printed_chars, buf_ptr);
		}
		else
		{
			*(buf_ptr++) = *format;
			num_of_printed_chars++;
		}
		format++;
	}
	*buf_ptr = '\0';

	va_end(args);
	write(STDOUT_FILENO, buffer, num_of_printed_chars);
	return (num_of_printed_chars);
}

/**
 * get_specifier_func - prints to output based on specified format
 * @fmt: format to print
 *
 * Return: void
 */
int (*get_specifier_func(char fmt))(va_list, int *, char *)
{
	int i = 0;
	spec_t spec[] = {
		{'c', print_character},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'S', print_mod_string},
		{'p', print_mem_address},
	};

	while (i < (int)(sizeof(spec) / sizeof(spec[i])))
	{
		if (fmt == '\0')
			return (NULL); /*Unexpected end of format string after %*/

		if (fmt == spec[i].c)
			return (spec[i].func);
		i++;
	}

	return (NULL);
}
