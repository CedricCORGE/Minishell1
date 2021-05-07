/*
** EPITECH PROJECT, 2020
** my_put_octal_nbr.c
** File description:
** display octal number
*/

#include "../../../include/my.h"
#include <stdlib.h>

int my_put_octal_nbr(int nb)
{
    char *nb2 = malloc(sizeof(char) * 100);
    int i = 0;

    while (nb > 7) {
        nb2[i] = (nb % 8) + 48;
        nb = nb / 8;
        i++;
    }
    nb2[i] = (nb % 8) + 48;
    my_revstr(nb2);
    my_putstr(nb2);
    free(nb2);
    return (0);
}