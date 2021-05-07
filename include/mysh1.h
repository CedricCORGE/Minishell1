/*
** EPITECH PROJECT, 2021
** mysh1.h
** File description:
** mini shell 1
*/

#ifndef mysh1_H_
#define mysh1_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "my.h"

int launch_sh(int ac, char **av, char **env);

int check_variable_name(char **variable, int indic);

int check_action(char *str);

char **call_builtins(char *str, char **env);

char **my_cd(char **env, char **command);

void my_env(char **env);

char **setenv2(char **env, char **variable);

char *binary_exec(char *exec, char *binary_name);

char **my_setenv(char **env, char **variable);

char **my_unsetenv(char **env, char **command);

int get_max_length(char **env);

void destroy_variable_name(char **variable_name);

char **init_variable_name(char **env);

char **init_swap_tab(char **env, int max_length, int k);

int my_exec(char **env, char *str);

void destroy_command(char **command);

void wait_end_exec(pid_t pid);

char *get_path(char **env, char *exec);

char *find_variable(char **tab, char *exec);

int get_path_index(char **env);

void destroy_tab(char **tab, int nb_lines);

char **update_pwd(void);

char **error_cd(char **command, char **env, char **tab);

char **do_cd(char **env, char **command, char **tab);

void cd_home(char **env);

void cd_past(char **env);

int is_full_path(char **command);

char **swap_to_the_end(char **env, int k);

char **load_new_env(char **new_env, int k, int i);

#endif /* !mysh1_H_ */
