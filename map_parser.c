/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:04:34 by sandre-a          #+#    #+#             */
/*   Updated: 2024/04/23 01:07:50 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd, char *map_name)
{
	char	**map;
	int		x;
	int		i;

	i = count_lines(fd);
	map = malloc((sizeof(char *) * (i + 1)));
	if (!map || i == 0)
		return (NULL);
	map[i] = 0;
	x = 0;
	fd = open(map_name, O_RDONLY);
	while (x < i)
	{
		map[x] = get_next_line(fd);
		if (map[x][(ft_strlen(map[x]) - 1)] == '\n')
			map[x][(ft_strlen(map[x]) - 1)] = 0;
		x++;
	}
	close(fd);
	if (map_checker(map, i))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

int	map_checker(char **map, int last_l)
{
	int	x;

	x = 0;
	while (x < last_l)
	{
		if (map[x][0] != '1' || map[x][ft_strlen(map[x]) - 1] != '1')
			return (1);
		if (x < last_l - 1)
			if (ft_strlen(map[x]) != ft_strlen(map[x + 1]))
				return (1);
		x++;
	}
	x = 0;
	while (map[0][x] && map[last_l - 1][x])
	{
		if (map[0][x] != '1' || map[last_l - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

int	valid_map_input(t_mlx_data *data)
{
	int	i;
	int	x;

	if (!data->map)
		return (1);
	data->it.col = 0;
	data->it.start = 0;
	data->it.exit = 0;
	i = 0;
	while (data->map[i])
	{
		x = 0;
		while (data->map[i][x])
		{
			if (data->map[i][x] != '1' && data->map[i][x] != '0'
				&& data->map[i][x] != 'C' && data->map[i][x] != 'P'
				&& data->map[i][x] != 'E')
				return (1);
			x++;
		}
		i++;
	}
	return (check_items(data));
}

void	check_wall(t_mlx_data *data, int key)
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
