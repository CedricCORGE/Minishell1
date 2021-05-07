/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** Reverse a string
*/

void my_putchar(char c);

char *my_revstr(char *str)
{
    int i = 0;
    int count = 0;
    char z;

    while (str[count] != '\0') {
        count++;
    }
    count--;

    while (i <= count) {
        z = str[i];
        str[i] = str[count];
        str[count] = z;
        count--;
        i++;
    }
    return (str);
}
