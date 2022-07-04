/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:05:33 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 16:05:36 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_sort.h"
#include "micro_sort.h"

void	mini_sort2(t_gest	*gest, t_stack *stackA, t_stack *stackB)
{
	write(1, "pb\n", 3);
	pb(stackA, stackB);
	gest->tmp_rrb = get_rpos(*stackA, get_max(*stackA));
	gest->tmp_rb = get_pos(*stackA, get_max(*stackA));
	if (gest->tmp_rb < gest->tmp_rrb)
	{
		while (gest->tmp_rb-- > 0)
		{
			write (1, "ra\n", 3);
			rt(stackA);
		}
	}
	else
	{
		while (gest->tmp_rrb-- >= 0)
		{
			write (1, "rra\n", 4);
			rrt(stackA);
		}
	}
}

void	init_min(t_stack *stackA, t_stack *stackB)
{
	int	p;
	int	rp;

	p = get_pos(*stackA, get_min(*stackA));
	rp = get_rpos(*stackA, get_min(*stackA));
	if (p < rp)
	{
		while (p--)
		{
			write (1, "ra\n", 3);
			rt(stackA);
		}
		write(1, "pb\n", 3);
		pb(stackA, stackB);
	}
	else
	{
		while (rp-- >= 0)
		{
			write (1, "rra\n", 4);
			rrt(stackA);
		}
		write(1, "pb\n", 3);
		pb(stackA, stackB);
	}
}

void	mini_sort(t_stack *stackA, t_stack *stackB)
{
	init_min(stackA, stackB);
	init_min(stackA, stackB);
	micro_sort(stackA);
	write(1, "pa\n", 3);
	pa(stackA, stackB);
	write(1, "pa\n", 3);
	pa(stackA, stackB);
}
