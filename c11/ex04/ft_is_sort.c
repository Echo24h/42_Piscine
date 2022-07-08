int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int		i;
	int		croissant;
	int		decroissant;

	i = 0;
	croissant = 0;
	decroissant = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			croissant++;
		if (f(tab[i], tab[i + 1]) <= 0)
			decroissant++;
		i++;
	}
	if (i == croissant || i == decroissant)
		return (1);
	return (0);
}
