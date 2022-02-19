/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:35:16 by oaissoun          #+#    #+#             */
/*   Updated: 2022/02/17 14:35:18 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10000

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_vars
{
	void	*img;
	int		img_width;
	int		img_height;
	int		pos_x;
	int		pos_y;
	bool	display;
}	t_vars;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_vars	t[2];
}	t_window;

int		key_hooks(int keycode, t_window *vars);
size_t	ft_strlen(char	*s);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_word(char *s, int from, int to);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
void	my_free(char **ptr);

#endif