/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:04:02 by sandre-a          #+#    #+#             */
/*   Updated: 2024/04/15 19:23:12 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TITLE "GOKU'S ADVENTURE"
# define PIXELS 48

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdlib.h>

typedef struct s_map_items
{
	int			col;
	int			exit;
	int			start;
	t_img		bone;
	t_img		bg;
	t_img		blk;
	t_img		exit_game;
	int			exit_x;
	int			exit_y;
}				t_map_items;

typedef struct s_player
{
	t_img		png;
	int			pos_y;
	int			pos_x;
}				t_player;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	char		**map;
	t_map_items	it;
	t_player	goku;
	int			rows;
	int			cols;
	int			moves;
	int			score;
}				t_mlx_data;

int				input(int key, t_mlx_data *data);
void			print_title(void);
char			**read_map(int fd, char *map_name);
int				map_format(char **map, int last_l);
void			free_map(char **map);
int				count_lines(int fd);
int				render_win(t_mlx_data *data);
int				exit_game(t_mlx_data *d);

int				is_valid_path(t_mlx_data *data);
int				is_valid_position(t_mlx_data *data, int x, int y);
void			dfs(t_mlx_data *d, int x, int y, int **visited);
int				check_items(t_mlx_data *d);
int				set_coord(t_mlx_data *data, int i, int x);
int				valid_map_input(t_mlx_data *data);
void			collectable(t_mlx_data *data, int x, int i, int key);
int				populate_map(t_mlx_data *d);
void			load_img(t_mlx_data *d);
void			check_wall_mov(t_mlx_data *data, int key);

#endif
