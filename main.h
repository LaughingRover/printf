#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct specifier - specifier datatype
 *
 * Description: Holds specifier data and corresponding function
 *
 * @c: format specifier
 * @func: format specifier handler
 */
typedef struct specifier
{
	char c;
	int (*func)(va_list args, int *num_of_printed_chars, char *buf_ptr);
} spec_t;

int is_flag(char);
int _putchar(char c);
int _printf(const char *format, ...);

int (*get_specifier_func(char fmt))(va_list, int *, char *);
typedef int (*specifier_function)(va_list, int *, char *);

int print_character(va_list args, int *num_of_printed_chars, char *buf_ptr);
int print_string(va_list args, int *num_of_printed_chars, char *buf_ptr);
int print_int(va_list args, int *num_of_printed_chars, char *buf_ptr);
int print_binary(va_list args, int *num_of_printed_chars, char *buf_ptr);
int print_mod_string(va_list args, int *num_of_printed_chars, char *buf_ptr);
int print_mem_address(va_list args, int *num_of_printed_chars, char *buf_ptr);

#endif /*MAIN_H*/

