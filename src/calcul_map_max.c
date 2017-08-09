#include "wolf3d.h"

int		ft_return_ymax(char **tab)
{
	int len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

int		ft_count_points(char *s)
{
	int i;
	int points;

	i = 0;
	points = 0;
	while (s[i])
	{
		while (s[i] == ' ' && s[i])
			i++;
		if (s[i] != ' ' && s[i])
		{
			points++;
			while (s[i] != ' ' && s[i])
				i++;
		}
	}
	return (points);
}
