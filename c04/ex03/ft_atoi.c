/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 23:17:54 by gborne            #+#    #+#             */
/*   Updated: 2021/07/14 18:55:00 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	convert_str_in_int(char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int	np;

	np = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			np++;
		str++;
	}
	if (np % 2 == 0)
		return (convert_str_in_int(str));
	else
		return (-convert_str_in_int(str));
}
