/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:27:56 by gborne            #+#    #+#             */
/*   Updated: 2021/07/15 16:50:49 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	total;

	total = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	nb--;
	while (nb > 0)
	{
		total *= nb;
		nb--;
	}
	return (total);
}
