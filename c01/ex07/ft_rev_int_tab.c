/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:20:08 by gborne            #+#    #+#             */
/*   Updated: 2021/07/08 19:27:08 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	min;
	int	max;
	int	temp;

	max = size - 1;
	min = 0;
	while (min < max)
	{
		temp = tab[max];
		tab[max] = tab[min];
		tab[min] = temp;
		max--;
		min++;
	}
}
