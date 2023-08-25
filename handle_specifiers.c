#include "main.h"

/**
 * get_specifier_func - handles format specifiers
 * @fmt: format to print
 *
 * Return: Format specifier function else NULL if not found
 */
int (*get_specifier_func(char fmt))(FormatContext *)
{
	int i = 0;
	specifier spec[] = {
		{'c', handle_character_specifier},
		{'s', handle_string_specifier},
		{'d', handle_integer_specifier},
		{'i', handle_integer_specifier},
		{'b', handle_binary_specifier},
		{'S', handle_mod_string_specifier},
		{'p', handle_mem_addr_specifier},
		{'u', handle_uint_specifier},
		{'x', handle_hexadecimal_specifier},
		{'X', handle_hexa_upper_specifier},
		{'o', handle_octal_specifier},
		{'r', handle_reverse_string_specifier},
		{'R', handle_rot13_string_specifier},
	};

	while (i < (int)(sizeof(spec) / sizeof(spec[i])))
	{
		if (fmt == '\0')
			return (NULL); /*Unexpected end of format string after %*/

		if (fmt == spec[i].fmt)
			return (spec[i].func);
		i++;
	}

	return (NULL);
}

/**
 * check_flag_modifier - check for flags and sends them for parsing
 * @fmt: format to check
 * @context: data store for formatting options and arguments
 *
 * Return: void
 */
void check_flag_modifier(const char **fmt, FormatContext *context)
{
	if (parse_flag(**fmt, context))
		fmt++;
	if (parse_length_modifier(**fmt, context))
		fmt++;
	if (parse_width(**fmt, context))
		fmt++;
}

/**
 * check_specifier - checks if format is a specifier and handles it
 * @fmt: format to check
 * @context: data store for formatting options and arguments
 * @spec_func: function pointer to specifier handlers
 *
 * Return: void
 */
void check_specifier(const char **fmt, FormatContext *context,
						specifier_function *spec_func)
{
	*spec_func = get_specifier_func(**fmt); /*Handle Specifiers*/
	if (*spec_func)
	{
		(*spec_func)(context);
	}
	else if (**fmt == '%') /*Double '%' character, print as-is*/
	{
		write_buffer(**fmt, context);
	}
	else /*Unsupported format specifier, print as-is*/
	{
		write_buffer('%', context);
		write_buffer(**fmt, context);
	}
}
