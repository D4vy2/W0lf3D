/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 14:30:48 by dea               #+#    #+#             */
/*   Updated: 2015/10/30 14:34:54 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		*ft_convert_atoi(char *s)
{
	int	*tab;
	int	len;
	int	i;
	char	**chartab;

	i = 0;
	len = ft_count_points(s);
	if (NULL == (tab = (int*)malloc(sizeof(int) * len)))
		return (NULL);
	chartab = ft_strsplit(s, ' ');
	while (i < len)
	{
		tab[i] = ft_atoi(chartab[i]);
		free(chartab[i]);
		i++;
	}
	free(chartab);
	return (tab);
}

int		**ft_convert_map(char **map, t_env vmax)
{
	int len;
	int i;
	int **tab;
	int **ptr;

	i = 0;
	len = ft_return_ymax(map);
	vmax.ymax = len;
	if (NULL == (tab = (int**)malloc(sizeof(int*) * len)))
		return (NULL);
	ptr = tab;
	while (i < len)
	{
		tab[i] = ft_convert_atoi(map[i]);
		i++;
	}
	tab = ptr;
	return (tab);
}

static int 	ft_count_line(char *save)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

static char 	**ft_split_map(int ret, char **map, char *save)
{
	ft_check_ret(ret);
	map = ft_strsplit(save, '\n');
	map[ft_count_line(save)] = NULL;
	free(save);
	return (map);
}

char	**ft_return_map(int fd, int ret)
{
	int	len_map;
	char	*save;
	char	**map;
	char	*temp;
	char 	buf[BUFF_SIZE];

	len_map = 0;
	save = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		if (!save)
			save = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(save, buf);
			free(save);
			save = temp;
		}
	}
	map = ft_split_map(ret, map, save);
	return (map);
}
