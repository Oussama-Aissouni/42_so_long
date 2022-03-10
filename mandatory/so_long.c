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
	int			width;
	int			height;
	t_window	asd;

	if (argc >= 2)
	{
		if (map_checker(argv[1], &asd) == 0)
		{
			width = ft_strlen(asd.map[0]);
			height = ft_strlen2(asd.map);
			parser(width, height, asd);
		}
	}
	else
	{
		write(2, "Error\nno enough arguments", 25);
		exit(1);
	}
}
