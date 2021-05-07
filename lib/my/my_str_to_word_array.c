/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** Desc
*/

#include <unistd.h>
#include <stdlib.h>

int my_alphanum(char c)
{
    if (c == ' ' || c == '\0' || c == '\n' || c == ':' || c == '\t')
        return (0);
    else
        return (1);
}

int count_words(char const *str)
{
    int i = 0;
    int col = 0;

    while (str[i] != '\0'){
        if (my_alphanum(str[i]) == 1)
            col++;
        while (my_alphanum(str[i]) == 1 && str[i] != '\0')
            i++;
        if (str[i] != '\0')
            i++;
    }
    return (col);
}

int len_word(char const *str, int j)
{
    int len = 0;

    while (my_alphanum(str[j]) == 1) {
        j++;
        len++;
    }
    return (len);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int j = 0;
    int stock = 0;
    char **dest = malloc(sizeof(char *) * (count_words(str) + 1));

    while (i != count_words(str)) {
        stock = 0;
        while (my_alphanum(str[j]) == 0)
            j++;
        dest[i] = malloc(sizeof(char) * (len_word(str, j) + 1));
        while (my_alphanum(str[j]) == 1){
            dest[i][stock] = str[j];
            stock++;
            j++;
        }
        dest[i][stock] = '\0';
        i++;
    }
    dest[i] = NULL;
    return (dest);
}
