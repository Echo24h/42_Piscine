/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:49:44 by gborne            #+#    #+#             */
/*   Updated: 2021/07/22 18:24:08 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	test_caracter(char caracter, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (caracter == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	words_count(char *str, char *charset)
{
	int	newword;
	int	count;
	int	i;

	newword = 1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (test_caracter(str[i], charset))
			newword = 1;
		else if (!test_caracter(str[i], charset) && newword == 1)
		{
			count++;
			newword = 0;
		}
		i++;
	}
	return (count);
}

void	str_split(char *str, char *charset, char **tab, int nbwords)
{
	int	j;
	int	i;
	int	lenword;

	i = -1;
	while (++i < nbwords)
	{
		j = -1;
		lenword = 0;
		while (!test_caracter(str[++j], charset) && str[j])
			lenword++;
		tab[i] = malloc(sizeof(char *) * (lenword + 1));
		j = -1;
		while (!test_caracter(*str, charset) && *str)
		{
			tab[i][++j] = *str;
			str++;
		}
		while (test_caracter(*str, charset) && *str)
			str++;
		tab[i][++j] = 0;
	}
	tab[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nbwords;

	while (*str && test_caracter(*str, charset))
		str++;
	if (!*str)
	{
		tab = malloc(sizeof(char *));
		*tab = 0;
	}
	else
	{
		nbwords = words_count(str, charset);
		tab = malloc(sizeof(char *) * (nbwords + 1));
		if (!tab)
			return (0);
		str_split(str, charset, tab, nbwords);
	}
	return (tab);
}
