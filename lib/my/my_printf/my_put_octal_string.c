/*
** EPITECH PROJECT, 2020
** my_put_octal_string.c
** File description:
** display special case of octal
*/

#include "../../../include/my.h"
#include <stdarg.h>

int my_put_octal_nbr(int nb);

void my_put_octal_string(char const *str)
{
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] > 32 && str[index] < 127) {
            my_putchar(str[index]);
        }
        if (str[index] <= 32 || str[index] >= 127) {
            my_putchar('\\');
            if (str[index] < 8) {
                my_putchar('0');
                my_putchar('0');
            } else if (str[index] <= 32)
                my_putchar('0');
            my_put_octal_nbr(str[index]);
        }
        index++;
    }
}