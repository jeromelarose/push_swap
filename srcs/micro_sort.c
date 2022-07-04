/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:44:23 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 16:44:25 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_sort.h"

void	micro_sort2(t_stack *stackA, t_gest	*gest)
{
	if (gest->rvalue > gest->rnext && gest->rnext > gest->rlast)
	{
		write(1, "sa\n", 3);
		swap(stackA);
		write(1, "rra\n", 4);
		rrt(stackA);
	}
	else if (gest->rvalue > gest->rlast && gest->rnext < gest->rlast)
	{
		write(1, "ra\n", 3);
		rt(stackA);
	}
	else if (gest->rvalue < gest->rlast && gest->rnext > gest->rlast)
	{
		write(1, "sa\n", 3);
		swap(stackA);
		write(1, "ra\n", 3);
		rt(stackA);
	}
	else if (gest->rvalue > gest->rlast && gest->rvalue < gest->rnext)
	{
		write(1, "rra\n", 4);
		rrt(stackA);
	}
}

void	micro_sort(t_stack *stackA)
{
	t_gest	gest;

	init_gest(&gest);
	gest.rvalue = (*stackA)->value;
	gest.rnext = (*stackA)->next->value;
	gest.rlast = get_last(*stackA)->value;
	if (get_size(*stackA) == 2)
	{
		if (gest.rvalue > gest.rnext)
		{
			write(1, "sa\n", 3);
			swap(stackA);
		}
		return ;
	}
	else if (gest.rvalue < gest.rlast && gest.rvalue > gest.rnext)
	{
		write(1, "sa\n", 3);
		swap(stackA);
	}
	else
		micro_sort2(stackA, &gest);
}
