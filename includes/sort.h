/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:37 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:41:39 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"
# include "get.h"
# include "move.h"
# include "gest.h"
# include "good_hit.h"

int		is_sort(t_stack stack);
void	sort(t_stack *stackA, t_stack *stackB);
void	init_tmp(t_stack *ptmp, t_stack *stackA, t_stack *stackB, t_gest *gest);
void	move_b_to_a(t_stack *stackA, t_stack *stackB);
void	micro_sort(t_stack *stackA);
void	mini_sort(t_stack *stackA, t_stack *stackB);

#endif
