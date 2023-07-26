#include "main.h"
#include <stddef.h>

/**
 * print_string - Prints a string to the standard output.
 * @args: The list of arguments.
 * 
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len] != '\0')
	{
		_putchar(str[len]);
		len++;
	}

	return (len);
}

