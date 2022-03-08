/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:08:13 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/08 18:08:15 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static	void	check_path(const char *path)
{
	char	*path_;
	char	*p;
	size_t	len;

	path_ = (char *)path;
	p = (char *) malloc(sizeof(char) * 5);
	len = ft_strlen(path_);
	p[0] = path_[len - 4];
	p[1] = path_[len - 3];
	p[2] = path_[len - 2];
	p[3] = path_[len - 1];
	p[4] = '\0';
	if (ft_strncmp(p, ".ber", 4) != 0)
		map_error();
	free(p);
}

int	map_checker(const char *path, t_window *asd)
{
	t_components	comp;
	size_t			i;
	size_t			lenght;

	check_path(path);
	asd->map = map_lines(path);
	i = 1;
	lenght = ft_strlen2(asd->map) - 1;
	if (check_lines_lenght(asd->map) != 0)
		map_error();
	if (check_top_bot(asd->map[0]) != 0)
		map_error();
	while (i < lenght)
	{
		if (check_mid_border(asd->map[i]) != 0)
			map_error();
		i++;
	}
	if (check_top_bot(asd->map[lenght]) != 0)
		map_error();
	check_components(asd->map, &comp, asd);
	if (comp.p != 1 || comp.e != 1 || comp.c == 0)
		map_error();
	return (0);
}
