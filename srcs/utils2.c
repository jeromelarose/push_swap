/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:00:59 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 15:01:50 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils2.h"

long	ft_strcmp(char *str, char *str2)
{
	while (str && str2 && *str && *str2 && *str == *str2)
	{
		str++;
		str2++;
	}
	return (*str - *str2);
}

int	is_sup_max(char *str)
{
	char	*max;

	max = "2147483647";
	if (*str == '-')
		return (0);
	if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 10)
		return (1);
	else if (ft_strlen(str) < 10)
		return (0);
	else if (ft_strcmp(max, str) < 0)
		return (1);
	return (0);
}

int	is_inf_min(char *str)
{
	char	*min;

	min = "2147483648";
	if (*str == '+')
		return (0);
	if (*str == '-')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 10)
		return (1);
	else if (ft_strlen(str) < 10)
		return (0);
	else if (ft_strcmp(min, str) < 0)
		return (1);
	return (0);
}

int	is_num(char *str)
{
	int		i;

	i = 0;
	if (str && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str && str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_double(t_stack *stackA)
{
	t_stack		tmp;
	t_stack		org;
	int			value;

	org = *stackA;
	while (org)
	{
		value = org->value;
		tmp = org->next;
		while (tmp)
		{
			if (tmp->value == value)
				return (1);
			tmp = tmp->next;
		}
		org = org->next;
	}
	return (0);
}
