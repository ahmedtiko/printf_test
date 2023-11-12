#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#define OUTPUT_BUF_SIZE 1024
typedef struct params
{
unsigned int unsign : 1;
unsigned int plus_flag : 1;
unsigned int space_flag : 1;
unsigned int minus_flag : 1;
unsigned int zero_flag : 1;
unsigned int hashtag_flag : 1;
unsigned int width;
unsigned int precision;
unsigned int l_modifier : 1;
unsigned int h_modifier : 1;
} params_t;
int _printf(const char *format, ...);
int _putchar(char c);
int custom_printf(const char *format, va_list args);
int handle_custom_specifiers(char specifier, va_list args, char buffer[], int *buf_index);
int print_char(va_list args, params_t *params);
int print_str(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);
int print_int(va_list args, params_t *params);
int print_binary(va_list args, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);
int print_custom_str(va_list args, params_t *params);
int print_pointer(va_list args, params_t *params);
int print_reversed_str(va_list args, params_t *params);
int print_rot13_str(va_list args, params_t *params);

#endif /* MAIN_H */

