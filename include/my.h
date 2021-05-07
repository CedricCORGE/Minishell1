/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** all prototype
*/

void my_putchar(char c);

int my_puterror(char const *str);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

char *my_strdup(char const *src);

int my_str_isupper(char const *str);

char *my_strstr(char *str, char const *to_find);

char *my_strncpy(char *dest, char const *src, int n);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strlowcase(char *str);

void my_swap(int *a, int *b);

char *my_strupcase(char *str);

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *srx);

void my_sort_int_array(int *array, int size);

int my_put_nbr(int nb);

int my_getnbr(char const *str);

int my_find_prime_sup(int nb);

int my_showstr(char const *str);

int my_compute_square_root(int nb);

int my_showmem(char const *str, int size);

int my_is_prime(int nb);

int my_compute_power_rec(int nb, int p);

int my_isneg(int n);

char *my_revstr(char *str);

int my_putstr(char const *str);

char *my_strcapitalize(char *str);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

void my_print_params(int argc, char *argv[]);

void my_rev_params(int argc, char *argv[]);

void my_sort_params(int argc, char *argv[]);

int match(char const *s1, char const *s2);

int addition(char *num1, char *num2);

int substraction(char *num1, char *num2);

int multiplication(char *num1, char *num2);

int modulo(char *num1, char *num2);

int division(char *num1, char *num2);

char **my_str_to_word_array(char const *str);

int my_show_word_array(char * const *tab);

int len_word(char const *str);

int word_counter(char const *str);

int my_str_isalphanumeric(char c);

int my_printf(char *str, ...);
