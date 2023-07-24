#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of printf function
 * @format: The format string containing directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int len = 0;
    int printed_chars = 0;
    char ch;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    for (len = 0; format[len] != '\0'; len++)
    {
        if (format[len] != '%')
        {
            putchar(format[len]);
            printed_chars++;
        }
        else
        {
            len++;
            ch = format[len];
            switch (ch)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    printed_chars++;
                    break;

                case 's':
                    printed_chars += print_string(va_arg(args, char *));
                    break;

                case '%':
                    putchar('%');
                    printed_chars++;
                    break;

                default:
                    putchar('%');
                    putchar(ch);
                    printed_chars += 2;
                    break;
            }
        }
    }

    va_end(args);

    return (printed_chars);
}

/**
 * print_string - Helper function to print a string
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
    int len = 0;

    if (str == NULL)
    {
        str = "(null)";
    }

    while (*str != '\0')
    {
        putchar(*str);
        str++;
        len++;
    }

    return (len);
}

