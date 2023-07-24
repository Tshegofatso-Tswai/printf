#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	unsigned int i = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			printed_chars++;
			i++;
		}
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		{
			printed_chars += print_integer(va_arg(args, int));
			i++;
		}
		else
		{
			_putchar('%');
			printed_chars++;
		}

		i++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * print_integer - Print an integer
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_integer(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_integer(num / 10);

	_putchar('0' + num % 10);
	count++;

	return (count);
}

