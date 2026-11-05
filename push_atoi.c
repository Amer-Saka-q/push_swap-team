/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:56:18 by amalsaka          #+#    #+#             */
/*   Updated: 2026/11/03 13:44:56 by amalsaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	push_atoi(char *s, int *number)
{
	int	i;
	int	sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		if (sign == 1 && n > INT_MAX)
			return (0);
		else if (sign == -1 && -n < INT_MIN)
			return (0);
		i++;
	}
	if (s[i] != '\0')
		return (0);
	*number = (int)(n * sign);
	return (1);
}

int	dupee(t_stack *s, int number)
{
	while (s)
	{
		if (s->number == number)
			return (0);
		s = s->next;
	}
	return (1);
}

t_stack	*stack_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}
	
int	push_stack(t_stack **a, int number)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->number = number;
	new->next = NULL;
	if (!*a)
		*a = new;
	else
		stack_last(*a)->next = new;
	return (1);
}
int	valid(int ac, char **av, t_stack **a)
{
	int		i;
	int		j;
	int		number;
	char	**valid;

	i = 1;
	while (i < ac)
	{
		j = 0;
		valid = ft_split(av[i], ' ');
		if (!valid || !valid[0])
			return (free_split(valid, a));
		while (valid[j])
		{
			if (!push_atoi(valid[j], &number) || !dupee(*a, number))
				return (free_split(valid, a));
			push_stack(a, number);
			j++;
		}
		free_split(valid, NULL);
		i++;
	}
	return (1);
}
