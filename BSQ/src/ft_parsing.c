#include "ft.h"

int	manage_map(char *file)
{
	char	**map;
	int		param[20];
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = manage_init(file, param);
	if (!map)
		return (0);
	while (map[y])
	{
		while (x < param[4])
			x++;
		y++;
		x = 0;
	}
	map_parsing(map, param);
	return (1);
}

void	fill_map(char **map, int *param, char *buff)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = (param[5] + 1);
	while (map[y])
	{
		while (x < param[4])
		{
			if (buff[i] == param[1])
				map[y][x] = param[1];
			else
				map[y][x] = param[2];
			x++;
			i++;
		}
		y++;
		i++;
		x = 0;
	}
}

char	**create_map(char *buff, int *param)
{
	char	**map;

	map = init_map(param[4], param[0]);
	if (!map)
		return (NULL);
	fill_map(map, param, buff);
	return (map);
}

char	**manage_init(char *file, int *param)
{
	char	*buff;
	char	**map;

	buff = init_buff(file);
	if (!buff)
		return (NULL);
	if (!init_param(buff, param))
		return (NULL);
	if (!check_map(buff, param))
		return (NULL);
	map = create_map(buff, param);
	free(buff);
	if (!map)
		return (NULL);
	return (map);
}
