/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:08:34 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/08 18:08:35 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_enemy_image(t_window *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
		j * 80, i * 80);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy.img,
		j * 80, i * 85);
}

static	void	map_reading(t_window *vars)
{
	int			i;
	int			j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
				put_wall_image(vars, i, j);
			else if (vars->map[i][j] == '0')
				put_ground_image(vars, i, j);
			else if (vars->map[i][j] == 'P')
				put_player_image(vars, i, j);
			else if (vars->map[i][j] == 'C')
				put_collectible_image(vars, i, j);
			else if (vars->map[i][j] == 'E')
				put_exit_image(vars, i, j);
			else if (vars->map[i][j] == 'X')
				put_enemy_image(vars, i, j);
			j++;
		}
		i++;
	}
}

static	int	close_(void)
{
	exit(0);
}

void	parser(int width, int height, t_window	vars)
{
	int	x;

	vars.moves = 0;
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
	vars.enemy.img = mlx_xpm_file_to_image(vars.mlx,
			"./images/enemy.xpm", &x, &x);
	map_reading(&vars);
	mlx_key_hook(vars.win, key_hooks, &vars);
	mlx_hook(vars.win, 17, 0, close_, NULL);
	mlx_loop(vars.mlx);
}
