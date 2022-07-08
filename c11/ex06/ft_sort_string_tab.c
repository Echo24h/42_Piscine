void	ft_swap_tab(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] - s2[i] < 0)
		return (-1);
	else if (s1[i] - s2[i] == 0)
		return (0);
	else
		return (1);
}

int	len_string_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count + 1] != 0)
	{
		if (ft_strcmp(tab[count], tab[count + 1]) == 1)
		{
			ft_swap_tab(&tab[count], &tab[count + 1]);
			count = 0;
		}
		else
			count++;
	}
}
