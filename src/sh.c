/*
** EPITECH PROJECT, 2021
** sh.c
** File description:
** sh
*/

#include "my.h"
#include "mysh1.h"

char **copy_env(char **env)
{
    int i = 0;
    char **env_copy;

    for (i = 0; env[i]; i++);
    env_copy = malloc(sizeof(char *) * (i + 1));
    for (i = 0; env[i]; i++) {
        env_copy[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        my_strcpy(env_copy[i], env[i]);
    }
    env_copy[i] = NULL;
    return (env_copy);
}

void destroy_env(char **env)
{
    for (int i = 0; env[i]; i++) {
        free(env[i]);
    }
    free(env);
}

void display_fail(char *str)
{
    str[my_strlen(str) - 1] = '\0';
    my_printf("%s: Command not found.\n", str);
}

int sh(int ac, char **av, char **env)
{
    char *str = NULL;
    size_t n = 0;

    while (1) {
        if (isatty(0))
                my_printf("$> ");
        if (getline(&str, &n, stdin) == -1)
            return (0);
        if (check_action(str) == -1) {
            if (my_exec(env, str) == -1)
                display_fail(str);
        } else {
            env = call_builtins(str, env);
        }
        if (my_strcmp(str, "exit\n") == 0) {
            destroy_env(env);
            return (0);
        }
    }
    return (0);
}

int launch_sh(int ac, char **av, char **env)
{
    char **env_copy;

    env_copy = copy_env(env);
    sh(ac, av, env_copy);
    return (0);
}