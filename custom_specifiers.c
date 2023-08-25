#include "main.h"

/**
 * handle_binary_specifier - converts unsigned integer to binary
 * and writes to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Description: print binary numbers to output and increase the
 * num_of_printed_chars by 1 for each printed character
 *
 * Return: On success 0.
 */
int handle_binary_specifier(va_list args, FormatContext *context)
{
	int num = va_arg(args, int), i = 0;
	char rem[32];

	if (num < 0)
		return (-1);

	if (num == 0)
	{
		write_buffer('0',  context);

		return (0);
	}

	while (num > 0)
	{
		rem[i++] = (num % 2) + '0';
		num /= 2;
	}
	/* reverrse rem array to get actual number */
	for (i-- ; i >= 0 ; i--)
	{
		write_buffer(rem[i], context);
	}


	return (0);
}

/**
 * handle_mod_string_specifier - writes modified string to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_mod_string_specifier(va_list args, FormatContext *context)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		_printf("(null)");

	while (*str != '\0')
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			write_buffer('\\', context);
			write_buffer('x', context);
		}
		else
		{
			write_buffer(*str, context);
		}
		str++;
	}

	return (0);
}

/**
 * handle_reverse_string_specifier - writes reverse of string to buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_reverse_string_specifier(va_list args, FormatContext *context)
{

	return (0);
}

/**
 * handle_rot13'ed_string_specifier - writes  the  encoded string using rot13 to
 * buffer
 * @args: argument list
 * @context: formatting options and arguments
 *
 * Return: On Success 0.
 */
int handle_rot13_string_specifier(va_list args, FormatContext *context)
{
	const char *str = va_arg(args, char *);
	char *str_out = malloc(sizeof(str));

	char input[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char output[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};
	int i, size = 0;

	if (str == NULL)
		str = "(null)";

	while (str[size] != '\0')
	{
		*(str_out + size) = str[size];
		/*Replace with corrresponding rot13 char*/
		for (i = 0 ; i < 52 ; i++)
		{
			if (*(str_out + size) == input[i])
			{
				*(str_out + size) = output[i];
				break;
			}
		}

		size++;
	}

	for (i = 0 ; i <= size ; i++)
	{
		write_buffer(*(str_out + size), context);
	}

	free(str_out);

	return (0);
}

