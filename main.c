/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:31:10 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/03 01:19:54 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx_data	data;
	int			fd;

	fd = open(argv[1], O_RDONLY);
	if (argc < 2 || fd < 0)
		return (1);
	data.map = read_map(fd, argv[1]);
	if (valid_map_input(&data) || is_valid_path(&data))
	{
		ft_printf("Error\n%s", "Invalid map");
		if (data.map)
			free_map(data.map);
		return (1);
	}
	data.mlx = mlx_init();
	render_win(&data);
	return (0);
}

int	render_win(t_mlx_data *data)
{
	int	height;
	int	width;

	height = data->rows * PIXELS;
	width = data->cols * PIXELS;
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, width, height, TITLE);
	if (!data->win)
		return (mlx_destroy_display(data->mlx), 1);
	load_img(data);
	populate_map(data);
	data->score = 0;
	data->moves = 0;
	mlx_key_hook(data->win, input, data);
	mlx_hook(data->win, 17, 0, exit_game, data);
	mlx_loop(data->mlx);
	return (0);
}

int	input(int key, t_mlx_data *d)
{
	if (key == XK_Escape)
		exit_game(d);
	if (key == 97 || key == 100 || key == 115 || key == 119)
	{
		check_wall_mov(d, key);
		mlx_put_image_to_window(d->mlx, d->win, d->goku.png.image,
			d->goku.pos_x, d->goku.pos_y);
		if (d->score == d->it.col)
			mlx_put_image_to_window(d->mlx, d->win, d->it.exit_game.image,
				d->it.exit_x, d->it.exit_y);
		if (d->goku.pos_x == d->it.exit_x && d->goku.pos_y == d->it.exit_y
			&& d->score == d->it.col)
			exit_game(d);
	}
	return (0);
}

int	exit_game(t_mlx_data *d)
{
	if (d->goku.pos_x == d->it.exit_x && d->goku.pos_y == d->it.exit_y
		&& d->score == d->it.col)
		ft_printf("You Won! Goku will have a nap now!\n");
	else
		ft_printf("Sad to see you go! See you on our Next Adventure\n");
	mlx_destroy_image(d->mlx, d->it.bg.image);
	mlx_destroy_image(d->mlx, d->it.blk.image);
	mlx_destroy_image(d->mlx, d->it.bone.image);
	mlx_destroy_image(d->mlx, d->it.exit_game.image);
	mlx_destroy_image(d->mlx, d->goku.png.image);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	free_map(d->map);
	exit(1);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
