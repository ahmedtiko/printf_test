#include "main.h"
/**
 * is_printable - evaluates the char if it is printable
 * @c: char to be evaluated
 *
 * Return: 1 if c can be printed, 0 if not 
 */
int i_print(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}

/**
 * append_hexa_code - append ascci code in hexadecimal to buffer
 * @buffer: array of chars
 * @i: index to start append
 * @ascii_code: "ASSCI CODE" dec.
 * Return: always 3
 */
int ch_hex_code(char ascii_code, char buffer[], int i)
{
	char map[] = "0123456789ABCDEF";
	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map[ascii_code / 16];
	buffer[i] = map[ascii_code % 16];
	return (3);
}

/**
 * _digit - verifies if any char is a digit
 * @c: evaluate the char
 *
 * Return: 1 if c is a digit, 0 if not
 */
int _digit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size - casts a number to the required size
 * @num: casted num
 * @size: Num indicator to the type to be casted.
 *
 * Return: casted value of num
 */
long int conv_size(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * conv_size_unsigned - casts a number to the specified size
 * @num: casted num
 * @size: num indicator the type to be casted
 *
 * Return: casted value of num
 */
long int conv_size_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
