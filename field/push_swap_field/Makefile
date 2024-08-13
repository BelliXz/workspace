NAME = push_swap

SRC = main.c\
		error.c\
		init_stack.c\
		push.c\
		rev_rotate.c\
		rotate.c\
		sort_3.c\
		sort_utils.c\
		sort.c\
		swap.c\

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

OBJS = $(SRC.c=.o)

LIBFT_PATH = libft/

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_PATH)libft.h $(HEADER)
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)libft.a

clean :
		rm -rf $(OBJS)
		make clean -C $(LIBFT_PATH)

fclean : clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT_PATH)

re : fclean all
