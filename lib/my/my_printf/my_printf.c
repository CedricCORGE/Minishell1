/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>

int my_put_binary_nbr(unsigned int nb);

int my_put_hexa_nbr(int nb);

int my_put_nbr(int nb);

int my_putstr(char const *str);

void my_putchar(char c);

int my_put_lower_hexa_nbr(int nb);

int my_put_hexa_address(long long nb);

int my_put_address(void *nb);

int my_put_octal_nbr(int nb);

int my_put_long_nbr(long nb);

int my_put_unsigned_long_nbr(unsigned long nb);

int my_put_unsigned_longlong_nbr(unsigned long long nb);

int my_put_longlong_nbr(long long nb);

void my_put_octal_string(char const *str);

int my_put_unsigned_int(unsigned int nb);

int space_in_flags(char const *str, int i);

int print_other_flags(char const *str, int i, va_list ap)
{
    if (str[i + 1] == 'b')
        my_put_binary_nbr(va_arg(ap, unsigned int));
    if (str[i + 1] == 'u')
        my_put_unsigned_int(va_arg(ap, unsigned int));
    if (str[i + 1] == 'p')
        my_put_address(va_arg(ap, void *));
    return (i);
}

int print_long_flags(const char *str, int i, va_list ap)
{
    switch (str[i + 1]) {
        case 'l':
            if (str[i + 2] == 'd')
                my_put_long_nbr(va_arg(ap, long));
            if (str[i + 2] == 'u')
                my_put_unsigned_long_nbr(va_arg(ap, unsigned long));
            if (str[i + 2] == 'l' && str[i + 3] == 'd')
                my_put_longlong_nbr(va_arg(ap, long long));
            if (str[i + 2] == 'l' && str[i + 3] == 'u')
                my_put_unsigned_longlong_nbr(va_arg(ap, unsigned long long));
            break;
        default:
            i = print_other_flags(str, i, ap);
            break;
    }
    if (str[i + 2] == 'd' || str[i + 2] == 'u')
        i++;
    if (str[i + 3] == 'u' || str[i + 3] == 'd')
        i = i + 2;
    return (i);
}

int print_conversion_flags(const char *str, int i, va_list ap)
{
    switch (str[i + 1]) {
        case 'o':
            my_put_octal_nbr(va_arg(ap, int));
            break;
        case 'x':
            my_put_lower_hexa_nbr(va_arg(ap, int));
            break;
        case 'X':
            my_put_hexa_nbr(va_arg(ap, int));
            break;
        case 'S':
            my_put_octal_string(va_arg(ap, char *));
            break;
        default:
            i = print_long_flags(str, i, ap);
            break;
    }
    return (i);
}

int print_basic_flags(const char *str, int i, va_list ap)
{
    switch (str[i + 1]) {
        case 'c':
            my_putchar((char) va_arg(ap, int));
            break;
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        default:
            i = print_conversion_flags(str, i, ap);
            break;
    }
    i++;
    return (i);
}

int my_printf(const char *str, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, str);
    while (str[i] != '\0') {
        if (str[i] == '%' && str[i + 1] == '%')
            my_putchar('%');
        if (str[i] == '%') {
            i = space_in_flags(str, i);
            i = print_basic_flags(str, i, ap);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    va_end(ap);
    return (0);
}
