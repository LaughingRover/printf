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
	va_list args;
	int num_of_printed_chars = 0;
	char buffer[BUFSIZE]; /*Local buffer to minimize write calls*/
	char *buf_ptr = buffer;
	specifier_function spec_func;

	if (format == NULL)
		return (-1);

	/*Initialize buffer*/
	for (i = 0; i < sizeof(buffer); i++)
		buffer[i] = 0;

	va_start(args, format);

	while (*format != '\0' && num_of_printed_chars < BUFSIZE - 1)
	{
		if (*format == '%')
		{
			spec_func = get_specifier_func(*(++format));

			if (spec_func)
			{
				spec_func(args, &num_of_printed_chars, buf_ptr);
			}
			else if (*format == '%')
			{
				/*Double '%' character, print as-is*/
				*(buf_ptr++) = *format;
				num_of_printed_chars++;
			}
			else
			{
				/*Unsupported format specifier, print as-is*/
				*(buf_ptr++) = '%';
				*(buf_ptr++) = *format;
				num_of_printed_chars += 2;
			}
		}
		else
		{
			*(buf_ptr++) = *format;
			num_of_printed_chars++;
		}
		format++;
	}
	*buf_ptr = '\0'; /*Add null-terminating character at the end of the sequence*/
	va_end(args);
	write(STDOUT_FILENO, buffer, num_of_printed_chars);

	return (num_of_printed_chars);
}
