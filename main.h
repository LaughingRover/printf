#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BUFSIZE (1024)
#define UNUSED(x) (void)(x)

/**
 * struct specifier - specifier datatype
 *
 * Description: Holds specifier data and corresponding function
 *
 * @fmt: format specifier
 * @func: format specifier handler
 */
struct specifier
{
	char fmt;
	int (*func)(va_list args, char buffer[], size_t *buf_index);
};

typedef struct specifier spec_t;

int is_flag(char);
int _putchar(char c);
int _printf(const char *format, ...);

void *_memset(void *dest, int value, size_t block_size);
void write_buffer(char c, char buffer[], size_t *buf_index);
int flush_buffer(char buffer[], size_t *buf_index);

int (*get_specifier_func(char fmt))(va_list args, char [], size_t *);
typedef int (*specifier_function)(va_list args, char [], size_t *);

int handle_character_specifier(va_list args, char buffer[], size_t *buf_index);
int handle_string_specifier(va_list args, char buffer[], size_t *buf_index);
int handle_integer_specifier(va_list args, char buffer[], size_t *buf_index);
int handle_binary_specifier(va_list args, char buffer[], size_t *buf_index);
int handle_mod_string_specifier(va_list args, char buffer[],
		size_t *buf_index);
int handle_mem_addr_specifier(va_list args, char buffer[], size_t *buf_index);
int handle_unint_specifier(va_list args, char buffer[], size_t *buf_index);
int handle_hexadecimal_specifier(va_list args, char buffer[], size_t *buf_index);
int handle_hexa_upper_specifier(va_list args, char buffer[], size_t *buf_index);
int handle_octal_specifier(va_list args, char buffer[], size_t *buf_index);

#endif /*MAIN_H*/
