CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

SRCS= main.c \
bubblesort.c \
operations.c \
parse_stack.c \
utils.c \
list.c

all: $(NAME)

libft/libft.a:
	make -C libft NOLIST=1

ft_printf/libftprintf.a:
	make -C ft_printf LIBFT_PATH=../libft

INCLUDE_PATHS = -Ilibft -Ift_printf
LIB_PATHS = -Llibft -Lft_printf

$(NAME): $(SRCS) libft/libft.a ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE_PATHS) $(LIB_PATHS) -lft -lftprintf -o $@

clean:
	make clean -C libft
	make clean -C ft_printf LIBFT_PATH=../libft

fclean:
	make fclean -C libft
	make fclean -C ft_printf LIBFT_PATH=../libft

re: fclean all
