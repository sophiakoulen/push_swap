#include "push_swap.h"

/* return 0 if SUCCESS, -1 if error */

/* need to do malloc failure and overflow handling */

int	parse_stack(char **strs, t_stack *s)
{
	int		i;
	int		n;
	t_list	*new_node;
	int		val;

	n = 0;
	while (strs[n])
		(n)++;
	i = 0;
	while (strs[i])
	{
		val = ft_atoi(strs[n - i - 1]); //do ERANGE error handling
		new_node = factory(val);
		if (!new_node)
		{
			cleanup_list(s);
			ft_dprintf(2, "Error\n");
			exit(1);
		}
		push(s, new_node);
		i++;
	}
	return (0);
}