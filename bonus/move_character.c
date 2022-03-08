/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:08:54 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/08 18:08:55 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_right(t_window *vars, char	**map)
{
	if (map[vars->p.pos_i][vars->p.pos_j + 1] != '1'
		&& map[vars->p.pos_i][vars->p.pos_j + 1] != 'E')
	{
		vars->moves += 1;
		vars->p.pos_j += 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
			vars->p.pos_x, vars->p.pos_y);
		vars->p.pos_x += 80;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
			vars->p.pos_x, vars->p.pos_y);
		printf("moves : %d\n", vars->moves);
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'C')
	{
		vars->coins_count--;
		map[vars->p.pos_i][vars->p.pos_j] = '0';
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'O')
		exit(0);
	if (map[vars->p.pos_i][vars->p.pos_j] == 'X')
		exit(0);
}

void	move_left(t_window *vars, char	**map)
{
	if (map[vars->p.pos_i][vars->p.pos_j - 1] != '1'
		&& map[vars->p.pos_i][vars->p.pos_j - 1] != 'E')
	{
		vars->moves += 1;
		vars->p.pos_x -= 80;
		vars->p.pos_j -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
			vars->p.pos_x + 80, vars->p.pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
			vars->p.pos_x, vars->p.pos_y);
		printf("moves : %d\n", vars->moves);
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'C')
	{
		vars->coins_count--;
		map[vars->p.pos_i][vars->p.pos_j] = '0';
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'O')
		exit(0);
	if (map[vars->p.pos_i][vars->p.pos_j] == 'X')
		exit(0);
}

void	move_down(t_window *vars, char	**map)
{
	if (map[vars->p.pos_i - 1][vars->p.pos_j] != '1'
		&& map[vars->p.pos_i - 1][vars->p.pos_j] != 'E')
	{
		vars->moves += 1;
		vars->p.pos_y -= 80;
		vars->p.pos_i -= 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
			vars->p.pos_x, vars->p.pos_y + 80);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
			vars->p.pos_x, vars->p.pos_y);
		printf("moves : %d\n", vars->moves);
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'C')
	{
		vars->coins_count--;
		map[vars->p.pos_i][vars->p.pos_j] = '0';
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'O')
		exit(0);
	if (map[vars->p.pos_i][vars->p.pos_j] == 'X')
		exit(0);
}

void	move_up(t_window *vars, char	**map)
{
	if (map[vars->p.pos_i + 1][vars->p.pos_j] != '1'
		&& map[vars->p.pos_i + 1][vars->p.pos_j] != 'E')
	{
		vars->moves += 1;
		vars->p.pos_y += 80;
		vars->p.pos_i += 1;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
			vars->p.pos_x, vars->p.pos_y - 80);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
			vars->p.pos_x, vars->p.pos_y);
		printf("moves : %d\n", vars->moves);
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'C')
	{
		vars->coins_count--;
		map[vars->p.pos_i][vars->p.pos_j] = '0';
	}
	if (map[vars->p.pos_i][vars->p.pos_j] == 'O')
		exit(0);
	if (map[vars->p.pos_i][vars->p.pos_j] == 'X')
		exit(0);
}

int	key_hooks(int keycode, t_window *vars)
{
	int	x;

	if (vars->coins_count == 0)
	{
		vars->e.img = mlx_xpm_file_to_image(vars->mlx,
				"./images/exit_opened.xpm", &x, &x);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->e.img,
			vars->e.pos_j * 80, vars->e.pos_i * 80);
		vars->map[vars->e.pos_i][vars->e.pos_j] = 'O';
	}
	if (keycode == 53)
		exit(0);
	else if (keycode == 2)
		move_right(vars, vars->map);
	else if (keycode == 0)
		move_left(vars, vars->map);
	else if (keycode == 1)
		move_up(vars, vars->map);
	else if (keycode == 13)
		move_down(vars, vars->map);
	return (0);
}
