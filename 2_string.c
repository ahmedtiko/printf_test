#include "main.h"
/**
 * print_string - Print a string
 * @ap: va_list containing the string to print
 * @params: Additional parameters (if needed)
 *
 * Return: Number of characters printed
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char*);
	int count = 0;
if (str == NULL)
{
str = NULL_STRING;
}
while (*str)
{
_putchar(*str);
count++;
str++;
}
return (count);
}
