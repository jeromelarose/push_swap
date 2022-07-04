/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:45:42 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:45:43 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "good_hit.h"

void	init_conf1(t_gest *gest)
{
	t_gest	init;

	init = *gest;
	init.ra = init.pos;
	init.rra = -1;
	init.rb = init.tmp_rb;
	init.rrb = -1;
	*gest = init;
}

void	init_conf2(t_gest *gest)
{
	t_gest	init;

	init = *gest;
	init.ra = -1;
	init.rra = init.rpos;
	init.rb = -1;
	init.rrb = init.tmp_rrb;
	*gest = init;
}

void	init_good_hit(t_gest *gest)
{
	t_gest	init;

	init = *gest;
	if (init.pos > init.tmp_rb && init.pos < init.good_hit)
	{
		init.good_hit = init.pos;
		init_conf1(&init);
	}
	if (init.pos == init.tmp_rb
		|| (init.pos < init.tmp_rb && init.tmp_rb < init.good_hit))
	{
		init.good_hit = init.tmp_rb;
		init_conf1(&init);
	}
	if (init.rpos == init.tmp_rrb
		|| (init.rpos > init.tmp_rrb && init.rpos < init.good_hit))
	{
		init.good_hit = init.rpos;
		init_conf2(&init);
	}
	*gest = init;
}

void	init_good_hit2(t_gest *gest)
{
	t_gest	init;

	init = *gest;
	if (init.rpos < init.tmp_rrb && init.tmp_rrb < init.good_hit)
	{
		init.good_hit = init.tmp_rrb;
		init_conf2(&init);
	}
	if (init.rpos + init.tmp_rb < init.good_hit)
	{
		init.good_hit = init.rpos + init.tmp_rb;
		init.ra = -1;
		init.rra = init.rpos;
		init.rb = init.tmp_rb;
		init.rrb = -1;
	}
	if (init.pos + init.tmp_rrb < init.good_hit)
	{
		init.good_hit = init.pos + init.tmp_rrb;
		init.ra = init.pos;
		init.rra = -1;
		init.rb = -1;
		init.rrb = init.tmp_rrb;
	}
	*gest = init;
}

void	gest_good_hit(t_gest *gest)
{
	init_good_hit(gest);
	init_good_hit2(gest);
}
