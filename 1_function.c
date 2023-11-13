#include "main.h"
/*PRINT UNSIGNED NUM*/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	num = conv_size_unsigned(num, size);
	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/* PRINT UNSIGNED NUM IN OCTAL **/
/**
 * print_octal - Prints an unsigned number in octal
 * @types: list of args
 * @buffer: buffer array to handle print
 * @flags:  calculates the active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numb of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	UNUSED(width);
	num = conv_size_unsigned(num, size);
	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & FLAG_HASH && init_num != 0)
	{
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*PRINT UNSIGNED NUM IN HEXA*/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal
 * @types: list of args
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Num of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
/*PRINT UNSIGNED NUM IN UPPER HEXADECIMAL */
/**
 * print_HEXA - print an unsigned number in upper hexadecimal
 * @types: list of args
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Num of chars printed
 */
int print_HEXA(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - prints a hexadecimal number lower or upper
 * @types: list of args
 * @map_to: array of values that map the num to
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @flag_ch: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * @size: size specification
 * Return: Num of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;
	UNUSED(width);
	num = conv_size_unsigned(num, size);
	if (num == 0)
	{
		buffer[i--] = '0';
	}
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & FLAG_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
