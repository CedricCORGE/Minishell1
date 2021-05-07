/*
** EPITECH PROJECT, 2020
** my_put_hexa_nbr.c
** File description:
** diisplay number in hexa base
*/

#include "../../../include/my.h"
#include <stdlib.h>

int my_put_hexa_nbr(int nb)
{
    char *nb2 = malloc(sizeof(char) * 100);
    int i = 0;

    for (i = 0; nb > 15; i++) {
        nb2[i] = (nb % 16) + 48;
        if (nb2[i] > '9')
            nb2[i] = nb2[i] + 7;
        nb = nb / 16;
    }
    nb2[i] = (nb % 16) + 48;
    if (nb2[i] > '9')
            nb2[i] = nb2[i] + 7;
    my_revstr(nb2);
    my_putstr(nb2);
    free(nb2);
    return (0);
}

int my_put_lower_hexa_nbr(int nb)
{
    char *nb2 = malloc(sizeof(char) * 100);
    int i = 0;

    for (i = 0; nb > 15; i++) {
        nb2[i] = (nb % 16) + 48;
        if (nb2[i] > '9')
            nb2[i] = nb2[i] + 39;
        nb = nb / 16;
    }
    nb2[i] = (nb % 16) + 48;
    if (nb2[i] > '9')
            nb2[i] = nb2[i] + 39;
    my_revstr(nb2);
    my_putstr(nb2);
    free(nb2);
    return (0);
}

int my_put_hexa_address(long long nb)
{
    char *nb2 = malloc(sizeof(char) * 100);
    int i = 0;

    for (i = 0; nb > 15; i++) {
        nb2[i] = (nb % 16) + 48;
        if (nb2[i] > '9')
            nb2[i] = nb2[i] + 39;
        nb = nb / 16;
    }
    nb2[i] = (nb % 16) + 48;
    if (nb2[i] > '9')
            nb2[i] = nb2[i] + 39;
    my_revstr(nb2);
    my_putstr(nb2);
    free(nb2);
    return (0);
}

int my_put_address(void *nb)
{
    my_putstr("0x");
    my_put_hexa_address((long long) nb);
    return (0);
}
