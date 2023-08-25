#include "main.h"

/**
 * handle_binary_specifier - converts unsigned integer to binary
 * and writes to buffer
 * @context: data store for formatting options and arguments
 *
 * Description: print binary numbers to output and increase the
 * num_of_printed_chars by 1 for each printed character
 *
 * Return: On success 0.
 */
int handle_binary_specifier(FormatContext *context)
{
	int num = va_arg(context->args, int), i = 0;
	char rem[22];

	if (!num)
		return (1);

	if (num < 0)
	{
		num = -num;
		write_buffer('1', context);
	}

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
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_mod_string_specifier(FormatContext *context)
{
	char *str = va_arg(context->args, char *);

	if (str == NULL)
		_printf("(null)");

	while (*str != '\0')
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			write_buffer('\\', context);
			write_buffer('x', context);

			/*Replace with custom function to Convert to Hexadecimal*/
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
 * handle_reverse_string_specifier - writes reversed string to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_reverse_string_specifier(FormatContext *context)
{
	char *str = va_arg(context->args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	/*Find length of the string*/
	while (str[len++] != '\0')
	{}

	/*Reverse string and write into buffer*/
	while (len-- > 0)
	{
		write_buffer(str[len], context);
	}

	return (0);
}

/**
 * handle_rot13_string_specifier - writed the encoded string in rot13 to buffer
 * @context: data store for formatting options and arguments
 *
 * Return: On success 0.
 */
int handle_rot13_string_specifier(FormatContext *context)
{
	char *str_in = va_arg(context->args, char *);
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int size = 0, i;
	int len = strlen(str_in);
	char *str = malloc(sizeof(char) * len);

	str = strdup(str_in);

	if (str == NULL)
		return (1);

	while (str[size] != '\0')
	{
		for (i = 0; i < 52; i++)
		{
			if (str[size] == input[i])
			{
				*(str + size) = output[i];
				break;
			}
		}

		size++;
	}

	for (i = 0; i <= size; i++)
	{
		write_buffer(str[i], context);
	}
	free(str);

	return (0);
}

