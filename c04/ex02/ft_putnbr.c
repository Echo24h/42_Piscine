/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:44:46 by gborne            #+#    #+#             */
/*   Updated: 2021/07/14 18:00:25 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	unb;

	if (nb < 0)
	{
		ft_putchar('-');
		unb = nb * -1;
	}
	else
		unb = nb;
	if (unb > 9)
	{
		ft_putnbr(unb / 10);
		unb = unb % 10;
	}
	ft_putchar(unb % 10 + 48);
}
