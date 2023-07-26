#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Struct to store format flags */
typedef struct format_flags
{
	char specifier;
	int (*print_fn)(va_list args);
	int width;
	int precision;
	int left_align;
	int show_sign;
	int space_flag;
	int hash_flag;
	int zero_flag;
} format_flags_t;

/* Custom conversion specifiers */
int print_binary(va_list args);

/* Function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_integer(int n);
int print_unsigned(va_list args, format_flags_t *flags);
int print_binary(va_list args);
int print_octal(va_list args, format_flags_t *flags);
int print_hex(va_list args, format_flags_t *flags);
int print_hex_upper(va_list args, format_flags_t *flags);
int print_pointer(va_list args, format_flags_t *flags);
int print_reverse(va_list args, format_flags_t *flags);
int print_rot13(va_list args, format_flags_t *flags);

typedef struct format_func
{
    char type;
    int (*func)(va_list);
} format_func_t;

#endif
