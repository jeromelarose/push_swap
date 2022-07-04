/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:46:08 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:46:11 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	swap(t_stack *st)
{
	t_stack	stack;
	t_stack	tmp;

	tmp = NULL;
	stack = NULL;
	if (st && *st && (*st)->next)
	{
		stack = *st;
		tmp = stack->next;
		if (tmp->next)
			tmp->next->prev = stack;
		stack->prev = tmp;
		stack->next = tmp->next;
		tmp->next = stack;
		tmp->prev = NULL;
		*st = tmp;
	}
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	swap(stackA);
	swap(stackB);
}

void	pa(t_stack *stackA, t_stack *stackB)
{
	int	value;

	if (stackB && *stackB)
	{
		value = pop(stackB);
		push(stackA, value);
	}
}

void	pb(t_stack *stackA, t_stack *stackB)
{
	int	value;

	if (stackA && *stackA)
	{
		value = pop(stackA);
		push(stackB, value);
	}
}

void	rt(t_stack *st)
{
	t_stack	tmp;
	t_stack	stack;

	tmp = NULL;
	stack = NULL;
	if (st && *st && (*st)->next)
	{
		stack = *st;
		tmp = stack;
		*st = tmp->next;
		while (tmp->next)
			tmp = tmp->next;
		stack->next->prev = NULL;
		stack->next = NULL;
		stack->prev = tmp;
		tmp->next = stack;
	}
}
