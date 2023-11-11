#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

/* task 4 */
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

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

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* task 0 functions */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);

/* task 1 functions */
int print_int(va_list ap, params_t *params);

/* task 2 functions */
int print_binary(va_list ap, params_t *params);

/* task 3 functions */
int print_unsigned(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);

int _printf(const char *format, ...);
int _putchar(char c);

#endif
