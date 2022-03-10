/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:15:16 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/09 18:15:17 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init2(t_window *vars)
{
	int	i;

	vars->e.img3 = mlx_xpm_file_to_image(vars->mlx,
			"./images/animations/exit3.xpm", &i, &i);
	vars->e.img1 = mlx_xpm_file_to_image(vars->mlx,
			"./images/animations/exit1.xpm", &i, &i);
	vars->e.img2 = mlx_xpm_file_to_image(vars->mlx,
			"./images/animations/exit2.xpm", &i, &i);
}

int	animation(t_window *vars)
{
	static int	count;

	if (count < 10)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->g.img, vars->e.pos_j * 80, vars->e.pos_i * 80);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->e.img1, vars->e.pos_j * 80, vars->e.pos_i * 80);
	}
	else if (count < 50)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->g.img, vars->e.pos_j * 80, vars->e.pos_i * 80);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->e.img2, vars->e.pos_j * 80, vars->e.pos_i * 80);
	}
	else if (count < 70)
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->g.img, vars->e.pos_j * 80, vars->e.pos_i * 80);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->e.img3, vars->e.pos_j * 80, vars->e.pos_i * 80);
	}
	count++;
	return (0);
}

void	f(t_window *vars)
{
	char	*str;

	str = ft_itoa(vars->moves);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->w.img,
		0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->w.img,
		80, 0);
	mlx_string_put(vars->mlx, vars->win, 0, 0,
		0xFFFFFF, "moves :");
	mlx_string_put(vars->mlx, vars->win, 80, 0,
		0xFFFFFF, str);
	free(str);
}
