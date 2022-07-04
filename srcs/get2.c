/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:45:19 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:45:22 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get.h"

int	get_last_value(t_stack stack)
{
	t_stack	tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->value);
}

int	get_size(t_stack stack)
{
	t_stack	tmp;
	int		i;

	if (!stack)
		return (0);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
