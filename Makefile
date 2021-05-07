##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC				=	src/sh.c				\
					src/check_action.c		\
					src/call_ops.c			\
					src/ops/cd.c			\
					src/ops/env.c			\
					src/ops/unsetenv.c		\
					src/ops/setenv.c		\
					src/my_exec.c			\
					src/utils_my_exec.c		\
					src/utils_unsetenv.c	\
					src/utils_setenv.c		\
					src/utils_cd.c			\
					src/destroy_variable.c	\
					src/main.c

OBJ				=	$(SRC:.c=.o)

NAME			=	mysh

CFLAGS			=	-Wall -Werror -Wshadow -I include/

LDFLAGS			=	-L./lib -lmy

CC				=	gcc

all:				$(NAME)

$(NAME):			$(OBJ)
					make re -C lib/my/
					$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

debug:				$(OBJ)
					make re -C lib/my/
					$(CC) -g $(OBJ) -o $(NAME) -L./lib/ -lmy -lm

clean:
					rm -f $(OBJ)

fclean:				clean
					rm -f $(NAME)
					make fclean -C lib/my/
					rm -f lib/libmy.a

re:					fclean all

.PHONY:
					all clean fclean re