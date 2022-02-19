/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:14:40 by oaissoun          #+#    #+#             */
/*   Updated: 2021/12/04 11:52:30 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	my_free(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s2) + ft_strlen(s1) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i + j] != '\0')
	{
		ptr[j] = s1[i + j];
		j++;
	}
	while (s2[i] != '\0')
	{
		ptr[j + i] = s2[i];
		i++;
	}
	ptr[j + i] = '\0';
	return (ptr);
}

char	*extract_word(char *s, int from, int to)
{
	char	*ptr;
	int		s_len;
	int		i;

	s_len = to - from + 1;
	i = 0;
	ptr = malloc (sizeof (char) * (s_len + 1));
	while (s_len > i)
	{
		ptr[i] = s[from + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	size_t		s1_len;
	char		*ptr;
	int			i;

	i = 0;
	s1_len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (s1_len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
