/*
** EPITECH PROJECT, 2021
** utils_setenv.c
** File description:
** utils for setenv
*/

#include "my.h"
#include "mysh1.h"

int check_first_letter(char **variable)
{
    if ((variable[1][0] < 'a' || variable[1][0] > 'z') && \
(variable[1][0] < 'A' || variable[1][0] > 'Z')) {
        my_printf("setenv: Variable name must begin with a letter\n");
        return (1);
    }
    return (0);
}

int check_variable_name(char **variable, int indic)
{
    if (indic == 1)
        return (0);
    if (check_first_letter(variable) == 1)
        return (1);
    for (int i = 0; variable[1][i]; i++)
        if (my_str_isalpha(variable[1]) != 1 && \
my_str_isnum(variable[1]) != 1) {
            my_printf("setenv: Variable name must contain \
alphanumeric characters.\n");
            return (1);
        }
    if (indic == 3)
        for (int i = 0; variable[2][i]; i++)
            if (my_str_isalpha(variable[2]) != 1 && \
my_str_isnum(variable[2]) != 1) {
                my_printf("setenv: Variable name must contain \
alphanumeric characters.\n");
                return (1);
            }
    return (0);
}