/*
** EPITECH PROJECT, 2021
** utils_my_exec.c
** File description:
** utils for my_exec
*/

#include "mysh1.h"
#include "my.h"

int get_path_index(char **env)
{
    int i = 0;

    for (i = 0; (env[i][0] != 'P' || env[i][1] != 'A' \
|| env[i][2] != 'T' || env[i][3] != 'H'); i++) {
        if (env[i + 1] == NULL)
            return (-1);
    }
    return (i);
}

char *find_variable(char **tab, char *exec)
{
    int i = 0;
    char *stock = NULL;
    char *binary_name = malloc(sizeof(char) * (my_strlen(exec) + 1));

    if (access(exec, X_OK) == 0)
        return (exec);
    if (binary_exec(exec, binary_name) != NULL)
        return (binary_name);
    for (i = 0; tab[i]; i++) {
        stock = malloc(sizeof(char) * \
(my_strlen(tab[i]) + my_strlen(exec) + 2));
        stock[0] = '\0';
        my_strcat(stock, tab[i]);
        my_strcat(stock, "/");
        my_strcat(stock, exec);
        if (access(stock, X_OK) == 0)
            return (stock);
        free(stock);
    }
    return (NULL);
}

char *get_path(char **env, char *exec)
{
    int path_index = get_path_index(env);
    if (path_index == -1)
        return (NULL);
    char *path_variable = malloc(sizeof(char) * \
(my_strlen(env[path_index]) + 1));
    int j = 0;
    char **tab;
    char *valide_path;

    for (int k = 5; env[path_index][k]; k++, j++) {
        path_variable[j] = env[path_index][k];
    }
    path_variable[j] = '\0';
    tab = my_str_to_word_array(path_variable);
    valide_path = find_variable(tab, exec);
    free(path_variable);
    if (valide_path == NULL)
        return (NULL);
    return (valide_path);
}

void wait_end_exec(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    if (WTERMSIG(status)) {
        if (WTERMSIG(status) == 8)
            my_printf("Floating exception\n");
        else
            my_printf("%s\n", strsignal(WTERMSIG(status)));
    }
}