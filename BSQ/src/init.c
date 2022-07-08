#include "ft.h"

char	*init_buff(char *file)
{
	int		fd;
	char	c;
	char	*buff;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		i++;
	buff = malloc(sizeof(char) * (i + 1));
	if (!buff || fd < 0)
		return (NULL);
	close(fd);
	buff[i + 1] = '\0';
	i = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &c, 1))
	{
		buff[i] = c;
		i++;
	}
	close(fd);
	return (buff);
}

char	**init_map(int x_max, int y_max)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (y_max + 1));
	if (!map)
		return (NULL);
	while (i < y_max)
	{
		map[i] = malloc(sizeof(char *) * (x_max + 1));
		if (!map[i])
			return (NULL);
		i++;
	}
	map[i] = 0;
	return (map);
}

int	detect_x(char *buff)
{
	int	x;
	int	sub;

	sub = 0;
	while (buff[sub] != '\n')
		sub++;
	sub++;
	x = 0;
	while (buff[x + sub] != '\n')
		x++;
	return (x);
}

int	detect_y(char *buff, int *param)
{
	int	num;
	int	imax;
	int	i;

	num = 0;
	imax = 0;
	while (buff[imax] != '\n')
		imax++;
	param[5] = imax;
	i = 0;
	while (buff[i] >= '0' && buff[i] <= '9' && i < param[5] - 3)
	{
		num = num * 10 + (buff[i] - 48);
		i++;
	}
	return (num);
}

int	init_param(char *buff, int *param)
{
	param[4] = detect_x(buff);
	param[0] = detect_y(buff, param);
	if (param[0] == 0 || param[4] == 0)
		return (0);
	param[1] = buff[param[5] - 3];
	param[2] = buff[param[5] - 2];
	param[3] = buff[param[5] - 1];
	param[15] = 0;
	param[16] = 0;
	if (param[1] == param[2] || param[1] == param[3]
		|| param[2] == param[3])
		return (0);
	return (1);
}
