/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:19:23 by oaissoun          #+#    #+#             */
/*   Updated: 2022/02/28 14:23:07 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	map_reading(t_window *vars, char	**map)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				put_wall_image(vars, i, j);
			else if (map[i][j] == '0')
				put_ground_image(vars, i, j);
			else if (map[i][j] == 'P')
				put_player_image(vars, i, j);
			else if (map[i][j] == 'C')
				put_collectible_image(vars, i, j);
			else if (map[i][j] == 'E')
				put_exit_image(vars, i, j);
			j++;
		}
		i++;
	}
}

void	parser(char **map, int width, int height, t_window	vars)
{
	int	x;

	vars.map = map;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width * 80, height * 80, "So_long");
	vars.p.img = mlx_xpm_file_to_image(vars.mlx,
			"./images/character.xpm", &x, &x);
	vars.w.img = mlx_xpm_file_to_image(vars.mlx,
			"./images/wall.xpm", &x, &x);
	vars.g.img = mlx_xpm_file_to_image(vars.mlx,
			"./images/ground.xpm", &x, &x);
	vars.c.img = mlx_xpm_file_to_image(vars.mlx,
			"./images/bomb.xpm", &x, &x);
	vars.e.img = mlx_xpm_file_to_image(vars.mlx,
			"./images/exit.xpm", &x, &x);
	map_reading(&vars, map);
	mlx_key_hook(vars.win, key_hooks, &vars);
	mlx_loop(vars.mlx);
}
