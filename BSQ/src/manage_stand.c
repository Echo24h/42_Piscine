#include "ft.h"

int	manage_stand(void)
{
	char	**map;
	int		param[6];
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = manage_initstand(param);
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

char	*init_buffstand(void)
{
	char	c;
	char	*buff;
	int		i;

	buff = malloc(sizeof(char) * (100000));
	i = 0;
	while (read(0, &c, 1) != 0)
	{
		buff[i] = c;
		i++;
	}
	buff[i + 1] = '\0';
	return (buff);
}

char	**manage_initstand(int *param)
{
	char	*buff;
	char	**map;

	buff = init_buffstand();
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
