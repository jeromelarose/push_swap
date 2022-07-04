/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelarose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:59:56 by jelarose          #+#    #+#             */
/*   Updated: 2022/03/23 14:59:58 by jelarose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	res;

	res = 0;
	neg = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!ret)
		return (NULL);
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

unsigned int	get_length(int n)
{
	unsigned int	negative;
	unsigned int	size;

	size = 1;
	negative = 0;
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		size++;
	}
	return (size + negative);
}

char	*ft_itoa(int n)
{
	int				n_copy;
	char			*result;
	unsigned int	size;

	n_copy = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = get_length(n);
	if (n < 0)
		n = -n;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	while (n > 9)
	{
		result[--size] = n % 10 + 48;
		n = n / 10;
	}
	if (n % 10 != 0 || (n == 0 && size == 1))
		result[--size] = n % 10 + 48;
	if (n_copy < 0)
		result[--size] = '-';
	return (result);
}
