/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:09:02 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/08 18:09:04 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	int			width;
	int			height;
	t_window	asd;

	if (argc >= 2)
	{
		if (map_checker(argv[1], &asd) == 0)
		{
			asd.map = map_lines(argv[1]);
			width = ft_strlen(asd.map[0]);
			height = ft_strlen2(asd.map);
			parser(asd.map, width, height, asd);
		}
	}
	else
	{
		write(2, "Error\nno enough arguments", 25);
		exit(1);
	}
}
