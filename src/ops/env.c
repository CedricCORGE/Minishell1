/*
** EPITECH PROJECT, 2021
** env.c
** File description:
** env
*/

#include "my.h"

void my_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        my_printf("%s\n", env[i]);
    }
}