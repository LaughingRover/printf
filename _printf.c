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
	specifier_function spec_func;
	FormatContext context = initialize_format_context();

	if (format == NULL)
		return (-1);

	va_start(context.args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_flag_modifier(&format, &context);
			check_specifier(&format, &context, &spec_func);
		}
		else
		{
			write_buffer(*format, &context);
		}
		format++;
	}
	va_end(context.args);
	context.buffer[context.buf_index] = '\0';
	return (flush_buffer(&context));
}

