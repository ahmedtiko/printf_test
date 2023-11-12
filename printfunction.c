#include "main.h"
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
count = custom_printf(format, args);
va_end(args);
return count;
}
int custom_printf(const char *format, va_list args)
{
int count = 0;
char buffer[OUTPUT_BUF_SIZE];
int buf_index = 0;
while (*format)
{
if (*format == '%')
{
format++;
if (*format)
{
switch (*format)
{
case 'c':
count += print_char(args, NULL);
break;
case 's':
count += print_str(args, NULL);
break;
case '%':
count += print_percent(args, NULL);
break;
case 'd':
case 'i':
count += print_int(args, NULL);
break;
case 'b':
count += print_binary(args, NULL);
break;
case 'u':
count += print_unsigned(args, NULL);
break;
case 'o':
count += print_octal(args, NULL);
break;
case 'x':
count += print_hex(args, NULL);
break;
case 'X':
count += print_HEX(args, NULL);
break;
case 'S':
count += print_custom_str(args, NULL);
break;
case 'p':
count += print_pointer(args, NULL);
break;
case 'r':
count += print_reversed_str(args, NULL);
break;
case 'R':
count += print_rot13_str(args, NULL);
break;
/* Handle other cases as needed */
default:
_putchar('%');
_putchar(*format);
count += 2;
break;
}
}
}
else
{
count += _putchar(*format);
}
format++;
}
// Flush remaining buffer
if (buf_index > 0)
write(1, buffer, buf_index);
return count;
}
int _putchar(char c)
{
return write(1, &c, 1);
}
int handle_custom_specifiers(char specifier, va_list args, char buffer[], int *buf_index)
{
// Implement handling for custom specifiers
return 0;
}
int print_char(va_list args, params_t *params)
{
char c = va_arg(args, int);
return _putchar(c);
}
int print_str(va_list args, params_t *params)
{
char *str = va_arg(args, char *);
int count = 0;
if (str == NULL)
str = "(null)";
while (*str)
{
count += _putchar(*str);
str++;
}
return count;
}
int print_percent(va_list args, params_t *params)
{
(void)args; /* Unused parameter */
return _putchar('%');
}
int print_int(va_list args, params_t *params)
{
int n = va_arg(args, int);
int count = 0;
// Handle flags
if (params)
{
// Implement flag handling (if needed)
}
// Implement print_int logic here
char num_str[20];
int length = sprintf(num_str, "%d", n);
count += write_buffer(num_str, length);
return count;
}
int print_binary(va_list args, params_t *params)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
// Implement flag handling (if needed)
// Implement print_binary logic here
char binary_str[40];
int length = sprintf(binary_str, "%o", n);
count += write_buffer(binary_str, length);
return count;
}
int print_unsigned(va_list args, params_t *params)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
// Implement flag handling (if needed)
// Implement print_unsigned logic here
char unsigned_str[20];
int length = sprintf(unsigned_str, "%u", n);
count += write_buffer(unsigned_str, length);
return count;
}
int print_octal(va_list args, params_t *params)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
// Implement flag handling (if needed)
// Implement print_octal logic here
char octal_str[20];
int length = sprintf(octal_str, "%o", n);
count += write_buffer(octal_str, length);
return count;
}
int print_hex(va_list args, params_t *params)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
// Implement flag handling (if needed)
// Implement print_hex logic here
char hex_str[20];
int length = sprintf(hex_str, "%x", n);
count += write_buffer(hex_str, length);
return count;
}
int print_HEX(va_list args, params_t *params)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
// Implement flag handling (if needed)
// Implement print_HEX logic here
char HEX_str[20];
int length = sprintf(HEX_str, "%X", n);
count += write_buffer(HEX_str, length);
return count;
}
int print_custom_str(va_list args, params_t *params)
{
char *str = va_arg(args, char *);
int count = 0;
// Implement flag handling (if needed)
// Implement print_custom_str logic here
while (*str)
{
if (*str < 32 || *str >= 127)
{
count += _putchar('\\');
count += _putchar('x');
count += print_hex_char(*str);
}
else
{
count += _putchar(*str);
}
str++;
}
return count;
}
int print_pointer(va_list args, params_t *params)
{
void *ptr = va_arg(args, void *);
int count = 0;
// Implement flag handling (if needed)
// Implement print_pointer logic here
char ptr_str[20];
int length = sprintf(ptr_str, "%p", ptr);
count += write_buffer(ptr_str, length);
return count;
}
int print_reversed_str(va_list args, params_t *params)
{
char *str = va_arg(args, char *);
int count = 0;
// Implement flag handling (if needed)
// Implement print_reversed_str logic here
int len = 0;
while (str[len])
len++;
for (int i = len - 1; i >= 0; i--)
count += _putchar(str[i]);
return count;
}
int print_rot13_str(va_list args, params_t *params)
{
char *str = va_arg(args, char *);
int count = 0;
// Implement flag handling (if needed)

// Implement print_rot13_str logic here
while (*str)
{
if ((*str >= 'a' && *str <= 'm') || (*str >= 'A' && *str <= 'M'))
{
count += _putchar(*str + 13);
}
else if ((*str >= 'n' && *str <= 'z') || (*str >= 'N' && *str <= 'Z'))
{
count += _putchar(*str - 13);
}
else
{
count += _putchar(*str);
}
str++;
}
return count;
}
int write_buffer(const char *str, int length)
{
int count = 0;
for (int i = 0; i < length; i++)
{
count += _putchar(str[i]);
}
return count;
}
int print_hex_char(char c)
{
int count = 0;
char hex_chars[] = "0123456789ABCDEF";
count += _putchar(hex_chars[(c >> 4) & 0xF]);
count += _putchar(hex_chars[c & 0xF]);
return count;
}

