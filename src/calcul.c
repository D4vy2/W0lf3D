/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/06 12:53:13 by dea               #+#    #+#             */
/*   Updated: 2015/11/10 17:34:19 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_calc_player_to_wall(t_env *e)
{
	e->hit = 0;
	if (e->ray_dir_x < 0) // si le rayon est oriente vers la gauche
	{
		e->etape_x = -1;
		e->dist_mur_x = (e->ray_pos_x - e->map_x) * e->dist_2murs_x;
	}
	else // rayon vers la droite
	{
		e->etape_x = 1;
		e->dist_mur_x = (e->map_x + 1.0 - e->ray_pos_x) 
			* e->dist_2murs_x;
	}
	if (e->ray_dir_y < 0) // si le rayon est oriente vers la gauche
	{
		e->etape_y = -1;
		e->dist_mur_y = (e->ray_pos_y - e->map_y) * e->dist_2murs_y;
	}
	else // vers la droite
	{
		e->etape_y = 1;
		e->dist_mur_y = (e->map_y + 1.0 - e->ray_pos_y) 
			* e->dist_2murs_y;
	}
}

void	ft_dda(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->dist_mur_x < e->dist_mur_y)
		{
			e->dist_mur_x += e->dist_2murs_x;
			e->map_x += e->etape_x;
			e->side = 0; // mur vertical
		}
		else
		{
			e->dist_mur_y += e->dist_2murs_y;
			e->map_y += e->etape_y;
			e->side = 1; // mur vertical
		}
		if (e->tab[e->map_x][e->map_y] > 0)
			e->hit = 1;
	}
}

void 		ft_ray_position_and_direction(t_env *e)
{
		e->camera_x = 2 * e->x / (double)e->screen_width - 1;
		e->ray_pos_x = e->pos_x;
		e->ray_pos_y = e->pos_y;
		e->ray_dir_x = e->dir_x + e->plane_x * e->camera_x;
		e->ray_dir_y = e->dir_y + e->plane_y * e->camera_x;
}

void 		ft_calc_next_wall(t_env *e)
{
	if (e->side == 0)
		e->longueur_mur = fabs((e->map_x - e->ray_pos_x
					+ (1 - e->etape_x) / 2) / e->ray_dir_x);
	else
		e->longueur_mur = fabs((e->map_y - e->ray_pos_y
					+ (1 - e->etape_y) / 2) / e->ray_dir_y);

	e->hauteur_mur = fabs(e->screen_height / e->longueur_mur);

	e->draw_start = -(e->hauteur_mur) / 2 + e->screen_height / 2;
	if (e->draw_start < 0)
		e->draw_start = 0;
	e->draw_end = e->hauteur_mur / 2 + e->screen_height / 2;
	if (e->draw_end >= e->screen_height)
		e->draw_end = e->screen_height - 1;
}

int		ft_calcul_and_draw(t_env *e)
{
	e->x = 0;
	/* ft_bzero(e->data, e->screen_width * e->screen_height * 4); */
	mlx_clear_window(e->mlx, e->win);
	while (e->x < e->screen_width)
	{

		ft_ray_position_and_direction(e);
		e->map_x = (int)e->ray_pos_x;
		e->map_y = (int)e->ray_pos_y;
		e->dist_2murs_x = sqrt(1 + (e->ray_dir_y * e->ray_dir_y) 
				/ (e->ray_dir_x * e->ray_dir_x));
		e->dist_2murs_y = sqrt(1 + (e->ray_dir_x * e->ray_dir_x) 
				/ (e->ray_dir_y * e->ray_dir_y));
		ft_calc_player_to_wall(e);
		ft_dda(e);
		ft_calc_next_wall(e);
		ft_draw(e);
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
