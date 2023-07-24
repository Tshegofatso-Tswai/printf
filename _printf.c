#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - Print data to the standard output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings), or -1 on error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed_chars = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else if (format[i] == '%' && format[i + 1])
		{
			i++;
			switch (format[i])
			{
				case 'c':
					printed_chars += print_char(args);
					break;
				case 's':
					printed_chars += print_string(args);
					break;
				case 'b':
					printed_chars += print_binary(args);
					break; // Don't forget to break after each case
				default:
					_putchar('%');
					_putchar(format[i]);
					printed_chars += 2;
			}
		}
		i++;
	}

	va_end(args);
	return (printed_chars);
}
