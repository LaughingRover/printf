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
	specifier_function spec_func;
	FormatContext context = initialize_format_context();

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (parse_flags(*format, &context))
				format++;
			if (parse_length_modifiers(*format, &context))
				format++;
			if (parse_width(*format, &context))
				format++;

			spec_func = get_specifier_func(*format); /*Handle Specifiers*/
			if (spec_func)
			{
				spec_func(args, &context);
			}
			else if (*format == '%') /*Double '%' character, print as-is*/
			{
				write_buffer(*format, &context);
			}
			else /*Unsupported format specifier, print as-is*/
			{
				write_buffer('%', &context);
				write_buffer(*format, &context);
			}
		}
		else
		{
			write_buffer(*format, &context);
		}
		format++;
	}
	va_end(args);
	context.buffer[context.buf_index] = '\0';
	return (flush_buffer(&context));
}

