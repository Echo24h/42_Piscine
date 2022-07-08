/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 05:21:50 by gborne            #+#    #+#             */
/*   Updated: 2021/07/20 13:51:27 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s;

	s = malloc(sizeof(*s) * (ac + 1));
	if (!(s))
		return (0);
	i = 0;
	while (i < ac && av[i] != 0)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = ft_strdup(av[i]);
		s[i].copy = ft_strdup(s[i].str);
		i++;
	}
	s[i].size = 0;
	s[i].str = 0;
	s[i].copy = 0;
	return (s);
}
