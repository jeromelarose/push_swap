/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:46:56 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:46:58 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h> 
#include <stdio.h>
#include "stack.h"
#include "utils.h"
#include "utils2.h"
#include "move.h"
#include "sort.h"
#include "get.h"
#include "ft_split.h"
#include "mini_sort.h"
#include "micro_sort.h"

void	select_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sort(*stack_a) && !is_double(stack_a))
	{
		if (get_size(*stack_a) <= 3)
			micro_sort(stack_a);
		else if (get_size(*stack_a) <= 5)
			mini_sort(stack_a, stack_b);
		else
			sort(stack_a, stack_b);
	}
	else if (is_double(stack_a))
		write (2, "Error\n", 6);
	free_stack(*stack_a);
	free_stack(*stack_b);
	stack_a = NULL;
	stack_b = NULL;
}

void	free_my_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	error(char **tab, t_stack *stack_a, t_stack *stack_b)
{
	write (2, "Error\n", 6);
	free_my_tab(tab);
	free_stack(*stack_a);
	free_stack(*stack_b);
}

int	init_stack(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	int		j;
	int		i;
	char	**tab;

	i = 0;
	while (++i < ac)
	{
		tab = ft_split(av[i], ' ');
		j = -1;
		while (tab[++j])
		{
			if (!is_num(tab[j]) || is_sup_max(tab[j]) || is_inf_min(tab[j]))
			{
				error(tab, stack_a, stack_b);
				return (0);
			}
			push(stack_a, ft_atoi(tab[j]));
			if (i > 1 || j >= 1)
				rt(stack_a);
		}
		free_my_tab(tab);
	}
	return (i == ac);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		return (0);
	if (init_stack(ac, av, &stack_a, &stack_b))
		select_sort(&stack_a, &stack_b);
	return (0);
}
