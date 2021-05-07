/*
** EPITECH PROJECT, 2020
** my_put_long_nbr.c
** File description:
** display long number
*/

#include "../../../include/my.h"

int my_put_long_nbr(long nb)
{
    int nb2 = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }

    if (nb > 9) {
        my_put_long_nbr(nb / 10);
    }
    nb2 = nb % 10;
    my_putchar(nb2 + 48);
    return (0);
}

int my_put_unsigned_long_nbr(unsigned long nb)
{
    int nb2 = 0;

    if (nb > 9) {
        my_put_long_nbr(nb / 10);
    }
    nb2 = nb % 10;
    my_putchar(nb2 + 48);
    return (0);
}

int my_put_unsigned_longlong_nbr(unsigned long long nb)
{
    int nb2 = 0;

    if (nb > 9) {
        my_put_long_nbr(nb / 10);
    }
    nb2 = nb % 10;
    my_putchar(nb2 + 48);
    return (0);
}

int my_put_longlong_nbr(long long nb)
{
    int nb2 = 0;

    if (nb > 9)
        my_put_long_nbr(nb / 10);
    nb2 = nb % 10;
    my_putchar(nb2 + 48);
    return (0);
}