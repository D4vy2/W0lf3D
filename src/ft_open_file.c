/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 14:29:43 by dea               #+#    #+#             */
/*   Updated: 2015/10/30 15:01:45 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env	ft_open_file(int argc, char **argv, t_env e)
{
	char	**map;
	int		fd;
	int		ret;

	ret = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Open() failed");
		exit(0);
	}
	map = ft_return_map(fd, ret);
	e.ymax = ft_return_ymax(map);
	e.xmax = ft_count_points(map[0]);
	e.tab = ft_convert_map(map, e);
	ft_check_map(map, &e);
	free(map);
	close(fd);
	return (e);
}

void	ft_init(t_env *e)
{
	e->screen_width = 512;
	e->screen_height = 384;
	e->pos_x = 4;
	e->pos_y = 4;
	e->dir_x = -1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->time = 0;
	e->oldtime = 0;
	e->speed = 20;
	e->color_sky = mlx_get_color_value(e->mlx, 0x87CEFA);
	e->color_floor = mlx_get_color_value(e->mlx, 0x666666);
	e->day_n_night = DAY;
	e->tmp_day_n_night = e->day_n_night;
	e->pause = 0;
	e->key_up = 0;
	e->key_down = 0;
	e->key_left = 0;
	e->key_right = 0;
	e->teleporting = 0;
	e->win = 0;
}
