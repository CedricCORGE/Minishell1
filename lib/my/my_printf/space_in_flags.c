/*
** EPITECH PROJECT, 2020
** space_in_flags.c
** File description:
** print and skip space in flags
*/

#include "../../../include/my.h"

int space_in_flags(char const *str, int i)
{
    while (str[i + 1] == ' ') {
        my_putchar(' ');
        i++;
    }
    return (i);
}