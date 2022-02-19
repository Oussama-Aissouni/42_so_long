/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:14:31 by oaissoun          #+#    #+#             */
/*   Updated: 2021/12/04 11:51:03 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	ft_find_index(char *s, int c)
{
	int				i;
	char			x;

	i = 0;
	x = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == x)
			return (i);
		i++;
	}
	if (s[i] == x)
		return (i);
	return (-1);
}

static char	*ft_read(char **storage, char **temp, int fd)
{
	int		read_ret;
	char	*read_;

	read_ret = 1;
	read_ = malloc(BUFFER_SIZE + 1);
	if (!read_)
		return (NULL);
	while (ft_find_index(*storage, '\n') == -1)
	{
		read_ret = read(fd, read_, BUFFER_SIZE);
		if (read_ret == -1)
		{
			my_free(storage);
			my_free(&read_);
			return (NULL);
		}
		read_[read_ret] = '\0';
		if (read_ret == 0)
			break ;
		*temp = *storage;
		*storage = ft_strjoin(*storage, read_);
		free(*temp);
	}
	free(read_);
	return (*storage);
}

static char	*no_line(char **storage, char **temp)
{
	if (*storage[0] == '\0')
	{
		free(*storage);
		*storage = NULL;
		return (NULL);
	}
	*temp = ft_strdup(*storage);
	free(*storage);
	*storage = NULL;
	return (*temp);
}

static char	*is_line(char **storage, char **temp)
{
	int		index;
	char	*p;

	index = ft_find_index(*storage, '\n');
	*temp = ft_strdup(*storage);
	free(*storage);
	*storage = extract_word(*temp, index + 1, ft_strlen(*temp));
	p = extract_word(*temp, 0, index);
	free(*temp);
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (storage == NULL)
		storage = ft_strdup("");
	if (ft_read(&storage, &temp, fd) == NULL)
		return (NULL);
	if (ft_find_index(storage, '\n') == -1)
	{
		line = no_line(&storage, &temp);
		return (line);
	}
	line = is_line(&storage, &temp);
	return (line);
}
