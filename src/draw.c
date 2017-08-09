/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 12:00:34 by dea               #+#    #+#             */
/*   Updated: 2015/11/10 17:31:19 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->pause == 1)
		mlx_string_put(e->mlx, e->win, 230, 170, 0xFFFFA8, "PAUSED");
	return (0);
}

void		ft_draw(t_env *e)
{
	e->sky = 0;
	ft_set_color(e);
	while (e->sky < e->draw_start)
	{
		ft_color_sky(e, e->color_sky);
		e->sky++;
	}
	if (e->side == 1 && e->day_n_night != PAUSE)
		e->color /= 2;
	while (e->draw_start <= e->draw_end)
	{
		ft_color_pix(e, e->color);
		e->draw_start++;
	}
	while (e->draw_start < e->screen_height)
	{
		ft_color_pix(e, e->color_floor);
		e->draw_start++;
	}
}
