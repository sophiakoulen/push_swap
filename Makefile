CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

ALGO = $(addprefix algorithms/,bubblesort.c quicksort.c)

FUNCS = operations1.c \
operations2.c \
operations3.c \
operations_utils.c \
parse_stack.c \
parse_stack_utils.c \
utils.c \
list.c \
strict_atoi.c \
sort_n.c

SRCS = main.c $(ALGO) $(FUNCS)

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

libft/libft.a:
	make -C libft NOLIST=1

ft_printf/libftprintf.a:
	make -C ft_printf LIBFT_PATH=../libft

INCLUDE_PATHS = -Ilibft -Ift_printf -I.
LIB_PATHS = -Llibft -Lft_printf

$(NAME): $(SRCS) libft/libft.a ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE_PATHS) $(LIB_PATHS) -lft -lftprintf -o $@

unit-tests: unit-tests.c $(FUNCS)
	$(CC) $(CFLAGS) $^ $(INCLUDE_PATHS) $(LIB_PATHS) -lft -lftprintf -o $@

clean:
	make clean -C libft
	make clean -C ft_printf LIBFT_PATH=../libft

fclean:
	rm -f push_swap
	make fclean -C libft
	make fclean -C ft_printf LIBFT_PATH=../libft

re: fclean all

test: $(NAME) checker
	./push_swap $(ARG) | ./checker $(ARG)

mac: checker_mac
	if [ -f checker ] ; then \
		mv checker checker_linux  ;\
	fi
	mv checker_mac checker

linux: checker_linux
	if [ -f checker ] ; then \
		mv checker checker_mac ;\
	fi
	mv checker_linux checker
	
