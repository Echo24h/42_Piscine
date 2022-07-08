#include "ft.h"

int	check_map(char *buff, int *param)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = param[5];
	while (y < param[0])
	{
		while (x < param[4])
		{
			if (buff[i] != param[1] && buff[i] != param[2] && buff[i] != '\n')
				return (0);
			x++;
			i++;
		}
		if (buff[i + 1] != '\n')
			return (0);
		x = 0;
		i++;
		y++;
	}
	return (1);
}
