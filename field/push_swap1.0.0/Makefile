NAME = push_swap

SRC = src/main.c\
		src/utils.c\
		src/error.c\
		src/sort.c\
		src/operations.c\
		src/free.c\
		src/sort_utils.c

CC = cc

CFLAGS = -Wall -Wextra -Werror -Iincludes

HEADER = push_swap.h

OBJS = $(SRC:.c=.o)

LIBFT_PATH = ./libft/

all : $(NAME)

$(NAME) : $(OBJS)
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)libft.a -o $(NAME)

clean :
		rm -rf $(OBJS)
		make clean -C $(LIBFT_PATH)

fclean : clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY: all clean fclean re