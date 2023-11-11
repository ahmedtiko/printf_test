#include "main.h"
/**
 * print_percent - Print a percentage sign
 * @ap: va_list (unused)
 * @params: Additional parameters (if needed)
 *
 * Return: Number of characters printed (1 for '%')
 */
int print_percent(va_list ap, params_t *params)
{
(void)ap;  /* Unused parameter */
_putchar('%');
return 1;
}
