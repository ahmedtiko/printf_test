#include "main.h"
/**
* handle_print - handling the printed format output
* @format: string format
* @ind: pointer of the index in the format string
* @list: variable arg list
* @buffer: buffer the array to handle print
* @flags: active flags
* @width: Width specifier
* @precision: precision specifier
* @size: size specifier
*
* Return: num of chars printed
*/
int handle_print(const char *format, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int i;
struct format /*struct */
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};
struct format format_types[] = {
{'c', &print_char}, {'s', &print_string}, {'%', &print_percent},
{'i', &print_int}, {'d', &print_int}, {'b', &print_binary},
{'u', &print_unsigned}, {'o', &print_octal}, {'x', &print_hexadecimal},
{'X', &print_HEXA}, {'p', &print_pointer}, {'S', &print_non_printable},
{'r', &print_reverse}, {'R', &print_rot13string}, {'\0', NULL}
};
for (i = 0; format_types[i].fmt != '\0'; i++)
{
if (format[*ind] == format_types[i].fmt)
{
return (format_types[i].fn(list, buffer, flags, width, precision, size));
}
}
if (format[*ind] == '\0')
{
return (0);
}
else
{
buffer[0] = format[*ind];
buffer[1] = '\0';
return (1);
}
}
