NAME = push_swap

SRC = main.c\
		main_utils.c\
		test.c

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
