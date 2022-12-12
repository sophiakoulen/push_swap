CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

# source files here

ALGO = $(addprefix algorithms/,bubblesort.c quicksort.c radix.c)

OPERATIONS = $(addprefix operations/, op-1.c op-2.c op-3.c)

PARSING = $(addprefix parsing/, parsing-utils.c parsing.c strict-atoi.c)

DEBUG_UTILS = $(addprefix debug-utils/, print-stack.c)

STACK_UTILS = $(addprefix stack-utils/, operation-utils.c stack-utils-1.c stack-utils-2.c)

OTHER_UTILS = $(addprefix other-utils/, cleanup.c sort-small.c sorting-utils.c)

SRCS = $(addprefix src/, main.c $(ALGO) $(OPERATIONS) $(PARSING) $(DEBUG_UTILS) $(STACK_UTILS) $(OTHER_UTILS) $(FUNCS))

# parameters here

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address
endif

ifdef ALGORITHM
	CFLAGS += -D ALGORITHM=$(ALGORITHM)
endif

# rules here

all: $(NAME)

# dependencies here

libft/libft.a:
	make -C libft NOLIST=1

ft_printf/libftprintf.a:
	make -C ft_printf LIBFT_PATH=../libft

INCLUDE_PATHS = -Ilibft -Ift_printf -I.
LIB_PATHS = -Llibft -Lft_printf

# rules for program here

$(NAME): $(SRCS) libft/libft.a ft_printf/libftprintf.a
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE_PATHS) $(LIB_PATHS) -lft -lftprintf -o $@

# cleanup here

clean:
	make clean -C libft
	make clean -C ft_printf LIBFT_PATH=../libft

fclean:
	rm -f push_swap
	make fclean -C libft
	make fclean -C ft_printf LIBFT_PATH=../libft

re: fclean all

# rules for switching between mac and linux checkers

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
	
