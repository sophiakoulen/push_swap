/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:46:51 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/07 13:31:00 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_list
{
	int				val;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef t_list	*t_stack;

/* atoi careful */
int		atoi_careful(char *str, int *val);

/* bubble sort */
void	bubble_sort(t_stack *a, t_stack *b);

/* quick sort */
void	sort3(t_stack *a, t_stack *b);
void	quick_sort(t_stack *a, t_stack *b, int n);

/* parse stack */
void	parse_stack(char **strs, t_stack *s);
int		*copy_tab(int *tab, int n);
int		check_duplicates(int *tab, int n);
int		atoi_careful(char *str, int *val);
int		get_int_tab(char **strs, int **tab, int *n);

/* parse stack utils */
void	sort_int_tab(int *tab, int n);

/* utils */
int		empty(t_stack *s);
int		first(t_stack *s);
int 	last(t_stack *s);
int		second(t_stack *s);
int		third(t_stack *s);
void	print_stack(t_stack *a);

/* list */
t_list	*factory(int val);
int		get_size(t_list *node);
void	cleanup_list(t_list *node);

/* operations 1*/
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);

/* operations 2 */
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* operations 3 */
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

#endif