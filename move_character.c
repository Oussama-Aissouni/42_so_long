/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 15:41:14 by oaissoun          #+#    #+#             */
/*   Updated: 2022/02/19 15:41:20 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_right(t_window *vars, char	**map)
{
	if (map[vars->p.pos_i][vars->p.pos_j + 1] != '1'
		&& map[vars->p.pos_i][vars->p.pos_j + 1] != 'E')
	{
		vars->p.pos_j += 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
			vars->p.pos_x, vars->p.pos_y);
		vars->p.pos_x += 80;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
			vars->p.pos_x, vars->p.pos_y);
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'C')
	{
		printf("%d\n", vars->coins_count);
		vars->coins_count--;
		map[vars->p.pos_i][vars->p.pos_j] = '0';
	}
}

void	move_left(t_window *vars, char	**map)
{
	if (map[vars->p.pos_i][vars->p.pos_j - 1] != '1')
	{
		vars->p.pos_x -= 80;
		vars->p.pos_j -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
			vars->p.pos_x + 80, vars->p.pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
			vars->p.pos_x, vars->p.pos_y);
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'C')
	{
		vars->coins_count--;
		map[vars->p.pos_i][vars->p.pos_j] = '0';
		printf("%d\n", vars->coins_count);
	}
}

void	move_down(t_window *vars, char	**map)
{
	if (map[vars->p.pos_i - 1][vars->p.pos_j] != '1')
	{
		vars->p.pos_y -= 80;
		vars->p.pos_i -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
			vars->p.pos_x, vars->p.pos_y + 80);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
			vars->p.pos_x, vars->p.pos_y);
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'C')
	{
		vars->coins_count--;
		map[vars->p.pos_i][vars->p.pos_j] = '0';
		printf("%d\n", vars->coins_count);
	}
}

void	move_up(t_window *vars, char	**map)
{
	if (map[vars->p.pos_i + 1][vars->p.pos_j] != '1')
	{
		vars->p.pos_y += 80;
		vars->p.pos_i += 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
			vars->p.pos_x, vars->p.pos_y - 80);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
			vars->p.pos_x, vars->p.pos_y);
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'C')
	{
		vars->coins_count--;
		map[vars->p.pos_i][vars->p.pos_j] = '0';
		printf("%d\n", vars->coins_count);
	}
}

int	key_hooks(int keycode, t_window *vars)
{
	char	**map;

	map = map_lines("map.ber");
	if (keycode == 53)
		exit(0);
	else if (keycode == 2)
		move_right(vars, map);
	else if (keycode == 0)
		move_left(vars, map);
	else if (keycode == 1)
		move_up(vars, map);
	else if (keycode == 13)
		move_down(vars, map);
	return (0);
}
