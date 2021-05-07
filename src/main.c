/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "mysh1.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    launch_sh(ac, av, env);
    return (0);
}