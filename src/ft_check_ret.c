/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 16:47:40 by dea               #+#    #+#             */
/*   Updated: 2015/10/30 14:54:06 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_check_ret(int ret)
{
	if (ret == -1)
	{
		perror("argv[1]");
		exit(0);
	}
}

void	ft_check_map(char **map, t_env *e)
{
	int i;
	int nbr;

	i = 0;
	nbr = e->xmax;
	while (i < e->ymax)
	{
		/* ft_count_points(map[i]); */
		if (nbr != ft_count_points(map[i]))
		{
			ft_putstr("Invalid: Map not well formatted.\n");
			exit(0);
		}
		free(map[i]);
		i++;
	}
}
