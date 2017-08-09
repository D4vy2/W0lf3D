/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dea <dea@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 13:55:06 by dea               #+#    #+#             */
/*   Updated: 2015/11/10 13:24:54 by dea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <string.h>
# include <math.h>

#include <stdio.h> 
/*
**
      TO REMOVE BEFORE CORRECTION
**
*/
#define DP printf("%s  %d\n", __FILE__, __LINE__);

#define BUFF_SIZE 1024
#define RIGHT 124
#define LEFT 123
#define UP 126
#define DOWN 125
#define ESC 53
#define MOUSE_UP 5
#define MOUSE_DOWN 4
#define RESTART 15
#define SPEEDUP 24
#define SPEEDDOWN 27
#define PAUSE 49
#define WIN 42
#define DAY 18
#define NIGHT 19
#define ROTATION 0.04


typedef struct 			s_env
{
	void			*mlx;
	void			*win;
	int			screen_width;
	int			screen_height;
	int 			**tab;
	int			xmax;
	int			ymax;

	void			*img;
	char			*data;
	int			bpp;
	int			sizeline;
	int 			endian;

	int			day_n_night;
	int			tmp_day_n_night;
	unsigned int		color;
	unsigned int		color_sky;
	unsigned int		color_floor;
	int 			pause;
	

	int			x;
	int			y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			oldtime;
	int			speed;

	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;

	int			map_x;
	int			map_y;

	double			dist_mur_x;
	double			dist_mur_y;
	double			dist_2murs_x;
	double			dist_2murs_y;
	double			longueur_mur;
	int			hauteur_mur;

	int			etape_x;
	int			etape_y;

	int			hit;
	int			side;

	int			draw_start;
	int			draw_end;
	int			sky;

	int 	key_up;
	int 	key_down;
	int 	key_left;
	int 	key_right;
	int teleporting;
	int  	you_win;
}				t_env;

t_env	ft_open_file(int argc, char **argv, t_env e);

int	*ft_convert_atoi(char *s);
int	ft_return_ymax(char **tab);
int	ft_count_points(char *s);
int	*ft_convert_atoi(char *s);
int	**ft_convert_map(char **map, t_env vmax);
char	**ft_return_map(int fd, int ret);

void	ft_check_map(char **map, t_env *e);
void	ft_check_ret(int ret);
void 	ft_check_error(int argc, char **argv);

int	ft_press_key(int keycode, t_env *e);
int	ft_release_key(int keycode, t_env *e);
void 	ft_move_front(t_env *e);
void 	ft_move_back(t_env *e);
void 	ft_move_left(t_env *e);
void 	ft_move_right(t_env *e);

void	ft_calc_player_to_wall(t_env *e);
void	ft_dda(t_env *e);
int	ft_calcul_and_draw(t_env *e);
void 	ft_ray_position_and_direction(t_env *e);
void 	ft_calc_next_wall(t_env *e);

void	ft_init(t_env *e);
int	expose_hook(t_env *e);
void	ft_color_pix(t_env *e, unsigned int color);
void	ft_color_sky(t_env *e, unsigned int color);
void	ft_set_color(t_env *e);
void	day_color(t_env *e);
void	night_color(t_env *e);

void	ft_draw(t_env *e);
int 	loop_hook(t_env *e);
void 	ft_teleport(t_env *e);

#endif
