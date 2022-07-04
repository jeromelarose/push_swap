/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:40:54 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:40:57 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

# include "stack.h"

int			get_max(t_stack stack);
int			get_min(t_stack stack);
int			get_size(t_stack stack);
long		get_pos(t_stack stack, int value);
long		get_rpos(t_stack stack, int value);
t_stack		get_last(t_stack stack);
int			get_last_value(t_stack stack);

#endif
