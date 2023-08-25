#include "main.h"

/**
 * parse_flags - checks format specifiers for flags and sets the bits
 * @fmt: format specifier
 * @context: data store for formatting options and arguments
 *
 * Return: flag
*/
int parse_flags(const char fmt, FormatContext *context)
{
	switch (fmt)
	{
	case '+':
		context->flags |= FLAG_PLUS;
		break;
	case ' ':
		context->flags |= FLAG_SPACE;
		break;
	case '#':
		context->flags |= FLAG_HASH;
		break;
	case '-':
		context->flags |= MOD_MINUS;
		break;
	case '0':
		context->flags |= FLAG_ZERO;
		break;
	}

	return (context->flags);
}

/**
 * parse_length_modifiers - indicates the size of the argument
 * @fmt: format specifier
 * @context: data store for formatting options and arguments
 *
 * Description: The h length modifier is used to indicate that the argument
 * is a short int (for integer specifiers). Example: %hd for short int
 *
 * Return: length modifier
*/
int parse_length_modifiers(const char fmt, FormatContext *context)
{
	switch (fmt)
	{
	case 'l':
		context->length_modifier |= LENGTH_MODIFIER_LONG;
		break;
	case 'h':
		context->length_modifier |= LENGTH_MODIFIER_SHORT;
		break;
	}

	return (context->length_modifier);
}

/**
 * parse_width - indicates the
 * @fmt: format specifier
 * @context: data store for formatting options and arguments
 *
 * Return: width
*/
int parse_width(const char fmt, FormatContext *context)
{
	if (fmt >= 0 && fmt <= 9)
	{
		/**
		 * TODO: Implement parse width
		*/
	}

	return (context->width);
}
