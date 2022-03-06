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

int	main(int argc, char *argv[])
{
	char	**map;
	int		width;
	int		height;
	t_window asd;

	if (argc >= 2)
	{
		if (map_checker(argv[1], &asd) == 0)
		{
			map = map_lines(argv[1]);
			width = ft_strlen(map[0]);
			height = ft_strlen2(map);
			parser(map, width, height, asd);
		}
	}
	else
	{
		write(2, "error", 5);
		exit(1);
	}
}
