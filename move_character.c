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

void	move_right(t_window *vars)
{
	vars->t[0].pos_x += 100;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t[1].img,
		vars->t[1].pos_x, vars->t[1].pos_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t[0].img,
		vars->t[0].pos_x, vars->t[0].pos_y);
}

void	move_left(t_window *vars)
{
	vars->t[0].pos_x -= 100;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t[1].img,
		vars->t[1].pos_x, vars->t[1].pos_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t[0].img,
		vars->t[0].pos_x, vars->t[0].pos_y);
}

void	move_down(t_window *vars)
{
	vars->t[0].pos_y -= 100;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t[1].img,
		vars->t[1].pos_x, vars->t[1].pos_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t[0].img,
		vars->t[0].pos_x, vars->t[0].pos_y);
}

void	move_up(t_window *vars)
{
	vars->t[0].pos_y += 100;
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t[1].img,
		vars->t[1].pos_x, vars->t[1].pos_y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->t[0].img,
		vars->t[0].pos_x, vars->t[0].pos_y);
}

int	key_hooks(int keycode, t_window *vars)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 2)
		move_right(vars);
	else if (keycode == 0)
		move_left(vars);
	else if (keycode == 1)
		move_up(vars);
	else if (keycode == 13)
		move_down(vars);
	return (0);
}
