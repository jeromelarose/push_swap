/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:40:20 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:40:25 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

# include <stdlib.h>

unsigned int	count_word(char const *s, char c);
char			*fill_cell(char const *s, char c, unsigned int index);
int				fill_array(char **array, char const *s, char c);
void			free_double_array(char **array);
char			**ft_split(const char *str, char charset);

#endif
