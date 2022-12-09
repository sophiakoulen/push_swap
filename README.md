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

## implementing the operations

To easily emulate those operations on a list of integers, I chose to use the doubly linked list data structure.
Stack a and stack b are each implemented as a pointer to a linked list.

Here is the relevent code snippet from my `push_swap.h` header:
```C
typedef struct s_list
{
	int	val;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef t_list	*t_stack;
```

The advantage of this structure is that I can implement all the operations in O(1) constant time, which is elegant.

## finding a suitable sorting algorithm

The challenge is to find an efficient sorting algorithm that we can apply given our constrains.

Before starting the project, I already knew about two well-known sorting algorithms: bubblesort and quicksort.

### bubblesort

Bubblesort is slow (it has a time complexity of O(n^2)), but relatively easy to implement.
It is also very suitable in our case.

The idea of the algorithm is:
While our list is unsorted, go through the list and swap pairs of elements that are in the wrong order relatively to each other.

### quicksort

Quicksort is generally much quicker than bubblesort, since it has an average time complexity of (O(nlogn)), which is generally the best we can expect from a sorting algorithm.
It is, however, a bit more tricky to implement in our case.

The idea of the algorithm is:
Choose a pivot element and put everything that is smaller than the pivot before it and the rest after it. Now, separately sort those two chunks.
