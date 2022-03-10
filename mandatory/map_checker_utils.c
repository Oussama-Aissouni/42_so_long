/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:13:46 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/08 11:13:47 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	write(2, "Error\nmap error", 15);
	exit(1);
}

int	check_lines_lenght(char **p)
{
	size_t	nb_lines;
	size_t	i;

	nb_lines = ft_strlen2(p);
	i = 0;
	while (i < nb_lines - 1)
	{
		if (ft_strlen(p[i]) != ft_strlen(p[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

void	init(t_components *comp)
{
	comp->c = 0;
	comp->e = 0;
	comp->p = 0;
}

void	check_components(t_components *comp, t_window *asd)
{
	size_t		i;
	size_t		j;

	i = 1;
	init(comp);
	while (i < ft_strlen2(asd->map) - 1)
	{
		j = 1;
		while (j < ft_strlen(asd->map[0]) - 1)
		{
			if (asd->map[i][j] != '0' && asd->map[i][j] != '1'
				&& asd->map[i][j] != 'C' && asd->map[i][j] != 'E'
				&& asd->map[i][j] != 'P')
				map_error();
			if (asd->map[i][j] == 'C')
				comp->c += 1;
			else if (asd->map[i][j] == 'E')
				comp->e += 1;
			else if (asd->map[i][j] == 'P')
				comp->p += 1;
			j++;
		}
		i++;
	}
	asd->coins_count = comp->c;
}

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
