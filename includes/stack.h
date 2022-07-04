/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:41:52 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:41:54 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "stack.h"
# include "utils.h"

typedef struct s_stack {
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
}				*t_stack;

int			is_empty(t_stack stack);
void		print_stack(t_stack stack);
void		free_stack(t_stack nd);
t_stack		creat_node(void);

#endif
