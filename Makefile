CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

FUNCS = bubblesort.c \
quicksort.c \
operations1.c \
operations2.c \
operations3.c \
operations_utils.c \
parse_stack.c \
parse_stack_utils.c \
utils.c \
list.c \
atoi_careful.c

SRCS = main.c $(FUNCS)

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

libft/libft.a:
	make -C libft NOLIST=1

ft_printf/libftprintf.a:
	make -C ft_printf LIBFT_PATH=../libft

INCLUDE_PATHS = -Ilibft -Ift_printf
LIB_PATHS = -Llibft -Lft_printf

$(NAME): $(SRCS) libft/libft.a ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE_PATHS) $(LIB_PATHS) -lft -lftprintf -o $@

unit-tests: unit-tests.c $(FUNCS)
	$(CC) $(CFLAGS) $^ $(INCLUDE_PATHS) $(LIB_PATHS) -lft -lftprintf -o $@

clean:
	make clean -C libft
	make clean -C ft_printf LIBFT_PATH=../libft

fclean:
	make fclean -C libft
	make fclean -C ft_printf LIBFT_PATH=../libft

re: fclean all

test: $(NAME) checker
	./push_swap $(ARG) | ./checker $(ARG)
