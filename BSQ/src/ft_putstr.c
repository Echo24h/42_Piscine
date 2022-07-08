#include "ft.h"

void	ft_putstr(char *str)
{
	int	i;
	int	character;

	i = 0;
	while (str[i] != '\0')
	{
		character = str[i];
		write(1, &character, 1);
		i++;
	}
}
