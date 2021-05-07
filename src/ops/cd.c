/*
** EPITECH PROJECT, 2021
** cd.c
** File description:
** cd
*/

#include "my.h"
#include "mysh1.h"

void copy_oldpwd(char **env, int i, char *stock)
{
    int index = 0;

    for (int k = 7; env[i][k]; k++, index++) {
        stock[index] = env[i][k];
    }
    stock[index] = '\0';
}

void cd_past(char **env)
{
    int i = 0;
    char *stock = NULL;

    for (i = 0; env[i]; i++) {
        if (env[i][0] == 'O' && env[i][1] == 'L' && \
env[i][2] == 'D' && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D') {
            stock = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
            copy_oldpwd(env, i, stock);
        }
        if (env[i + 1] == NULL && !(env[i][0] == 'O' && env[i][1] == 'L' && \
env[i][2] == 'D' && env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D')) {
            my_printf(": No such file or directory\n");
            break;
        }
    }
    chdir(stock);
    free(stock);
}

void cd_home(char **env)
{
    char *stock = NULL;
    char *home = NULL;
    int i = 0;

    for (i = 0; env[i]; i++)
        if (env[i][0] == 'H' && env[i][1] == 'O' && \
env[i][2] == 'M' && env[i][3] == 'E') {
            stock = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
            stock[0] = '\0';
            my_strcat(stock, env[i]);
        }
    for (i = 0; stock[i] != '='; i++);
    i++;
    home = malloc(sizeof(char) * (my_strlen(stock) - i));
    for (int k = 0; stock[i]; i++, k++)
        home[k] = stock[i];
    if (chdir(home) == -1)
        my_printf("Can't access to home directory");
    free(home);
    free(stock);
}

int is_full_path(char **command)
{
    if (chdir(command[1]) == -1)
        return (1);
    else
        return (0);
}

char **my_cd(char **env, char **command)
{
    char **tab = NULL;
    char **new_env = NULL;

    tab = update_pwd();
    new_env = do_cd(env, command, tab);
    if (new_env != NULL)
        return (new_env);
    error_cd(command, env, tab);
    return (env);
}
