/*
** EPITECH PROJECT, 2021
** utils_cd.c
** File description:
** utils cd
*/

#include "mysh1.h"

void destroy_tab(char **tab, int nb_lines)
{
    for (int i = 0; i < nb_lines; i++)
        free(tab[i]);
    free(tab);
}

char **update_pwd(void)
{
    char *buf = NULL;
    char **tab = malloc(sizeof(char *) * 3);

    buf = getcwd(NULL, 0);
    for (int i = 0; i < 3; i++)
        tab[i] = malloc(sizeof(char) * (my_strlen(buf) + 1));
    my_strcpy(tab[1], "OLDPWD");
    my_strcpy(tab[2], buf);
    return (tab);
}

char **error_cd(char **command, char **env, char **tab)
{
    if (opendir(command[1]) == NULL && access(command[1], F_OK) == 0) {
        my_printf("%s: Not a directory.\n", command[1]);
        destroy_tab(tab, 3);
        return (env);
    }
    if (chdir(command[1]) == -1) {
        my_printf("%s: No such files or directory.\n", command[1]);
    }
    destroy_tab(tab, 3);
    return (env);
}

char **do_cd(char **env, char **command, char **tab)
{
    char **new_env = NULL;

    if (command[1] == 0 || my_strcmp(command[1], "~") == 0) {
        new_env = setenv2(env, tab);
        cd_home(new_env);
        destroy_tab(tab, 3);
        return (new_env);
    }
    if (my_strcmp(command[1], "-") == 0) {
        cd_past(env);
        new_env = setenv2(env, tab);
        destroy_tab(tab, 3);
        return (new_env);
    }
    if (is_full_path(command) == 0) {
        new_env = setenv2(env, tab);
        destroy_tab(tab, 3);
        return (new_env);
    }
    return (NULL);
}