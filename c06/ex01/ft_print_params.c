/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 16:30:13 by gborne            #+#    #+#             */
/*   Updated: 2021/07/15 20:41:28 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;
	int		character;
	char	n;

	n = '\n';
	i = 0;
	while (*str != '\0')
	{
		character = *str;
		write(1, &character, 1);
		str++;
	}
	write(1, &n, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	(void) argc;
	while (argv[i])
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
