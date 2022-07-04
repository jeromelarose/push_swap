/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:59:32 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:59:34 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_empty(t_stack stack)
{
	if (!stack)
		return (1);
	return (0);
}

void	print_stack(t_stack stack)
{
	t_stack	tmp;
	char	*str;

	tmp = NULL;
	if (stack)
	{
		tmp = stack;
		while (tmp)
		{
			str = ft_itoa(tmp->value);
			write(1, str, ft_strlen(str));
			write(1, "\n", 1);
			free (str);
			str = NULL;
			tmp = tmp->next;
		}
	}
}

void	free_stack(t_stack nd)
{
	t_stack	tmp;

	if (nd)
	{
		while (nd)
		{
			tmp = nd->next;
			free(nd);
			nd = NULL;
			nd = tmp;
		}
		if (nd)
		{
			free(nd);
			nd = NULL;
		}
	}
}

t_stack	creat_node(void)
{
	t_stack	node;

	node = malloc(sizeof(struct s_stack) * 1);
	node->prev = NULL;
	node->next = NULL;
	node->value = 0;
	return (node);
}
