SRCS = srcs/ft_split.c srcs/gest.c srcs/get.c srcs/get2.c srcs/good_hit.c srcs/move.c srcs/move2.c srcs/sort.c srcs/stack.c srcs/utils.c srcs/push_swap.c srcs/utils2.c srcs/mini_sort.c srcs/micro_sort.c

OBJ = $(SRCS:.c=.o)

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Iincludes -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -o $@ -c $^ 

clean:
	rm -f  $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re