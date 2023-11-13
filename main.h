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
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* +, -, 0, #, space FLAGS */
#define FLAG_MINUS  (1 << 0)
#define FLAG_PLUS   (1 << 1)
#define FLAG_ZERO   (1 << 2)
#define FLAG_HASH   (1 << 3)
#define FLAG_SPACE  (1 << 4)
/* Long and short SIZES */
#define S_LONG  2
#define S_SHORT 1
/**
 * struct format - to hold format specifiers
 *
 * @fmt: format specifier.
 * @fn: associated function.
 */
typedef struct format
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
} format_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
/* Fns 4 printing string */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* Fns 4 printing numbers */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_HEXA(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size);
/* Fn 2 print unprintable characters */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* Fn 2 print memory address */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* Fn 4 handling other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
/* Fn 2 print string in reverse */
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* Fn 2 print a string in ROT13 */
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* prototypes 4 handling width */
int hand_write_ch(char c, char buffer[],
int flags, int width, int precision, int size);
int write_num_0(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);
/*util*/
int i_print(char);
int ch_hex_code(char, char[], int);
int _digit(char);
long int conv_size(long int num, int size);
long int conv_size_unsigned(unsigned long int num, int size);
#endif
