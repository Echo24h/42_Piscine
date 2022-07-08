/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:56:24 by gborne            #+#    #+#             */
/*   Updated: 2021/07/20 09:49:33 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	calcul_malloc(int size, char **strs, char *sep)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	while (i < size)
	{
		t += ft_strlen(strs[i]);
		t += ft_strlen(sep);
		i++;
	}
	t -= ft_strlen(sep);
	return (t);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char *) * (calcul_malloc(size, strs, sep) + 1));
	if (!(dest))
		return (0);
	if (size == 0)
	{
		return (dest);
	}
	while (i < size)
	{
		if (i == size - 1)
		{
			ft_strcat(dest, strs[i]);
			break ;
		}
		ft_strcat(dest, strs[i]);
		ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
