#include "main.h"

/**
 * print_binary - Custom function to print an unsigned int in binary
 * @args: The va_list containing the unsigned int to print
 *
 * Return: The number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int printed_chars = 0;

    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
    }
    else
    {
        int bin_digits[32];
        int i = 0;

        while (num > 0)
        {
            bin_digits[i] = num % 2;
            num = num / 2;
            i++;
        }

        for (i = i - 1; i >= 0; i--)
        {
            _putchar(bin_digits[i] + '0');
            printed_chars++;
        }
    }

    return (printed_chars);
}

