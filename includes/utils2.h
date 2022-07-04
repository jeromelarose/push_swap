/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:24:22 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 16:24:24 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS2_H
# define UTILS2_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "stack.h"
# include "utils.h"

int		is_double(t_stack *stackA);
int		is_num(char *str);
int		is_inf_min(char *str);
int		is_sup_max(char *str);
long	ft_strcmp(char *str, char *str2);

#endif