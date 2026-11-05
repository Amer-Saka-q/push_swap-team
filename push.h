/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:35:52 by amalsaka          #+#    #+#             */
/*   Updated: 2026/11/03 14:02:24 by amalsaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>//replace with ur own printf later

typedef struct s_node
{
	int	number;
	struct s_node *next;
} t_stack;

char	**ft_split(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		push_atoi(char *s, int *number);
int		dupee(t_stack *s, int number);
int		valid(int ac, char **av, t_stack **a);
int		free_split(char **s, t_stack **a);
int		write_error(void);
void		print_stack(t_stack *a);
void		free_stack(t_stack **a);
t_stack		*stack_last(t_stack *s);
#endif
