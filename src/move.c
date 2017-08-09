#include "wolf3d.h"

void 		ft_move_left(t_env *e)
{
	double olddir_x = e->dir_x;
	double oldplane_x = e->plane_x;
	e->dir_x = e->dir_x * cos(ROTATION) - e->dir_y * sin(ROTATION);
	e->dir_y = olddir_x * sin(ROTATION) + e->dir_y * cos(ROTATION);
	e->plane_x = e->plane_x * cos(ROTATION) - e->plane_y * sin(ROTATION);
	e->plane_y = oldplane_x * sin(ROTATION) + e->plane_y * cos(ROTATION);
}

void 		ft_move_right(t_env *e)
{
	double olddir_x = e->dir_x;
	double oldplane_x = e->plane_x;
	e->dir_x = e->dir_x * cos(-ROTATION) - e->dir_y * sin(-ROTATION);
	e->dir_y = olddir_x * sin(-ROTATION) + e->dir_y * cos(-ROTATION);
	e->plane_x = e->plane_x * cos(-ROTATION) - e->plane_y * sin(-ROTATION);
	e->plane_y = oldplane_x * sin(-ROTATION) + e->plane_y * cos(-ROTATION);
}

void 	ft_move_front(t_env *e)
{
	if (!e->tab[(int)(e->pos_x + e->dir_x)][(int)e->pos_y])
		e->pos_x += e->dir_x / e->speed;
	if (!e->tab[(int)e->pos_x][(int)(e->pos_y + e->dir_y)])
		e->pos_y += e->dir_y / e->speed;
}

void 	ft_move_back(t_env *e)
{
	if (!e->tab[(int)(e->pos_x - e->dir_x)][(int)e->pos_y])
		e->pos_x -= e->dir_x / e->speed;
	if (!e->tab[(int)e->pos_x][(int)(e->pos_y - e->dir_y)])
		e->pos_y -= e->dir_y / e->speed;
}
