/*
** EPITECH PROJECT, 2020
** my_puterror.c
** File description:
** print on error output
*/

#include "../../include/my.h"
#include <unistd.h>

int my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
    return (0);
}