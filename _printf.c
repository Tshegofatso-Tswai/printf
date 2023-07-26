#include "main.h"
#include <stddef.h> /* Add this line to include the NULL definition */

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int i = 0, j = 0, printed_chars = 0;
    va_list args;
    format_func_t formats[] = {
        {'c', print_char},
        {'s', print_string},
        {'b', print_binary}, /* Custom conversion specifier for binary */
        {'\0', NULL}
    };

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            _putchar(format[i]);
            printed_chars++;
        }
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            _putchar('%');
            printed_chars++;
            i++;
        }
        else
        {
            j = 0;
            while (formats[j].type != '\0')
            {
                if (formats[j].type == format[i + 1])
                {
                    printed_chars += formats[j].func(args);
                    break;
                }
                j++;
            }
            i++;
        }
        i++;
    }

    va_end(args);
    return (printed_chars);
}

