#include "push_swap.h"
/*
void test_ra(t_stack *a, t_stack *b)
{
	print_stack(a);
	ra(a, b);
	print_stack(a);
}
*/

/*
void test_sa(t_stack *a, t_stack *b)
{
	print_stack(a);
	sa(a, b);
	print_stack(a);
}
*/


int	main(int argc, char *argv[])
{
	int		n;
	t_stack a;
	t_stack b;
	char	**strs;

	a = 0;
	b = 0;
	n = argc - 1;
	if (n == 1)
	{
		strs = ft_split(argv[1], ' ');
		parse_stack(strs, &a);
		free(strs);
	}
	else
	{
		parse_stack(argv + 1, &a);
	}
	bubble_sort(&a, &b);
	//test_ra(&a, &b);
	//test_sa(&a, &b);
	/* see if sorted */
	/*for (int i = 0; i < n; i++)
		ft_dprintf(2, "%d\n", a_stack[i]);
	
	*/
	cleanup_list(a);
	cleanup_list(b);	
	return (0);
}