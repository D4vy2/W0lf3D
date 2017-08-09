#include "wolf3d.h"

void	ft_color_pix(t_env *e, unsigned int color)
{
	int c;

	c = e->x * 4 + e->sizeline * e->draw_start;
	e->data[c] = color;
	e->data[c + 1] = (color >> 8);
	e->data[c + 2] = (color >> 16);
}

void	ft_color_sky(t_env *e, unsigned int color)
{
	int c;

	c = e->x * 4 + e->sizeline * e->sky;
	e->data[c] = color;
	e->data[c + 1] = (color >> 8);
	e->data[c + 2] = (color >> 16);
}

void	ft_set_color(t_env *e)
{
	if (e->day_n_night == DAY)
		day_color(e);
	else if (e->day_n_night == NIGHT)
		night_color(e);
	else if (e->day_n_night == PAUSE)
	{
		e->color_sky = mlx_get_color_value(e->mlx, 0x000000);
		e->color_floor = mlx_get_color_value(e->mlx, 0x000000);
		e->color = mlx_get_color_value(e->mlx, 0x000000);
	}
	else if (e->day_n_night == WIN)
	{
		e->color_sky = mlx_get_color_value(e->mlx, 0x0043FC);
		e->color_floor = mlx_get_color_value(e->mlx, 0x0043FC);
		e->color = mlx_get_color_value(e->mlx, 0x0043FC);
	}
}

void	day_color(t_env *e)
{
	e->color_sky = mlx_get_color_value(e->mlx, 0x87CEFA);
	e->color_floor = mlx_get_color_value(e->mlx, 0x666666);
	if (e->tab[e->map_x][e->map_y] == 1)
		e->color = mlx_get_color_value(e->mlx, 0xFA8080); //red
	else if (e->tab[e->map_x][e->map_y] == 2)
		e->color = mlx_get_color_value(e->mlx, 0x98FFC5); // green
	else if (e->tab[e->map_x][e->map_y] == 3)
		e->color = mlx_get_color_value(e->mlx, 0xFFB6C1); // pink
	else if (e->tab[e->map_x][e->map_y] == 4)
		e->color = mlx_get_color_value(e->mlx, 0xffffff); //white

	else if (e->tab[e->map_x][e->map_y] == 9)
		e->color = mlx_get_color_value(e->mlx, 0x000000); //black

	else
		e->color = mlx_get_color_value(e->mlx, 0xFFEC8B); //yellow
}

void	night_color(t_env *e)
{
	e->color_sky = 0x011f4b;
	e->color_floor = 0x333333;
	if (e->tab[e->map_x][e->map_y] == 1)
		e->color = mlx_get_color_value(e->mlx, 0x380f0f); //brown
	else if (e->tab[e->map_x][e->map_y] == 2)
		e->color = mlx_get_color_value(e->mlx, 0x10380f); // green
	else if (e->tab[e->map_x][e->map_y] == 3)
		e->color = mlx_get_color_value(e->mlx, 0x450749); // pink
	else if (e->tab[e->map_x][e->map_y] == 4)
		e->color = mlx_get_color_value(e->mlx, 0x5c5d60); //white

	else if (e->tab[e->map_x][e->map_y] == 9)
		e->color = mlx_get_color_value(e->mlx, 0x000000); //black

	else
		e->color = mlx_get_color_value(e->mlx, 0x716e00); //yellow
}
