/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:25 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:41:28 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "stack.h"

void		push(t_stack *st, int value);
int			pop(t_stack *st);
void		swap(t_stack *st);
void		ss(t_stack *stackA, t_stack *stackB);
void		pa(t_stack *stackA, t_stack *stackB);
void		pb(t_stack *stackA, t_stack *stackB);
void		rt(t_stack *st);
void		rrt(t_stack *st);
void		rt2(t_stack *stA, t_stack *stB);
void		rrt2(t_stack *stA, t_stack *stB);

#endif
