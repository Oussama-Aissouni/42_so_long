/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaissoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:09:10 by oaissoun          #+#    #+#             */
/*   Updated: 2022/03/08 18:09:12 by oaissoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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
	void	*img1;
	void	*img2;
	void	*img3;
	int		pos_i;
	int		pos_j;
}	t_exit;

typedef struct s_window
{
	void		*win;
	void		*mlx;
	int			coins_count;
	char		**map;
	int			moves;
	t_player	p;
	t_texture	c;
	t_texture	g;
	t_texture	w;
	t_texture	enemy;
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
void	parser(int width, int height, t_window asd);
int		map_checker(const char *path, t_window *asd);
void	put_player_image(t_window *vars, int i, int j);
void	put_exit_image(t_window *vars, int i, int j);
void	put_collectible_image(t_window *vars, int i, int j);
void	put_ground_image(t_window *vars, int i, int j);
void	put_wall_image(t_window *vars, int i, int j);
void	map_error(void);
void	init(t_components *comp);
void	init2(t_window *vars);
void	init3(t_window *vars);
int		check_lines_lenght(char **p);
void	check_components(char **mp, t_components *comp, t_window *asd);
int		ft_strncmp(char *s1, const char *s2, size_t n);
int		animation(t_window *vars);
char	*ft_itoa(int n);
void	f(t_window *vars);
#endif
