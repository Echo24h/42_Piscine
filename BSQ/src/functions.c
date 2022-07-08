#include "ft.h"

void	map_writing(char **map, int *param, int x, int y)
{
	int	x_start;
	int	x_end;
	int	y_end;

	if (y == 0 && param[0] != 1 && param[4] != 1)
		param[18]++;
	x_end = x + param[18];
	y_end = y + param[18];
	x--;
	y--;
	x_start = x;
	while (++y < y_end)
	{
		while (++x < x_end)
			map[y][x] = param[3];
		x = x_start;
	}
}

int	**init_mapint(int x_max, int y_max)
{
	int	i;
	int	**mapint;

	i = 0;
	mapint = (int **)malloc(sizeof(int *) * (y_max + 1));
	if (!mapint)
		return (NULL);
	while (i < y_max)
	{
		mapint[i] = malloc(sizeof(int *) * (x_max + 1));
		if (!mapint[i])
			return (NULL);
		i++;
	}
	mapint[i] = 0;
	return (mapint);
}

void	map_shading(int **mapint, int *p)
{
	int	value;

	p[17] = -1;
	p[19] = -1;
	value = 0;
	while (mapint[++p[19]])
	{
		while (++p[17] < p[4])
		{
			if (p[19] == 0)
			{
				if (mapint[p[19]][p[17]] != 0)
					value++;
				mapint[p[19]][p[17]] = value;
			}
			else if (p[19] > 0)
			{
				if (mapint[p[19]][p[17]] != 0)
					value++;
				mapint[p[19]][p[17]] = value + mapint[p[19] - 1][p[17]];
			}
		}
		p[17] = -1;
		value = 0;
	}
}

void	print_map(char **map, int *param)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++y])
	{
		while (++x < param[4])
		{
			ft_putchar(map[y][x]);
		}
		ft_putchar('\n');
		x = -1;
	}
}

void	map_parsing(char **map, int *param)
{
	int	x;
	int	y;
	int	**mapint;

	x = -1;
	y = -1;
	mapint = init_mapint(param[4], param[0]);
	while (map[++y])
	{
		while (++x < param[4])
		{
			if (map[y][x] == param[1])
				mapint[y][x] = 0;
			if (map[y][x] == param[2])
				mapint[y][x] = 1;
		}
		x = -1;
	}
	map_shading(mapint, param);
	search_sqrt(mapint, param, map);
	print_map(map, param);
}
