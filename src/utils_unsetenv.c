/*
** EPITECH PROJECT, 2021
** utils_unsetenv.c
** File description:
** utils for unsetenv
*/

#include "my.h"
#include "mysh1.h"

int get_max_length(char **env)
{
    int max_length = 0;

    for (int i = 0; env[i]; i++) {
        if (my_strlen(env[i]) > max_length)
            max_length = my_strlen(env[i]);
    }
    return (max_length);
}

char **load_new_env(char **new_env, int k, int i)
{
    if (new_env != NULL) {
        for (k = 0; new_env[k]; k++);
        new_env[k - (i - 1)] = NULL;
        return (new_env);
    }
    return (NULL);
}

char **init_variable_name(char **env)
{
    char **variable_name;
    int i = 0;

    for (i = 0; env[i]; i++);
    variable_name = malloc(sizeof(char *) * (i + 1));
    for (i = 0; env[i]; i++) {
        variable_name[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
    }
    variable_name[i] = NULL;
    return (variable_name);
}

char **init_swap_tab(char **env, int max_length, int k)
{
    int i = 0;
    char **swap_tab;

    for (i = 0; env[i]; i++);
    swap_tab = malloc(sizeof(char *) * (i + 1));
    for (i = 0; env[i]; i++) {
        swap_tab[i] = malloc(sizeof(char) * (max_length + 1));
    }
    for (i = 0; env[i]; i++) {
        my_strcpy(swap_tab[i], env[i]);
    }
    swap_tab[i] = NULL;
    return (swap_tab);
}

char **swap_to_the_end(char **env, int k)
{
    char *stock;
    int max_length = get_max_length(env);
    int i = 0;
    char **swap_tab = init_swap_tab(env, max_length, k);

    for (; env[k + 1]; k++) {
        stock = my_strdup(env[k + 1]);
        my_strcpy(swap_tab[k + 1], swap_tab[k]);
        my_strcpy(swap_tab[k], stock);
        free(stock);
    }
    for (i = 0; env[i]; i++)
        free(env[i]);
    free(env);
    return (swap_tab);
}