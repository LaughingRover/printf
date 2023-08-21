#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char);
void handle_specifier(char fmt,
		int *num_of_printed_chars, va_list args, char buffer[]);
int dec_to_bin(int, int *num_of_printed_chars);
void print_mod_string(char *str, int *num_of_printed_chars, char buffer[]);
void print_string(char *str, int *num_of_printed_chars, char buffer[]);
void print_int(int num, int *num_of_printed_chars, char buffer[]);
void print_mem_address(void *addr, int *num_of_printed_chars, char buffer[]);

#endif /*MAIN_H*/

