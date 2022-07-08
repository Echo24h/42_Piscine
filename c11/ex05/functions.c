/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:44:38 by mea               #+#    #+#             */
/*   Updated: 2021/07/28 11:53:54 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "doop.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int		nombre;
	int		signe;
	char	*charptr;

	nombre = 0;
	signe = 1;
	charptr = str;
	while (*charptr == ' ' || (*charptr >= 9 && *charptr <= 13))
	{
		charptr++;
	}
	while (*charptr == '-' || *charptr == '+')
	{
		if (*charptr == '-')
			signe *= -1;
		charptr++;
	}
	while (*charptr >= '0' && *charptr <= '9')
	{
		nombre *= 10;
		nombre += (int)(*charptr - '0');
		charptr++;
	}
	return (nombre * signe);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + nb % 10);
	}
	else if (nb <= 9 && nb >= 0)
	{
		ft_putchar('0' + nb);
	}
}

int	calcul(int a, int b, char **argv)
{
	if (argv[2][0] == '*')
		ft_putnbr((a * b));
	else if (argv[2][0] == '-')
		ft_putnbr((a - b));
	else if (argv[2][0] == '+')
		ft_putnbr((a + b));
	else if (argv[2][0] == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	else if (argv[2][0] == '/')
		ft_putnbr((a / b));
	else if (argv[2][0] == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	else if (argv[2][0] == '%')
		ft_putnbr((a % b));
	else
		write (1, &"0", 1);
	write(1, &"\n", 1);
	return (0);
}
