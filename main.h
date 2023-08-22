#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFSIZE (1024)

/**
 * struct specifier - specifier datatype
 *
 * Description: Holds specifier data and corresponding function
 *
 * @c: format specifier
 * @func: format specifier handler
 */
struct specifier
{
	char fmt;
	int (*func)(va_list args, int *num_of_printed_chars, char *buf_ptr);
};

typedef struct specifier spec_t;

int is_flag(char);
int _putchar(char c);
int _printf(const char *format, ...);

int (*get_specifier_func(char fmt))(va_list, int *, char *);
typedef int (*specifier_function)(va_list, int *, char *);

int handle_character_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr);
int handle_string_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr);
int handle_integer_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr);
int handle_binary_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr);
int handle_mod_string_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr);
int handle_mem_addr_specifier(va_list args, int *num_of_printed_chars,
							char *buf_ptr);

#endif /*MAIN_H*/

