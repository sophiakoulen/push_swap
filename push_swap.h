#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef	struct s_list
{
	int				val;
	struct s_list	*next;
	struct s_list	*previous;
} t_list;

typedef t_list * t_stack;

/* bubble sort */
void	bubble_sort(t_stack *a, t_stack *b);

/* parse stack */
int		parse_stack(char **strs, t_stack *s);

/* utils */
int		empty(t_stack *s);
int		first(t_stack *s);
int 	second(t_stack *s);
void	print_stack(t_stack *a);

/* list */
t_list	*factory(int val);
int		get_size(t_list *node);
void	cleanup_list(t_list *node);

/* operations */
void	push(t_stack *s, t_list *node);

void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);

#endif