/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 15:09:57 by dea               #+#    #+#             */
/*   Updated: 2015/11/10 17:20:04 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void 	ft_pause_menu(t_env *e)
{
	if (e->pause == 1)
	{
		e->day_n_night = e->tmp_day_n_night;
		e->pause = 0;
	}
	else if (e->pause == 0)
	{
		e->pause = 1;
		e->tmp_day_n_night = e->day_n_night;
		e->day_n_night = PAUSE;
	}
}

int		ft_press_key(int keycode, t_env *e)
{
	keycode == ESC ? exit(0) : 0;
	if (keycode == PAUSE)
		ft_pause_menu(e);
	if (e->pause == 0)
	{
		if (keycode == SPEEDDOWN && e->speed <= 30)
			e->speed++;
		if (keycode == SPEEDUP && e->speed > 5)
			e->speed--;
		if (keycode == UP)
			e->key_up = 1;
		if (keycode == DOWN)
			e->key_down = 1;
		if (keycode == LEFT)
			e->key_left = 1;
		if (keycode == RIGHT)
			e->key_right = 1;
		if (keycode == RESTART)
			ft_init(e);
		keycode == DAY ? e->day_n_night = DAY : 0;
		keycode == NIGHT ? e->day_n_night = NIGHT : 0;
	}
	return (0);
}

int 		ft_release_key(int keycode, t_env *e)
{
	if ((keycode == UP || keycode == DOWN || \
		keycode == LEFT || keycode == RIGHT) && e->teleporting == 1)
	{
		if (e->you_win == 1)
			exit(0);
		e->teleporting = 0;
		ft_calcul_and_draw(e);
	}
	if (keycode == UP)
		e->key_up = 0;
	if (keycode == DOWN)
		e->key_down = 0;
	if (keycode == LEFT)
		e->key_left = 0;
	if (keycode == RIGHT)
		e->key_right = 0;
	return (0);
}
