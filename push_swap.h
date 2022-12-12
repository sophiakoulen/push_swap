/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:46:51 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/12 10:48:13 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

# define WHITESPACE " \t\n\v\f\r"

# define RADIX 0
# define QUICK 1
# define BUBBLE 2

# ifndef ALGORITHM
#  define ALGORITHM RADIX
# endif

/* The data structure we'll be using is a circular doubly linked list */

typedef struct s_list
{
	int				val;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef t_list	*t_stack;

/* bubble sort */
void	bubble_sort(t_stack *a, t_stack *b);

/* quick sort */
int		get_median(t_stack a, int n);
void	partition(t_stack *a, t_stack *b, int n);
void	quick_sort(t_stack *a, t_stack *b, int n);

/* radix sort */
void	radix_sort(t_stack *a, t_stack *b, int n);

/* parsing */
void	parse_args(int n, char **argv, t_stack *a, t_stack *b);

/* parsing utils */
void	sort_int_tab(int *tab, int n);
int		*copy_tab(int *tab, int n);
int		check_duplicates(int *tab, int n);
int		get_int_tab(char **strs, int **tab, int *n);
int		normalize(int *tab, int n);

/* atoi careful */
int		strict_atoi(char *str, int *val);

/* operations */
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

/* operation utils */
void	rev_rotate(t_stack *s);
void	rotate(t_stack *s);
void	swap(t_stack *s);
t_list	*pop(t_stack *s);
void	push(t_stack *s, t_list *node);

/* stack utils 1*/
int		empty(t_stack *s);
int		first(t_stack *s);
int		last(t_stack *s);
int		second(t_stack *s);
int		third(t_stack *s);

/* stack utils 2 */
t_list	*factory(int val);

/* cleanup */
void	cleanup_strs(char **strs);
void	cleanup_list(t_list *node);

/* sort small stack*/
void	sort2(t_stack *a, t_stack *b);
void	sort3(t_stack *a, t_stack *b);
void	sort5(t_stack *a, t_stack *b);

/* sorting utils */
int		get_size(t_list *node);
int		n_sorted(t_stack s, int n);

/* debug utils */
void	print_stack(t_stack *a);

#endif