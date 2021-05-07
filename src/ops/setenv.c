/*
** EPITECH PROJECT, 2021
** setenv.c
** File description:
** set env
*/

#include "my.h"
#include "mysh1.h"

char **my_realloc(char **env, int len_stock)
{
    int i = 0;
    int k = 0;
    char **new_env;
    int max_length = get_max_length(env);

    for (i = 0; env[i]; i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    for (k = 0; env[k]; k++)
        new_env[k] = malloc(sizeof(char) * (max_length + 1));
    new_env[k] = malloc(sizeof(char) * (max_length + 1));
    new_env[k + 1] = NULL;
    for (i = 0; i < k; i++) {
        my_strcpy(new_env[i], env[i]);
        new_env[i][my_strlen(env[i])] = '\0';
    }
    return (new_env);
}

int check_variable(char **variable)
{
    int i = 0;

    for (i = 0; variable[i]; i++);
    return (i);
}

char **setenv1(char **env, char **variable)
{
    int len_variable = (my_strlen(variable[1]) + 1);
    int i = 0;
    char **new_env = my_realloc(env, len_variable + 1);

    for (i = 0; env[i]; i++);
    new_env[i][0] = '\0';
    my_strcat(new_env[i], variable[1]);
    my_strcat(new_env[i], "=");
    new_env[i][len_variable] = '\0';
    for (i = 0; env[i]; i++) {
        free(env[i]);
    }
    free(env);
    return (new_env);
}

char **setenv2(char **env, char **variable)
{
    int i = 0;
    int len_variable = (my_strlen(variable[1]) + my_strlen(variable[2]) + 1);
    char **new_env;

    new_env = my_realloc(env, len_variable + 1);
    for (i = 0; env[i]; i++);
    new_env[i][0] = '\0';
    my_strcat(new_env[i], variable[1]);
    my_strcat(new_env[i], "=");
    my_strcat(new_env[i], variable[2]);
    new_env[i][len_variable] = '\0';
    for (i = 0; env[i]; i++) {
        free(env[i]);
    }
    free(env);
    return (new_env);
}

char **my_setenv(char **env, char **variable)
{
    char **new_env;
    int indic = check_variable(variable);

    if (check_variable_name(variable, indic) == 1)
        return (env);
    if (indic < 2) {
        my_env(env);
        return (env);
    } else if (indic > 3) {
        my_printf("setenv: Too many arguments.\n");
        return (env);
    }
    if (indic == 2) {
        new_env = setenv1(env, variable);
    } else
        new_env = setenv2(env, variable);
    for (int i = 0; variable[i]; i++)
        free(variable[i]);
    free(variable);
    return (new_env);
}