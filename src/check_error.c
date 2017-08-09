#include "wolf3d.h"

void 	ft_check_error(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc < 2)
			ft_putendl("Error: Need one map to run.");
		else
			ft_putendl("Wrong number of map: Please choose one \
valid map.");
		exit(0);
	}
	else if (ft_strcmp(argv[1], "-h") == 0)
	{
		ft_putstr("Usage: ./wolf3d + maps/( small_map || map_laby || map ");
		ft_putendl("|| map_block )");
		exit(0);
	}
	else if ((ft_strcmp(argv[1], "maps/small_map") != 0) &&
		(ft_strcmp(argv[1], "maps/map_laby") != 0) &&
		(ft_strcmp(argv[1], "maps/map") != 0) &&
		(ft_strcmp(argv[1], "maps/map_block") != 0))
	{
		ft_putendl("Wrong map name.");
		exit(0);
	}
}
