#include "main.h"

/**
 * print_char - Print a character
 * @ap: va_list containing the character to print
 * @params: Additional parameters (if needed)
 *
 * Return: Number of characters printed
 */
int print_char(va_list ap, params_t *params)
{
	char c = va_arg(ap, int);
	/* Assuming _putchar is the function to print a character */
	return _putchar(c);
}
