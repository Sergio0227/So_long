/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandre-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:54:57 by sandre-a          #+#    #+#             */
/*   Updated: 2024/04/23 01:07:57 by sandre-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_mlx_data *d)
{
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

void	print_title(void)
{
	ft_printf("╭━━━╮  ╭╮            ╭━━━╮ ╭╮        ╭╮\n");
	ft_printf("┃╭━╮┃  ┃┃     ╭╮     ┃╭━╮┃ ┃┃       ╭╯╰╮\n");
	ft_printf("┃┃ ╰╋━━┫┃╭┳╮╭┫ ┣━━╮  ┃┃ ┃┣━╯┣╮╭┳━━┳━╋╮╭╋╮╭┳━┳━━╮\n");
	ft_printf("┃┃╭━┫╭╮┃╰╯┫┃┃┣ ┫━━┫  ┃╰━╯┃╭╮┃╰╯┃┃━┫╭╮┫┃┃┃┃┃╭┫┃━┫\n");
	ft_printf("┃╰┻━┃╰╯┃╭╮┫╰╯┃ ┣━━┃  ┃╭━╮┃╰╯┣╮╭┫┃━┫┃┃┃╰┫╰╯┃┃┃┃━┫\n");
	ft_printf("╰━━━┻━━┻╯╰┻━━╯ ╰━━╯  ╰╯ ╰┻━━╯╰╯╰━━┻╯╰┻━┻━━┻╯╰━━╯\n");
}
