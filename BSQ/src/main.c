#include "ft.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
	{
		if (!manage_stand())
			ft_putstr("map error");
	}
	else
	{
		while (i < ac)
		{
			if (!manage_map(av[i]))
				ft_putstr("map error");
			if (!(i == ac - 1))
				ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
