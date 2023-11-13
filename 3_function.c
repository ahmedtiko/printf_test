/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array to handle print
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
    UNUSED(buffer);  // <-- Marking buffer as unused
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

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
