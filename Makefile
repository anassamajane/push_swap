SRCS = final_check.c ft_split.c libft_linked_list.c main.c \
       parse.c parse_helpers.c push.c push_swap.c swap.c \
       reverse_rotate.c rotate.c small_sort.c sort_helpers.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
