#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char);
void handle_specifier(char fmt, va_list args, int *num_of_printed_chars);
int dec_to_bin(int, int *num_of_printed_chars);

#endif /*MAIN_H*/

