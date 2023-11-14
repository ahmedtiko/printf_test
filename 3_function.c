#include "main.h"
/**
* print_char - Prints a char
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char c = va_arg(types, int);
return (hand_write_ch(c, buffer, flags, width, precision, size));
}
/**
* print_string - Prints a string
* @types: List of arguments
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
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
* print_percent - Prints a percent sign
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
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
* print_int - Print int
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
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
* print_binary - Prints an unsigned number
* @types: List of arguments
* @buffer: Buffer array to handle print
* @flags: Calculates active flags
* @width: Width
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int m, i, sum;
unsigned int a[32];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
m = va_arg(types, unsigned int);
a[0] = m / 2147483648;
for (i = 1; i < 32; i++)
{
m /= 2;
a[i] = (m / 2147483648) % 2;
}
for (i = 0, sum = 0, count = 0; i < 32; i++)
{
sum += a[i];
if (sum || i == 31)
{
char z = '0' + a[i];
write(1, &z, 1);
count++;
}
}
return (count);
}
