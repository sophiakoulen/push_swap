# push_swap, an exercice about sorting

push_swap is a learning project at 42Lausanne.

The exercice is as follows:

Sort a list of numbers using two stacks (stack a and stack b) and the following operations:
- pa: push the top item of b on top of a
- pb: push a's top item onto b
- sa: swap the first two elements of a
- sb: swap the first two elements of b
- ss: sa and sb simultaneously
- ra: rotate stack a (meaning the first element becomes the last)
- rb: rotate stack b
- rr: ra and rb simultaneously
- rra: reverse rotate a (meaning the last element becomes the first)
- rrb: reverse rotate b
- rrr: rra and rrb simultaneously

**Input:**
The list of numbers we need to sort, initially all on stack a.

**Output:**
A program consisting of the above instructions, that sorts the list.

## Goal
- 3 items: max 3 instructions
- 5 items: max 12 instructions
- 100 items: less than 700 instructions
- 500 items: less than 5500 instructions

## implementing the operations

To easily emulate those operations on a list of integers, I chose to use the doubly linked list data structure.
Stack a and stack b are each implemented as a pointer to a linked list.

Here is the relevent code snippet from my `push_swap.h` header:
```C
typedef struct s_list
{
	int		val;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef t_list	*t_stack;
```

The advantage of this structure is that I can implement all the operations in O(1) constant time, which is elegant.
To implement those operations, I need the following helper functions:
- `void	push(t_stack *s, t_list *item)`: Push item on top of stack s. This is just equates to inserting an element at the beginning of a linked list. Note that the `previous` pointer of the newly inserted element will point to the last element of the stack.
- `t_list	*pop(t_stack *s)`: Detaches the first element of the stack and returns a pointer to it.
- `void	rotate(t_stack *s)`: Rotate stack. First element becomes the last, etc. This is done very simply by just shifting the `s` pointer to point to the next item.
- `void reverse_rotate(t_stack *s)`:  Reverse rotate stack. Last element becomes the first, etc.


## finding a suitable sorting algorithm

The challenge is to find an efficient sorting algorithm that we can apply given our constrains.

Before starting the project, I already knew about two well-known sorting algorithms: bubblesort and quicksort.

### bubblesort

Bubblesort is slow (it has a time complexity of O(n^2)), but relatively easy to implement.
It is also very suitable in our case.

The idea of the algorithm is:
While our list is unsorted, go through the list and swap pairs of elements that are in the wrong order relatively to each other.

Results I got with bubblesort:
- 100 numbers: on average 11.2k operations
- 500 numbers: on average 298k operations

### quicksort

Quicksort is generally much quicker than bubblesort, since it has an average time complexity of O(nlogn), which is generally the best we can expect from a sorting algorithm.
It is, however, a bit more tricky to implement in our case.

The idea of the algorithm is:
Choose a pivot element and put everything that is smaller than the pivot before it and the rest after it. Now, separately sort those two chunks.

To implement quicksort, I apply the following technique:
```
Procedure quicksort(n):
	partition(n);
	quicksort(n/2);
	for 0 to n/2 do:
		rotate stack a;
	quicksort(n - n/2);
	for 0 to n/2 do:
		reverse rotate stack a;
```
```
Procedure partition(n):
	pivot <- median of n first items;
	first_greater <- pivot;
	for 0 to n do:
		if first item of a <= pivot:
			push it to stack b;
		else:
			if first_greater == pivot:
				first_greater <- first;
			rotate stack a;
		endif
	while first item of a != first_greater:
		reverse rotate stack a;
	while first item of b != pivot:
		rotate stack b;
	while sack b is not empty:
		push first item of b to stack a;
```

Results I got with quicksort:
- 100 numbers: on average 1.63k operations 
- 500 numbers: on average 12.4k operations

That's already much better! But it's not quick enough yet.
Our algorithm needs to be more than twice faster.

## Radix sort

Radix sort is also called bucket sort.
