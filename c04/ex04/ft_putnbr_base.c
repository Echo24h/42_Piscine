/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 01:35:23 by gborne            #+#    #+#             */
/*   Updated: 2021/07/20 12:57:40 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (base[i] != '\0')
	{
		k = 0;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[k] != '\0')
		{
			if (base[i] == base[k] && i != k)
				return (0);
			k++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;

	if (!check_base(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		nb = nb % ft_strlen(base);
	}
	ft_putchar(base[nb % ft_strlen(base)]);
}
