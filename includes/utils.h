/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:42:04 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:42:07 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int						ft_atoi(const char *str);
int						ft_strlen(const char *str);
char					*ft_strdup(const char *src);
unsigned int			get_length(int n);
char					*ft_itoa(int n);
long					ft_strcmp(char *str, char *str2);

#endif
