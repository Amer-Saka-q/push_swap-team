#include "push.h"

int is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->number > a->next->number)
			return(0);
		a = a->next;
	}
	return (1);
}


void	swap(t_stack **a)
{
	t_stack	*second;

	if (!*a || !(*a) ->next)
		return ;
	second = (*a) ->next; // I save the 2nd node
	(*a) ->next = second ->next; // i make 1st node point to the 3rd node
	second ->next = *a; // i make the new 2nd the HEAD of the stack
	*a = second; // update the head
}

void	rotate(t_stack **a)
{
	t_stack *first;

	if (!*a || !(*a) ->next)
		return ;
	first = *a; // i save the 1st node
	*a = first ->next; // update the head to point to 2nd node which will be new head
	first ->next = NULL; // the first node will now point to null bc we will put it last
	(stack_last(*a))->next = first; // i go to the last node and make it point to the new last node 
}

void	test_sort(t_stack **a)
{
	int size;
	int i;

	size = stack_size(*a);
	while (!is_sorted(*a))
	{
		i = 0;
		while (i < size - 1)
		{
			if ((*a)->number > (*a)->next->number)
				swap(a);
			rotate(a);
			i++;
		}
		rotate(a);
	}
}
