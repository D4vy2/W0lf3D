/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 14:35:07 by dea               #+#    #+#             */
/*   Updated: 2015/11/10 17:36:09 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void 	ft_teleport(t_env *e)
{
	if (e->map_x == 4 && e->map_y == 8 \
		&& (int)e->pos_x == 5 && (int)e->pos_y == 8)
	{
		e->pos_x = 18;
		e->pos_y = 6;
		e->teleporting = 1;
	}
	else if (e->map_x == 19 && e->map_y == 5 \
		&& (int)e->pos_x == 18 && (int)e->pos_y == 6)
	{
		e->pos_x = 6;
		e->pos_y = 8;
		e->teleporting = 1;
	}
	else if (e->map_x == 13 && e->map_y == 21 \
		&& (int)e->pos_x == 13 && (int)e->pos_y == 22)
	{
		e->you_win = 1;
	}
}

int 	loop_hook(t_env *e)
{
	if (e->pause == 1 && e->teleporting == 0)
	{
		ft_calcul_and_draw(e);
		mlx_string_put(e->mlx, e->win, 230, 170, 0xFFFFA8, "PAUSED");
		return (0);
	}
	if (e->key_up == 1 && e->teleporting == 0)
		ft_move_front(e);
	if (e->key_down == 1 && e->teleporting == 0)
		ft_move_back(e);
	if (e->key_left == 1 && e->teleporting == 0)
		ft_move_left(e);
	if (e->key_right == 1 && e->teleporting == 0)
		ft_move_right(e);
	ft_teleport(e);
	if (e->teleporting == 1)
	{
		mlx_string_put(e->mlx, e->win, 200, 170, 0x92EDF7,\
				"TELEPORTING...");
		return (0);
	}
	if (e->you_win == 1)
	{
		mlx_string_put(e->mlx, e->win, 200, 170, 0x92EDF7,\
				"***** YOU WIN *****...");
		return (0);
	}
	ft_calcul_and_draw(e);
	/* printf("map_x %d - map_y %d\n", e->map_x, e->map_y); */
	/* printf("pos_x %d - pos_y %d\n", (int)e->pos_x, (int)e->pos_y); */
	return (0);
}


int		main(int argc, char **argv)
{
	t_env e;

	ft_check_error(argc, argv);
	e = ft_open_file(argc, argv, e);
	ft_init(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.screen_width, e.screen_height, "wolf3d");
	e.img = mlx_new_image(e.mlx, e.screen_width, e.screen_height);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_hook(e.win, 2, (1L<<0), &ft_press_key, &e);
	mlx_hook(e.win, 3, (1L<<1), &ft_release_key, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
