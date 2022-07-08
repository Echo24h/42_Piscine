/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 22:27:41 by gborne            #+#    #+#             */
/*   Updated: 2021/07/20 11:41:31 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{	
	int	i;
	int	j;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (1)
		{
			if (to_find[j] == '\0')
				return (&str[i]);
			if (str[i + j] != to_find[j])
				break ;
			j++;
		}
		i++;
	}
	return (0);
}
