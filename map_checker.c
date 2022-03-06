/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:26:38 by oaissoun          #+#    #+#             */
/*   Updated: 2022/02/19 19:26:40 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static	void	map_error(void)
{
	write(2, "error with the map", 18);
	exit(1);
}

static	int	check_lines_lenght(char **p)
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

static	void	check_components(char **mp, t_components *comp, t_window *asd)
{
	size_t		i;
	size_t		j;

	i = 1;
	asd->coins_count = 0;
	comp->c = 0;
	comp->e = 0;
	comp->p = 0;
	while (i < ft_strlen2(mp) - 1)
	{
		j = 1;
		while (j < ft_strlen(mp[0]) - 1)
		{
			if (mp[i][j] != '0' && mp[i][j] != '1' && mp[i][j] != 'C'
				&& mp[i][j] != 'E' && mp[i][j] != 'P')
				map_error();
			if (mp[i][j] == 'C')
				comp->c += 1;
			else if (mp[i][j] == 'E')
				comp->e += 1;
			else if (mp[i][j] == 'P')
				comp->p += 1;
			j++;
		}
		i++;
	}
	asd->coins_count = comp->c;
}

int	map_checker(const char *path, t_window *asd)
{
	t_components	comp;
	char			**mp;
	size_t			i;
	size_t			lenght;

	mp = map_lines(path);
	i = 1;
	lenght = ft_strlen2(mp) - 1;
	if (check_lines_lenght(mp) != 0)
		map_error();
	if (check_top_bot(mp[0]) != 0)
		map_error();
	while (i < lenght)
	{
		if (check_mid_border(mp[i]) != 0)
			map_error();
		i++;
	}
	if (check_top_bot(mp[lenght]) != 0)
		map_error();
	check_components(mp, &comp, asd);
	if (comp.p != 1 || comp.e != 1 || comp.c == 0)
		map_error();
	return (0);
}
