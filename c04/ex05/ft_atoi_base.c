/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:44:19 by gborne            #+#    #+#             */
/*   Updated: 2021/07/21 13:37:55 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_base(char str, char *base);
int	ft_check(char *base);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	convert_int(char *str, char *base)
{
	unsigned int	n;
	int				i;

	n = 0;
	while (*str && ft_check_base(*str, base))
	{
		i = 0;
		n *= ft_strlen(base);
		while (base[i])
		{
			if (*str == base[i])
				break ;
			i++;
		}
		n += i;
		str++;
	}
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	int				sign;

	sign = 1;
	if (!ft_check(base))
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return ((int)convert_int(str, base) * sign);
}

int	ft_check_base(char str, char *base)
{
	while (*base)
	{
		if (*base == str)
			return (1);
		base++;
	}
	return (0);
}

int	ft_check(char *base)
{
	int	i;
	int	k;

	i = 0;
	while (base[i])
	{
		k = 1;
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == ' ')
			return (0);
		while (base[i + k])
		{
			if (base[i] == base[i + k])
				return (0);
			k++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}
