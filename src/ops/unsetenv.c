/*
** EPITECH PROJECT, 2021
** unsetenv.c
** File description:
** unsetenv
*/

#include "my.h"
#include "mysh1.h"

char **load_variable_name(char **env)
{
    int k = 0;
    int i = 0;
    char **variable_name;

    variable_name = init_variable_name(env);
    for (i = 0; env[i]; i++) {
        for (k = 0; env[i][k] != '='; k++)
            variable_name[i][k] = env[i][k];
        variable_name[i][k] = '\0';
    }
    return (variable_name);
}

int check_env(char **variable_name, char **command, int *k, int i)
{
    int indic = 0;

    for (k[0] = 0; my_strcmp(variable_name[k[0]], command[i]) != 0; k[0]++) {
        if (variable_name[k[0] + 1] == NULL) {
            indic = 1;
            break;
        }
    }
    return (indic);
}

char **remove_env(char **env, char **command)
{
    int k = 0;
    int i = 0;
    int indic = 0;
    char **variable_name;
    char **new_env = NULL;

    for (i = 1; command[i]; i++) {
        variable_name = load_variable_name(env);
        indic = check_env(variable_name, command, &k, i);
        if (indic == 0) {
            new_env = swap_to_the_end(env, k);
            env = new_env;
        }
        indic = 0;
        destroy_variable_name(variable_name);
    }
    if ((new_env = load_new_env(new_env, k, i)) != NULL)
        return (new_env);
    return (env);
}

char **unset_env(char **env, char **command)
{
    env = remove_env(env, command);
    return (env);
}

char **my_unsetenv(char **env, char **command)
{
    char **new_env;

    if (command[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return (env);
    }
    new_env = unset_env(env, command);
    return (new_env);
}