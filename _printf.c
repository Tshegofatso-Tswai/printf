#include "main.h"
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str_arg;
	char ch;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = va_arg(args, int);
					write(1, &ch, 1);
					count++;
					break;
				case 's':
					str_arg = va_arg(args, char *);
					if (str_arg == NULL)
						str_arg = "(null)";
					while (*str_arg != '\0')
					{
						write(1, str_arg, 1);
						str_arg++;
						count++;
					}
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
				default:
					write(1, format - 1, 2);
					count += 2;
					break;
			}
		}
		format++;
	}

	va_end(args);

	return (count);
}

