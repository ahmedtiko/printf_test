#include "main.h"

/**
 * handle_print - Handles the printing of formatted output.
 * @format: Format string.
 * @ind: Pointer to the index in the format string.
 * @list: Variable argument list.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
                 int flags, int width, int precision, int size)
{
    int i;
    int un_len = 0;
    int print_char = -1;

    struct format
    {
        char fmt;
        int (*fn)(va_list, char[], int, int, int, int);
    };

    struct format format_types[] = {
        {'c', &print_char}, {'s', &print_string}, {'%', &print_percent},
        {'i', &print_int}, {'d', &print_int}, {'b', &print_binary},
        {'u', &print_unsigned}, {'o', &print_octal}, {'x', &print_hexadecimal},
        {'X', &print_hexa}, {'p', &print_pointer}, {'S', &print_non_printable},
        {'r', &print_reverse}, {'R', &print_rot13string}, {'\0', NULL}
    };

    for (i = 0; format_types[i].fmt != '\0'; i++)
    {
        if (format[*ind] == format_types[i].fmt)
        {
            return format_types[i].fn(list, buffer, flags, width, precision, size);
        }
    }

    /* Handle other cases here */
    if (format[*ind] == '\0')
    {
        return 0; /* End of format string */
    }
    else
    {
        buffer[0] = format[*ind];
        buffer[1] = '\0';
        return 1; /* Single character printed */
    }
}
