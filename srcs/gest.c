/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:44:06 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:44:07 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gest.h"

void	init_gest(t_gest *gest)
{
	t_gest	init;

	init = *gest;
	init.pos = 0;
	init.ra = -2147483648;
	init.rb = -2147483648;
	init.rrb = -2147483648;
	init.rra = -2147483648;
	init.rpos = -2147483648;
	init.good_hit = 2147483647;
	*gest = init;
}

void	gest_move_double(t_gest *gest, t_stack *stackA, t_stack *stackB)
{
	t_gest	init;
	char	*msg;

	init = *gest;
	while (init.ra > 0 && init.rb > 0)
	{
		msg = "rr\n";
		rt2(stackA, stackB);
		write(1, msg, ft_strlen(msg));
		init.ra--;
		init.rb--;
	}
	while (init.rra > 0 && init.rrb > 0)
	{
		msg = "rrr\n";
		write(1, msg, ft_strlen(msg));
		rrt2(stackA, stackB);
		init.rra--;
		init.rrb--;
	}
	*gest = init;
}

void	gest_move_normal(t_gest *gest, t_stack *stackA, t_stack *stackB)
{
	t_gest	init;
	char	*msg;

	init = *gest;
	while (init.ra > 0)
	{
		msg = "ra\n";
		write(1, msg, ft_strlen(msg));
		rt(stackA);
		init.ra--;
	}
	while (init.rb > 0)
	{
		msg = "rb\n";
		write(1, msg, ft_strlen(msg));
		rt(stackB);
		init.rb--;
	}
	*gest = init;
}

void	gest_move_reverse(t_gest *gest, t_stack *stackA, t_stack *stackB)
{
	t_gest	init;
	char	*msg;

	init = *gest;
	while (init.rra > 0)
	{
		msg = "rra\n";
		write(1, msg, ft_strlen(msg));
		rrt(stackA);
		init.rra--;
	}
	while (init.rrb > 0)
	{
		msg = "rrb\n";
		write(1, msg, ft_strlen(msg));
		rrt(stackB);
		init.rrb--;
	}
	*gest = init;
}

void	gest_move(t_gest *gest, t_stack *stackA, t_stack *stackB)
{
	char	*msg;

	msg = "pb\n";
	gest_move_double(gest, stackA, stackB);
	gest_move_normal(gest, stackA, stackB);
	gest_move_reverse(gest, stackA, stackB);
	write(1, msg, ft_strlen(msg));
	pb(stackA, stackB);
}
