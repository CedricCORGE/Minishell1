/*
** EPITECH PROJECT, 2020
** my_put_binary_number.c
** File description:
** display number in binary
*/

#include "../../../include/my.h"
#include <stdlib.h>

int my_put_binary_nbr(unsigned int nb)
{
    char *nb2 = malloc(sizeof(char) * 100);
    int i = 0;

    while (nb > 1) {
        nb2[i] = (nb % 2) + 48;
        nb = nb / 2;
        i++;
    }
    nb2[i] = (nb % 2) + 48;
    my_revstr(nb2);
    my_putstr(nb2);
    free(nb2);
    return (0);
}