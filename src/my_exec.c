/*
** EPITECH PROJECT, 2021
** my_exec.c
** File description:
** exec
*/

#include "my.h"
#include "mysh1.h"

char *binary_exec(char *exec, char *binary_name)
{
    int i = 0;
    int k = 0;
    char *buf = malloc(sizeof(char) * 1000);
    size_t size = 1000;

    if (exec[0] != '.' && exec[1] != '/')
        return (NULL);
    for (i = 0; (exec[i] < 'A' || exec[i] > 'Z') && \
(exec[i] < 'a' || exec[i] > 'z'); i++);
    for (; exec[i]; i++, k++) {
        binary_name[k] = exec[i];
    }
    binary_name[k] = '\0';
    getcwd(buf, size);
    my_strcat(buf, "/");
    my_strcat(buf, binary_name);
    if (access(buf, X_OK) == 0)
        return (buf);
    return (NULL);
}

int check_dir(char *path, char **command)
{
    DIR *dir;

    if ((dir = opendir(path)) != NULL) {
        closedir(dir);
        my_printf("%s: Permission denied.\n", command[0]);
        return (1);
    }
    return (0);
}

int my_exec(char **env, char *str)
{
    char **command = my_str_to_word_array(str);
    char *path;
    int pid = 0;

    if (command[0] == NULL)
        return (-2);
    path = get_path(env, command[0]);
    if (path == NULL)
        return (-1);
    if (check_dir(path, command) == 1)
        return (0);
    pid = fork();
    if (pid == 0) {
        execve(path, command, env);
        my_printf("failed\n");
        exit(-1);
    }
    wait_end_exec(pid);
    destroy_command(command);
    return (0);
}