/*
** EPITECH PROJECT, 2021
** call_ops.c
** File description:
** call different ops
*/

#include "my.h"
#include "mysh1.h"

char **call_builtins(char *str, char **env_cpy)
{
    char **builtin = my_str_to_word_array(str);

    if (my_strcmp(builtin[0], "cd") == 0)
        env_cpy = my_cd(env_cpy, builtin);
    if (my_strcmp(builtin[0], "env") == 0)
        my_env(env_cpy);
    if (my_strcmp(builtin[0], "setenv") == 0) {
        env_cpy = my_setenv(env_cpy, builtin);
    } else if (my_strcmp(builtin[0], "unsetenv") == 0)
        env_cpy = my_unsetenv(env_cpy, builtin);
    return (env_cpy);
}