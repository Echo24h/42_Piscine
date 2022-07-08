#include "ft.h"

void	check_abcd(int *param, int l, int **mapint)
{
	if (param[16] == 0 && param[15] > 0)
	{
		param[10] = 0;
		param[11] = 0;
		param[12] = mapint[param[16] + l][param[15] - 1];
	}
	else if (param[15] == 0 && param[16] > 0)
	{
		param[10] = 0;
		param[11] = mapint[param[16] - 1][param[15] + l];
		param[12] = 0;
	}
	else if (param[15] == 0 && param[16] == 0)
	{
		param[10] = 0;
		param[11] = 0;
		param[12] = 0;
	}
	else
	{
		param[10] = mapint[param[16] - 1][param[15] - 1];
		param[11] = mapint[param[16] - 1][param[15] + l];
		param[12] = mapint[param[16] + l][param[15] - 1];
	}
	param[13] = mapint[param[16] + l][param[15] + l];
}

int	check_sqrt(int **mapint, int *param, int l, char **map)
{
	int	value;

	if (map[param[16]][param[15]] == param[2])
		return (0);
	value = 0;
	if (param[15] + 1 == param[4] || param[16] + 1 == param[0])
		return (1);
	while (value <= 0 && (param[15] + l) < param[4]
		&& (param[16] + l) < param[0])
	{
		check_abcd(param, l, mapint);
		value = param[10] + param[13] - param[11] - param[12];
		l++;
	}
	if (l == 0 && map[param[16]][param[15]] == param[1])
		return (1);
	if (l <= 0)
		return (0);
	else
		return (l - 1);
}

void	search_sqrt(int **mapint, int *param, char **map)
{
	int	l;
	int	x_square;
	int	y_square;

	x_square = 0;
	y_square = 0;
	l = 0;
	while ((param[16] + l) < param[0])
	{
		while ((param[15] + l) < param[4])
		{
			if (check_sqrt(mapint, param, l, map) > l)
			{
				l = check_sqrt(mapint, param, l, map);
				x_square = param[15];
				y_square = param[16];
			}
			param[15]++;
		}
		param[15] = 0;
		param[16]++;
	}
	param[18] = l;
	map_writing(map, param, x_square, y_square);
}
