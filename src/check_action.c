/*
** EPITECH PROJECT, 2021
** check_action.c
** File description:
** check action
*/

#include "mysh1.h"
#include "my.h"

void destroy_command(char **command)
{
    for (int k = 0; command[k]; k++)
        free(command[k]);
    free(command);
}

int check_action(char *str)
{
    char **command = my_str_to_word_array(str);

    if (command[0] == 0)
        return (-1);
    char *ope[5] = {"cd", "setenv", "unsetenv", "env", "exit"};

    for (int i = 0; i < 5; i++) {
        if (my_strcmp(command[0], ope[i]) == 0) {
            destroy_command(command);
            return (0);
        }
    }
    destroy_command(command);
    return (-1);
}