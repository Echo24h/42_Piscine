/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 01:46:54 by gborne            #+#    #+#             */
/*   Updated: 2021/07/17 15:20:26 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] - s2[i] < 0)
		return (-1);
	else if (s1[i] - s2[i] == 0)
		return (0);
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int		count;
	char	*temp;

	if (argc < 2)
		return (0);
	count = 1;
	while (count < argc - 1)
	{
		if (ft_strcmp(argv[count + 1], argv[count]) == 1)
		{
			temp = argv[count];
			argv[count] = argv[count + 1];
			argv[count + 1] = temp;
			count = 0;
		}
		count++;
	}
	while (count > 0)
	{
		ft_putstr(argv[count]);
		count--;
	}
}
