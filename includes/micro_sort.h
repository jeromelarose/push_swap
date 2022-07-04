/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:49:01 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 16:49:05 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_SORT_H
# define MICRO_SORT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "stack.h"
# include "gest.h"
# include "get.h"

void	micro_sort(t_stack *stackA);
void	micro_sort2(t_stack *stackA, t_gest	*gest);

#endif