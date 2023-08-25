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
