#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @ind: Index.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: 1 or 2;
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, un_len = 0, print_char = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	for (i = 0; format_types[i].fmt != '\0'; i++)
	{
		if (format[*ind] == format_types[i].fmt)
		{
			return format_types[i].fn(list, buffer, flags, width, precision, size);
		}
	}

	if (format_types[i].fmt == '\0')
	{
		if (format[*ind] == '\0')
		{
			return -1;
		}

		un_len += write(1, "%%", 1);

		if (format[*ind - 1] == ' ')
		{
			un_len += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
			{
				--(*ind);
			}
			if (format[*ind] == ' ')
			{
				--(*ind);
			}
			return 1;
		}

		un_len += write(1, &format[*ind], 1);
		return un_len;
	}

	return print_char;
}
