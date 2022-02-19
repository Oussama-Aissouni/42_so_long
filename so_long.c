/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:35:02 by oaissoun          #+#    #+#             */
/*   Updated: 2022/02/17 14:35:10 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_window	vars;
	int			x;
	int			y;

	vars.t[0].pos_x = 0;
	vars.t[0].pos_y = 0;
	vars.t[0].display = true;
	vars.t[1].display = true;
	vars.t[1].pos_x = 1000;
	vars.t[1].pos_y = 900;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So_long");
	mlx_key_hook(vars.win, key_hooks, &vars);
	vars.t[0].img = mlx_xpm_file_to_image(vars.mlx,
			"./images/coin.xpm", &x, &y);
	vars.t[1].img = mlx_xpm_file_to_image(vars.mlx,
			"./images/wall.xpm", &x, &y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.t[0].img,
		vars.t[0].pos_x, vars.t[0].pos_y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.t[1].img,
		vars.t[1].pos_x, vars.t[1].pos_y);
	mlx_loop(vars.mlx);
	return (0);
}
