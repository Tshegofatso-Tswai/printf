#include "main.h"
<<<<<<< HEAD
#include <stddef.h>
=======
#include <stdarg.h>
#include <unistd.h> /* for write */
>>>>>>> 5048d1c6c2bd24e7d12917158cfcf5b21b3fbd42

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing directives.
 *
<<<<<<< HEAD
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
=======
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
>>>>>>> 5048d1c6c2bd24e7d12917158cfcf5b21b3fbd42
}
