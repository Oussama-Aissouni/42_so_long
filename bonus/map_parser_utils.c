/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:08:41 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/08 18:08:44 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player_image(t_window *vars, int i, int j)
{
	vars->p.pos_j = j;
	vars->p.pos_i = i;
	vars->p.pos_x = j * 80;
	vars->p.pos_y = i * 80;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
		j * 80, i * 80);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->p.img,
		j * 80, i * 80);
}

void	put_exit_image(t_window *vars, int i, int j)
{
	vars->e.pos_i = i;
	vars->e.pos_j = j;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
		j * 80, i * 80);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->e.img,
		j * 80, i * 80);
}

void	put_collectible_image(t_window *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
		j * 80, i * 80);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->c.img,
		j * 80, i * 80);
}

void	put_ground_image(t_window *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->g.img,
		j * 80, i * 80);
}

void	put_wall_image(t_window *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->w.img,
		j * 80, i * 80);
}
