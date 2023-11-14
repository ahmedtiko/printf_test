#include "main.h"
void print_buffer(char buffer[], int *buff_index);
/**
* _printf - printf function
* @format: format.
* Return: printed character.
*/
int _printf(const char *format, ...)
{
int i, pr = 0, pr_chars = 0;
int flags, width, precision, size, buff_index = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
{
return (-1);
}
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_index++] = format[i];
if (buff_index == BUFF_SIZE)
{
print_buffer(buffer, &buff_index);
}
pr_chars++;
}
else
{
print_buffer(buffer, &buff_index);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
pr = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (pr == -1)
{
return (-1);
}
pr_chars += pr;
}
}
print_buffer(buffer, &buff_index);
va_end(list);
return (pr_chars);
}
/**
* print_buffer - prints the contents of the buffer
* @buffer: array of character
* @buff_index: index represents the length.
*/
void print_buffer(char buffer[], int *buff_index)
{
if (*buff_index > 0)
{
write(1, &buffer[0], *buff_index);
}
*buff_index = 0;
}
