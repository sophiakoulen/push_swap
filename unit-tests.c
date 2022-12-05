#include "push_swap.h"

void	test_pb(void)
{
	t_stack a;
	t_stack b;

	a = 0;
	b = 0;
	for (int i = 0; i < 5; i++)
	{
		push(&a, factory(i));
	}

	ft_printf("stack a:\n");
	print_stack(&a);
	ft_printf("stack b:\n");
	print_stack(&b);

	pb(&a, &b);

	ft_printf("stack a:\n");
	print_stack(&a);
	ft_printf("stack b:\n");
	print_stack(&b);

}

int main()
{
	test_pb();
	return (0);
}