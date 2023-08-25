#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE		(1024)
#define UNUSED(x)	(void)(x)
#define NULL		((void *)0)

#define FLAG_PLUS	(0X01)
#define FLAG_SPACE	(0x02)
#define FLAG_HASH	(0x03)
#define FLAG_ZERO	(0x04)
#define MOD_MINUS	(0x05)

#define LENGTH_MODIFIER_NONE	(0x00)
#define LENGTH_MODIFIER_LONG	(0x01)
#define LENGTH_MODIFIER_SHORT	(0x02)


/**
 * struct FormatContext - formatting options and arguments
 * @flags: represents various formatting flags for the output
 * @width: specifies the minimum field width for formatted output
 * @precision: specifies the precision for formatted output, for
 * floating-point numbers
 * @size: indicates the size of the data being formatted
 * @buf_index: keeps track of the current position in a buffer
 * @length_modifier: indicates the size or type of arguments that are expected
 * by the conversion specifier.
 * @buffer: A character array (or string) that serves as a temporary storage
 * location for formatted output. It is used to accumulate characters and data
 * before writing them to the final destination, such as a file or stdout.
 *
 * Description: A custom data structure that encapsulates formatting
 * information and context for a printf-like function. It includes fields for
 * flags, width, precision, size, variable arguments, buffer management, and
 * more, allowing for flexible text formatting and output handling
 */
typedef struct FormatContext
{
	int flags;
	int width;
	int precision;
	int size;
	int length_modifier;
	va_list args;
	size_t buf_index;
	char buffer[BUFSIZE]; /*Local buffer to minimize write calls*/
} FormatContext;

/**
 * struct specifier - specifier datatype
 * @fmt: format specifier
 * @func: format specifier handler
 *
 * Description: Holds specifier data and corresponding function
 */
typedef struct specifier
{
	char fmt;
	int (*func)(FormatContext *context);
} specifier;

int _printf(const char *format, ...);

FormatContext initialize_format_context(void);
void reset_flags_modifiers(FormatContext *context);
void *_memset(void *dest, int value, size_t block_size);
void write_buffer(char c, FormatContext *context);
int flush_buffer(FormatContext *context);
int (*get_specifier_func(char fmt))(FormatContext *context);
typedef int (*specifier_function)(FormatContext *context);

int parse_flags(const char fmt, FormatContext *context);
int parse_length_modifiers(const char fmt, FormatContext *context);
int parse_width(const char fmt, FormatContext *context);

int handle_character_specifier(FormatContext *context);
int handle_string_specifier(FormatContext *context);
int handle_integer_specifier(FormatContext *context);
int handle_binary_specifier(FormatContext *context);
int handle_mod_string_specifier(FormatContext *context);
int handle_mem_addr_specifier(FormatContext *context);
int handle_uint_specifier(FormatContext *context);
int handle_hexadecimal_specifier(FormatContext *context);
int handle_hexa_upper_specifier(FormatContext *context);
int handle_octal_specifier(FormatContext *context);
int handle_reverse_string_specifier(FormatContext *context);
int handle_rot13_string_specifier(FormatContext *context);

#endif /*MAIN_H*/

