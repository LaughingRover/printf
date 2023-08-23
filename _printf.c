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
	va_list args;
	char buffer[BUFSIZE]; /*Local buffer to minimize write calls*/
	size_t buf_index = 0;
	specifier_function spec_func;

	if (format == NULL)
		return (-1);

	_memset(buffer, '0', sizeof(buffer));
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%') /*Handle format specifiers*/
		{
			spec_func = get_specifier_func(*(++format));
			if (spec_func)
			{
				spec_func(args, buffer, &buf_index);
			}
			else if (*format == '%')
			{
				/*Double '%' character, print as-is*/
				write_buffer(*format, buffer, &buf_index);
			}
			else
			{
				/*Unsupported format specifier, print as-is*/
				write_buffer('%', buffer, &buf_index);
				write_buffer(*format, buffer, &buf_index);
			}
		}
		else
		{
			write_buffer(*format, buffer, &buf_index);
		}
		format++;
	}
	va_end(args);
	buffer[buf_index] = '\0';
	return (flush_buffer(buffer, &buf_index));
}

