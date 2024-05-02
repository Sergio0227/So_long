/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:00:42 by sandre-a          #+#    #+#             */
/*   Updated: 2024/05/03 01:17:41 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**allocate_visited(int rows, int cols)
{
	int	**visited;
	int	i;
	int	j;

	visited = (int **)malloc(rows * sizeof(int *));
	i = -1;
	while (++i < rows)
		visited[i] = (int *)malloc(cols * sizeof(int));
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
			visited[i][j] = 0;
	}
	return (visited);
}

int	is_valid_path(t_mlx_data *d)
{
	int	**visited;
	int	flag;
	int	i;
	int	j;

	flag = 0;
	visited = allocate_visited(d->rows, d->cols);
	dfs(d, d->goku.pos_y / PIXELS, d->goku.pos_x / PIXELS, visited);
	i = -1;
	while (++i < d->rows)
	{
		j = -1;
		while (++j < d->cols)
			if ((d->map[i][j] == 'C' || d->map[i][j] == 'E') && !visited[i][j])
				flag = 1;
	}
	j = -1;
	while (++j < d->rows)
		free(visited[j]);
	free(visited);
	if (flag)
		return (1);
	return (0);
}

int	is_valid_position(t_mlx_data *data, int x, int y)
{
	return (x >= 0 && x < data->rows && y >= 0 && y < data->cols
		&& data->map[x][y] != '1');
}

void	dfs(t_mlx_data *d, int x, int y, int **visited)
{
	int	dx[4];
	int	dy[4];
	int	i;
	int	new_x;
	int	new_y;

	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
	visited[x][y] = 1;
	i = 0;
	while (i < 4)
	{
		new_x = x + dx[i];
		new_y = y + dy[i];
		if (is_valid_position(d, new_x, new_y) && !visited[new_x][new_y])
			dfs(d, new_x, new_y, visited);
		i++;
	}
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
