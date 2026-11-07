/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:29:19 by amalsaka          #+#    #+#             */
/*   Updated: 2026/11/03 14:02:35 by amalsaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_swap(t_stack **a)
{
	if (is_sorted(*a))
		printf("its already sorted");
	else
		test_sort(a);
}


int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	double disorder;
	//int selector[1]; to select flag and bench based on input TBA
	//int ops[11]; to count the operatins in bench TBA
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (write_error());
	if (valid(ac, av, &a) == 0)
		return (write_error());
	disorder = calc(a);
	print_stack(a);
	push_swap(&a);
	printf("\n");
	print_stack(a);
	free_stack(&a);
}

