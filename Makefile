SRCS = final_check.c ft_split.c libft_linked_list.c main.c \
       parse.c parse_helpers.c push.c push_swap.c swap.c \
       reverse_rotate.c rotate.c small_sort.c sort_helpers.c

SRCSB = bonus/checker_bonus.c bonus/libft_helpers_bonus.c bonus/main_bonus.c \
		bonus/parse_bonus.c bonus/parse_helpers_bonus.c bonus/push_bonus.c \
		bonus/reverse_rotate_bonus.c bonus/rotate_bonus.c bonus/swap_bonus.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c bonus/ft_split_bonus.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CHECKER = checker

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(CHECKER): $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(CHECKER)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.SECONDARY: $(OBJS) $(OBJSB)

.PHONY: all clean fclean re bonus
