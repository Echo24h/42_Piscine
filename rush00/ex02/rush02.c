/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:15:40 by gborne            #+#    #+#             */
/*   Updated: 2021/07/10 15:21:30 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_putchar(char c);
void	print_first_width(int x, int width);
void	print_mid_width(int x, int width);
void	print_last_width(int x, int width);

void	rush(int width, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < height)
	{
		if (y == 0)
			print_first_width(x, width);
		else if (y == (height - 1))
			print_last_width(x, width);
		else
			print_mid_width(x, width);
		y++;
	}
}

void	print_first_width(int x, int width)
{
	while (x < width)
	{
		if (x == 0 || x == (width - 1))
			ft_putchar('A');
		else
			ft_putchar('B');
		x++;
	}
	ft_putchar('\n');
}

void	print_mid_width(int x, int width)
{
	while (x < width)
	{
		if (x == 0 || x == (width - 1))
			ft_putchar('B');
		else
			ft_putchar(' ');
		x++;
	}
	ft_putchar('\n');
}

void	print_last_width(int x, int width)
{
	while (x < width)
	{
		if (x == 0 || x == (width - 1))
			ft_putchar('C');
		else
			ft_putchar('B');
		x++;
	}
	ft_putchar('\n');
}
