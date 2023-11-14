#include "main.h"
/**
* hand_write_ch - handles writing chars for width formatting
* @c: char to be written
* @buffer: buffer array to handle print
* @flags: calculates active flags
* @width: Width
* @precision: precision specification.
* @size: size specifier.
* Return: num of chars printed
*/
int hand_write_ch(char c, char buffer[],
int flags, int width, int precision, int size)
{
int i, index = 0;
char padding = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & FLAG_ZERO)
{
padding = '0';
}
if (width > 1)
{
for (i = 0; i < width - 1; i++)
{
buffer[index++] = padding;
if (index == BUFF_SIZE - 1)
{
write(1, &buffer[0], index);
index = 0;
}
}
}
buffer[index++] = c;
buffer[index] = '\0';
while (index < width)
{
write(1, &padding, 1);
index++;
}
return (index);
}
/**
* write_num_0 - write number with special conditions
* @is_positive: indicates if the number is positive
* @ind: index at which the number starts in the buffer
* @buffer: buffer
* @flags: flags
* @width: Width
* @precision: precision specifier
* @size: size specifier
* Return: num of chars printed
*/
int write_num_0(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int len = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
{
padd = '0';
}
if (is_positive)
{
extra_ch = '+';
}
else if (flags & FLAG_PLUS)
{
extra_ch = '+';
}
else if (flags & FLAG_SPACE)
{
extra_ch = ' ';
}
return (write_num(ind, buffer, flags, width, precision, len, padd, extra_ch));
}
/**
* write_num - write num using buffer
* @ind: index which the num starts the buffer
* @buffer: buffer
* @flags: flags
* @width: Width
* @prec: precision specifier
* @length: num length
* @padd: padding char
* @extra_c: extra char
* Return: num of printed chars.
*/
int write_num(int ind, char buffer[], int flags, int width,
int prec, int length, char padd, char extra_c)
{
int i, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
{
    return (0);
}
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
{
    buffer[ind] = padd = ' ';
}
if (prec > 0 && prec > length)
{
    padd = ' ';
}
while (prec > length)
{
    buffer[--ind] = '0';
    length++;
}
if (extra_c != 0)
{
length++;
}
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
{
buffer[i] = padd;
}
buffer[i] = '\0';
if (flags & FLAG_MINUS && padd == ' ')
{
if (extra_c)
{
buffer[--ind] = extra_c;
}
return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
}
else if (!(flags & FLAG_MINUS) && padd == ' ')
{
if (extra_c)
{
buffer[--ind] = extra_c;
}
return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & FLAG_MINUS) && padd == '0')
{
if (extra_c)
{
buffer[--padd_start] = extra_c;
}
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start)));
}
}
if (extra_c)
{
buffer[--ind] = extra_c;
}
return (write(1, &buffer[ind], length));
}
/**
* write_unsgnd - Writes an unsigned number.
* @is_negative: Number indicating if the num is negative.
* @ind: Index at which the number starts in the buffer.
* @buffer: Array of chars.
* @flags: Flags specifiers.
* @width: Width specifier.
* @precision: Precision specifier.
* @size: Size specifier.
* Return: Number of written chars.
*/
int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int len = BUFF_SIZE - ind - 1, i = 0;
char padd = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
{
return (0); /* printf(".0d", 0)  no char is printed */
}
if (precision > 0 && precision < len)
{
padd = ' ';
}
while (precision > len)
{
buffer[--ind] = '0';
len++;
}
if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
{
padd = '0';
}
if (width > len)
{
for (i = 0; i < width - len; i++)
{
buffer[i] = padd;
}
buffer[i] = '\0';
if (flags & FLAG_MINUS)
{
return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
}
else /* Asign extra char to left of padding [padd>buffer]*/
{
return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
}
}
return (write(1, &buffer[ind], len));
}
/**
* write_pointer - Write a memory address.
* @buffer: Arrays of chars.
* @ind: Index at which the number starts in the buffer.
* @length: Length of number.
* @width: Width specifier.
* @flags: Flags specifier.
* @padd: Char representing the padding.
* @extra_c: Char representing extra char.
* @padd_start: Index at which padding should start.
* Return: number of written char
*/
int write_pointer(char buffer[], int ind, int length, int width,
int flags, char padd, char extra_c, int padd_start)
{
int i;
if (width > length)
{
for (i = 3; i < width - length + 3; i++)
{
buffer[i] = padd;
}
buffer[i] = '\0';
if (flags & FLAG_MINUS && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
{
buffer[--ind] = extra_c;
}
return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
}
else if (!(flags & FLAG_MINUS) && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
{
buffer[--ind] = extra_c;
}
return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
}
else if (!(flags & FLAG_MINUS) && padd == '0')
{
if (extra_c)
{
buffer[--padd_start] = extra_c;
}
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], i - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
{
buffer[--ind] = extra_c;
}
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
