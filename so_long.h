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

typedef struct s_player
{
	void	*img;
	int		pos_x;
	int		pos_y;
	int		pos_i;
	int		pos_j;
}	t_player;

typedef struct s_texture
{
	void	*img;
}	t_texture;

typedef struct s_exit
{
	void	*img;
	int		pos_i;
	int		pos_j;
}	t_exit;

typedef struct s_window
{
	int			coins_count;
	char		**map;
	void		*mlx;
	void		*win;
	t_player	p;
	t_texture	c;
	t_texture	g;
	t_texture	w;
	t_exit		e;
}	t_window;

typedef struct s_components
{
	int	c;
	int	e;
	int	p;
}	t_components;

int		key_hooks(int keycode, t_window *vars);
size_t	ft_strlen(char	*s);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_word(char *s, int from, int to);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
void	my_free(char **ptr);
size_t	ft_strlen2(char	**s);
int		lines_counter(const char *path);
char	**map_lines(const char *path);
int		check_top_bot(char *line);
int		check_mid_border(char *line);
void	parser(char **map, int width, int height, t_window asd);
int		map_checker(const char *path, t_window *asd);
void	put_player_image(t_window *vars, int i, int j);
void	put_exit_image(t_window *vars, int i, int j);
void	put_collectible_image(t_window *vars, int i, int j);
void	put_ground_image(t_window *vars, int i, int j);
void	put_wall_image(t_window *vars, int i, int j);
#endif