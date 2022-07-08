/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:35:38 by gborne            #+#    #+#             */
/*   Updated: 2021/07/08 17:45:29 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;
	int	character;

	i = 0;
	while (str[i] != '\0')
	{
		character = str[i];
		write(1, &character, 1);
		i++;
	}
}
