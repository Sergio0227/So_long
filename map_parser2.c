/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:00:42 by sandre-a          #+#    #+#             */
/*   Updated: 2024/04/23 01:08:00 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_items(t_mlx_data *d)
{
	int	i;
	int	x;

	i = 0;
	while (d->map[i])
	{
		x = 0;
		while (d->map[i][x])
		{
			if (ft_memchr("CEP", d->map[i][x], 3))
				if (check_path(d, i, x))
					return (1);
			x++;
		}
		i++;
	}
	if (d->it.col && d->it.exit == 1 && d->it.start == 1)
		return (0);
	return (1);
}

int	check_path(t_mlx_data *data, int i, int x)
{
	if (data->map[i + 1][x] == '1' && data->map[i - 1][x] == '1'
		&& data->map[i][x + 1] == '1' && data->map[i][x - 1] == '1')
		return (1);
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

void	collectable(t_mlx_data *data, int x, int i, int key)
{
	if (key == 115 && data->map[i + 1][x] == 'C')
	{
		data->map[i + 1][x] = '0';
		data->score += 1;
	}
	if (key == 119 && data->map[i - 1][x] == 'C')
	{
		data->map[i - 1][x] = '0';
		data->score += 1;
	}
	if (key == 100 && data->map[i][x + 1] == 'C')
	{
		data->map[i][x + 1] = '0';
		data->score += 1;
	}
	if (key == 97 && data->map[i][x - 1] == 'C')
	{
		data->map[i][x - 1] = '0';
		data->score += 1;
	}
}
