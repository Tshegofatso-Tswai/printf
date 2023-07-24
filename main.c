#include "main.h"

int main(void)
{
    int len;

    len = _printf("Hello, %s!\n", "World");
    _printf("Number of characters printed: %d\n", len);

    return (0);
}
