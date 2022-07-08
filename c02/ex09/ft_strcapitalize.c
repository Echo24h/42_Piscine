/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 03:03:05 by gborne            #+#    #+#             */
/*   Updated: 2021/07/11 04:40:45 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	capitalize(char *str, int i);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	capitalize(str, i);
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z'))
			&& (!(str[i - 1] >= '0' && str[i - 1] <= '9'))
			&& (!(str[i - 1] >= 'a' && str[i - 1] <= 'z')))
			capitalize(str, i);
		else if ((str[i] >= 'A' && str[i] <= 'Z')
			&& ((str[i - 1] >= 'a' && str[i - 1] <= 'z')
				|| (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')))
			capitalize(str, i);
		i++;
	}
	return (str);
}		

void	capitalize(char *str, int i)
{	
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	else if (str[i] >= 'A' && str[i] <= 'Z')
		str[i] += 32;
}
