/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:44:29 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:44:31 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"

t_stack	get_last(t_stack stack)
{
	t_stack	tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	get_max(t_stack stack)
{
	t_stack	tmp;
	int		max;

	if (!stack)
		return (0);
	tmp = stack;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack stack)
{
	t_stack	tmp;
	int		min;

	if (!stack)
		return (0);
	tmp = stack;
	min = get_max(stack);
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

long	get_pos(t_stack stack, int value)
{
	t_stack	tmp;
	int		i;
	int		min;
	int		max;

	tmp = stack;
	i = 0;
	min = get_min(stack);
	max = get_max(stack);
	if (get_size(stack) < 2)
		return (0);
	while (tmp && ((!tmp->prev
				&& !(value > tmp->value && value < get_last_value(tmp)))
			|| (tmp->prev && !(value > tmp->value && value < tmp->prev->value))
			|| (value >= max) || (value <= min)))
	{
		if ((value >= max && tmp->value == max)
			|| (value <= min && tmp->prev && tmp->prev->value == min))
			break ;
		if (value == tmp->value)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

long	get_rpos(t_stack stack, int value)
{
	t_stack	tmp;
	int		i;
	int		min;
	int		max;

	i = 0;
	if (get_size(stack) < 2)
		return (0);
	min = get_min(stack);
	max = get_max(stack);
	tmp = get_last(stack);
	while (tmp && ((!tmp->next && !(value < tmp->value && value > stack->value))
			|| (tmp->next && !(value > tmp->next->value && value < tmp->value))
			|| (value >= max) || (value <= min)))
	{
		if (value >= max && tmp->next && tmp->next->value == max)
			break ;
		if (value < min && tmp->value == min)
			break ;
		if (value == tmp->value)
			break ;
		i++;
		tmp = tmp->prev;
	}
	return (i);
}
