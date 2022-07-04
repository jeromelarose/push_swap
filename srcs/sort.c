/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:56:34 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:56:37 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	is_sort(t_stack stack)
{
	t_stack	tmp;
	int		old;

	if (!stack)
		return (1);
	tmp = stack;
	old = tmp->value;
	while (tmp)
	{
		if (tmp->value < old)
			return (0);
		old = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

void	init_tmp(t_stack *ptmp, t_stack *stackA, t_stack *stackB, t_gest *gest)
{
	t_gest		init;
	t_stack		tmp;

	tmp = *ptmp;
	init = *gest;
	init.rvalue = tmp->value;
	if (tmp->next)
		init.rnext = tmp->next->value;
	init.rlast = get_last_value(tmp);
	if (stackB && *stackB)
	{
		init.lvalue = (*stackB)->value;
		init.llast = get_last_value(*stackB);
		if ((*stackB)->next)
			init.lnext = (*stackB)->next->value;
	}
	if (get_size(*stackA) > 1)
		init.rpos = get_size(*stackA) - init.pos;
	else
		init.rpos = 0;
	init.tmp_rrb = get_rpos(*stackB, init.rvalue);
	init.tmp_rb = get_pos(*stackB, init.rvalue);
	*gest = init;
	*ptmp = tmp;
}

void	move_b_to_a2(int tmp_rrb, int tmp_rb, t_stack *stackA, t_stack *stackB)
{
	if (tmp_rrb < tmp_rb)
	{
		while (tmp_rrb-- >= 0)
		{
			write(1, "rrb\n", 4);
			rrt(stackB);
		}
	}
	else
	{
		while (tmp_rb-- > 0)
		{
			write(1, "rb\n", 3);
			rt(stackB);
		}
	}
	while (*stackB && stackB)
	{
		write(1, "pa\n", 3);
		pa(stackA, stackB);
	}
}

void	move_b_to_a(t_stack *stackA, t_stack *stackB)
{
	int		tmp_rb;
	int		tmp_rrb;
	int		max;

	max = get_max(*stackB);
	tmp_rrb = get_rpos(*stackB, get_max(*stackB));
	tmp_rb = get_pos(*stackB, get_max(*stackB));
	move_b_to_a2(tmp_rrb, tmp_rb, stackA, stackB);
}

void	sort(t_stack *stackA, t_stack *stackB)
{
	t_gest	gest;
	t_stack	tmp;

	while (stackA && *stackA)
	{
		init_gest(&gest);
		tmp = *stackA;
		while (tmp)
		{
			init_tmp(&tmp, stackA, stackB, &gest);
			gest_good_hit(&gest);
			gest.pos++;
			tmp = tmp->next;
		}
		gest_move(&gest, stackA, stackB);
	}
	move_b_to_a(stackA, stackB);
}
