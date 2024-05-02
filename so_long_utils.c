/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:54:57 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/03 00:45:52 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_coord(t_mlx_data *data, int i, int x)
{
	if (data->map[i][x] == 'C')
		data->it.col += 1;
	if (data->map[i][x] == 'E')
	{
		data->it.exit += 1;
		data->it.exit_x = x * PIXELS;
		data->it.exit_y = i * PIXELS;
	}
	if (data->map[i][x] == 'P')
	{
		data->it.start += 1;
		data->goku.pos_x = x * PIXELS;
		data->goku.pos_y = i * PIXELS;
	}
	return (0);
}

void	load_img(t_mlx_data *d)
{
	ft_printf("╭━━━╮  ╭╮            ╭━━━╮ ╭╮        ╭╮\n");
	ft_printf("┃╭━╮┃  ┃┃     ╭╮     ┃╭━╮┃ ┃┃       ╭╯╰╮\n");
	ft_printf("┃┃ ╰╋━━┫┃╭┳╮╭┫ ┣━━╮  ┃┃ ┃┣━╯┣╮╭┳━━┳━╋╮╭╋╮╭┳━┳━━╮\n");
	ft_printf("┃┃╭━┫╭╮┃╰╯┫┃┃┣ ┫━━┫  ┃╰━╯┃╭╮┃╰╯┃┃━┫╭╮┫┃┃┃┃┃╭┫┃━┫\n");
	ft_printf("┃╰┻━┃╰╯┃╭╮┫╰╯┃ ┣━━┃  ┃╭━╮┃╰╯┣╮╭┫┃━┫┃┃┃╰┫╰╯┃┃┃┃━┫\n");
	ft_printf("╰━━━┻━━┻╯╰┻━━╯ ╰━━╯  ╰╯ ╰┻━━╯╰╯╰━━┻╯╰┻━┻━━┻╯╰━━╯\n");
	d->it.bg.image = mlx_xpm_file_to_image(d->mlx, "textures/bg.xpm",
			&d->it.bg.width, &d->it.bg.height);
	d->it.blk.image = mlx_xpm_file_to_image(d->mlx, "textures/bg1.xpm",
			&d->it.blk.width, &d->it.blk.height);
	d->it.bone.image = mlx_xpm_file_to_image(d->mlx, "textures/bone.xpm",
			&d->it.bone.width, &d->it.bone.height);
	d->it.exit_game.image = mlx_xpm_file_to_image(d->mlx, "textures/exit.xpm",
			&d->it.exit_game.width, &d->it.exit_game.height);
	d->goku.png.image = mlx_xpm_file_to_image(d->mlx, "textures/1.xpm",
			&d->goku.png.width, &d->goku.png.height);
	if (!d->it.blk.image || !d->it.bg.image || !d->goku.png.image)
		exit_game(d);
}

void	select_img(t_mlx_data *d, char square, int pos_x, int pos_y)
{
	if (square == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->it.blk.image, pos_x, pos_y);
	else if (square == 'P')
		mlx_put_image_to_window(d->mlx, d->win, d->goku.png.image, pos_x,
			pos_y);
	else if (square == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->it.bone.image, pos_x, pos_y);
	else if (square == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->it.bg.image, pos_x, pos_y);
	else if (square == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->it.bg.image, pos_x, pos_y);
}

int	populate_map(t_mlx_data *d)
{
	int	i;
	int	j;
	int	pos_x;
	int	pos_y;

	pos_y = 0;
	i = 0;
	while (d->map[i])
	{
		j = 0;
		pos_x = 0;
		while (d->map[i][j])
		{
			select_img(d, d->map[i][j], pos_x, pos_y);
			pos_x += PIXELS;
			j++;
		}
		pos_y += PIXELS;
		i++;
	}
	return (0);
}

void	check_wall_mov(t_mlx_data *data, int key)
{
	int	x;
	int	i;

	x = data->goku.pos_x / PIXELS;
	i = data->goku.pos_y / PIXELS;
	mlx_put_image_to_window(data->mlx, data->win, data->it.bg.image,
		data->goku.pos_x, data->goku.pos_y);
	if (key == 115 && data->map[i + 1][x] != '1')
		data->goku.pos_y += PIXELS;
	if (key == 119 && data->map[i - 1][x] != '1')
		data->goku.pos_y -= PIXELS;
	if (key == 100 && data->map[i][x + 1] != '1')
		data->goku.pos_x += PIXELS;
	if (key == 97 && data->map[i][x - 1] != '1')
		data->goku.pos_x -= PIXELS;
	if (x != data->goku.pos_x / PIXELS || i != data->goku.pos_y / PIXELS)
	{
		collectable(data, x, i, key);
		data->moves++;
		ft_printf("Moves: %d\n", data->moves);
	}
}
