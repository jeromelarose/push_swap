/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:40:38 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:40:43 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEST_H
# define GEST_H

# include "stack.h"
# include "move.h"

typedef struct s_gest_move
{
	long		rvalue;
	long		rlast;
	long		rnext;
	long		lvalue;
	long		llast;
	long		lnext;
	long		rrb;
	long		rra;
	long		rb;
	long		ra;
	long		tmp_rb;
	long		tmp_rrb;
	long		pos;
	long		rpos;
	long		good_hit;
}				t_gest;

void	gest_move(t_gest *gest, t_stack *stackA, t_stack *stackB);
void	gest_move_reverse(t_gest *gest, t_stack *stackA, t_stack *stackB);
void	gest_move_normal(t_gest *gest, t_stack *stackA, t_stack *stackB);
void	gest_move_double(t_gest *gest, t_stack *stackA, t_stack *stackB);
void	init_gest(t_gest *gest);

#endif
