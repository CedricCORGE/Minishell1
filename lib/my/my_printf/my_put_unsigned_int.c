/*
** EPITECH PROJECT, 2020
** my_put_unsigned_int.c
** File description:
** print unsigned int
*/

#include "../../../include/my.h"

int my_put_unsigned_int(unsigned int nb)
{
    int nb2 = 0;

    if (nb > 9) {
        my_put_unsigned_int(nb / 10);
    }
    nb2 = nb % 10;
    my_putchar(nb2 + 48);
}
