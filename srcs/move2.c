/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:46:30 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:46:40 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	push(t_stack *st, int value)
{
	t_stack	tmp;
	t_stack	stack;

	tmp = creat_node();
	tmp->value = value;
	stack = *st;
	if (stack)
	{
		tmp->next = stack;
		stack->prev = tmp;
	}
	*st = tmp;
}

int	pop(t_stack *st)
{
	int		value;
	t_stack	stack;
	t_stack	new;

	value = 0;
	new = NULL;
	stack = *st;
	if (stack)
	{
		value = stack->value;
		if (stack->next)
		{
			new = stack->next;
			new->prev = NULL;
		}
		free(stack);
		stack = NULL;
	}
	*st = new;
	return (value);
}

void	rt2(t_stack *stA, t_stack *stB)
{
	rt(stA);
	rt(stB);
}

void	rrt2(t_stack *stA, t_stack *stB)
{
	rrt(stA);
	rrt(stB);
}

void	rrt(t_stack *st)
{
	t_stack	tmp;
	t_stack	stack;

	tmp = NULL;
	stack = NULL;
	if (st && *st && (*st)->next)
	{
		stack = *st;
		tmp = stack;
		while (tmp->next)
			tmp = tmp->next;
		stack->prev = tmp;
		tmp->prev->next = NULL;
		tmp->next = stack;
		tmp->prev = NULL;
		*st = tmp;
	}
}
