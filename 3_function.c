#include "main.h"
/**
* print_char - prints char
* @types: List of args
* @buffer: buffer array 
* @flags: calculates active flags
* @width: Width
* @precision: precision specification
* @size: size specifier
* Return: Num of chars printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (hand_write_ch(c, buffer, flags, width, precision, size));
}
/**
* print_string - print string
* @types: list of args
* @flags: calculates active flags
* @width: Width
* @precision: precision specification
* @size: size specifier
* Return: Num char printed
*/
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int len = 0, i;
char *str = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
UNUSED(buffer);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
{
str = "      ";
}
}
while (str[len] != '\0')
{
len++;
}
if (precision >= 0 && precision < len)
{
len = precision;
}
if (width > len)
{
if (flags & FLAG_MINUS)
{
write(1, &str[0], len);
for (i = width - len; i > 0; i--)
{
write(1, " ", 1);
}
return (width);
}
else
{
for (i = width - len; i > 0; i--)
{
write(1, " ", 1);
}
write(1, &str[0], len);
return (width);
}
}
return (write(1, str, len));
}
/**
* print_percent - prints a percent %
* @types: list of args
* @buffer: buffer array to handle print
* @flags: calculates active flags
* @width: Width
* @precision: precision specification
* @size: size specifier
* Return: Num of chars printed
*/
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/**
* print_int - print int
* @types: list of arguments
* @buffer: buffer array to print
* @flags: calculates active flags
* @width: Width
* @precision: precision specification
* @size: size specifier
* Return: Num of chars printed
*/
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int n = va_arg(types, long int);
n = conv_size(n, size);
if (n < 0)
{
is_negative = 1;
n = -n;
}
while (n > 0)
{
buffer[i--] = (n % 10) + '0';
n /= 10;
}
i++;
return (write_num_0(is_negative, i, buffer, flags, width, precision, size));
}
/**
 * print_binary - prints an unsigned num in binary
 * @types: list of args
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: Width
 * @precision: precision specification
 * @size: size specifier
 * Return: Num of chars printed
 */
int print_binary(va_list types, char buffer[],
                 int flags, int width, int precision, int size)
{
    unsigned int m, i;
    unsigned int a[32];
    int count;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    m = va_arg(types, unsigned int);
    a[0] = m / 2147483648;
    count = a[0] != 0 ? 1 : 0;

    for (i = 1; i < 32; i++)
    {
        m /= 2;
        a[i] = (m / 2147483648) % 2;

        if (a[i] != 0 || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
    }

    return count;
}
