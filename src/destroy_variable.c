/*
** EPITECH PROJECT, 2021
** destroy_variable.c
** File description:
** destroy variable
*/

#include "mysh1.h"

void destroy_variable_name(char **variable_name)
{
    int i = 0;

    for (i = 0; variable_name[i]; i++)
        free(variable_name[i]);
    free(variable_name);
}