/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:00:35 by oaissoun          #+#    #+#             */
/*   Updated: 2022/02/19 17:00:38 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_strlen2(char	**s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

int	lines_counter(const char *path)
{
	int	indice;
	int	fd;

	fd = open(path, O_RDONLY);
	indice = 0;
	while (1)
	{
		if (get_next_line(fd) == NULL)
			break ;
		else
			indice++;
	}
	close(fd);
	return (indice);
}

char	**map_lines(const char *path)
{
	int		nb_line;
	int		counter;
	int		fd;
	char	**map_lines;

	fd = open(path, O_RDONLY);
	counter = 0;
	nb_line = lines_counter(path);
	map_lines = (char **)malloc(sizeof(char *) * (nb_line + 1));
	while (counter < nb_line)
	{
		map_lines[counter] = get_next_line(fd);
		counter++;
	}
	map_lines[counter] = NULL;
	return (map_lines);
}

int	check_top_bot(char *line)
{
	size_t	i;
	size_t	line_len;

	line_len = ft_strlen(line);
	i = 0;
	while (i < line_len)
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_mid_border(char *line)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (line[0] != '1')
		return (1);
	if (line[line_len - 1] != '1')
		return (1);
	return (0);
}
