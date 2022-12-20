/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:22:17 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/28 12:22:18 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*open_image(char *path, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

void	open_tiles(t_cell ***map, t_max *max, mlx_t *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < max->ym)
	{
		x = 0;
		while (x < max->xm)
		{
			update_type(map, x, y, max);
			map[y][x]->image = find_tile(map[y][x]->num, mlx);
			map[y][x]->image_spe = find_tile_spe(map[y][x]->type, mlx);
			x++;
		}
		y++;
	}
}

void	update_type(t_cell ***map, int x, int y, t_max *max)
{
	if (map[y][x]->type > 0)
	{
		map[y][x]->num += 4;
		if (y + 1 < max->ym && map[y + 1][x]->type > 0)
			map[y][x]->num += 5;
		if (y - 1 >= 0 && map[y - 1][x]->type > 0)
			map[y][x]->num += 1;
		if (x + 1 < max->xm && map[y][x + 1]->type > 0)
			map[y][x]->num += 3;
		if (x - 1 >= 0 && map[y][x - 1]->type > 0)
			map[y][x]->num += 10;
	}
}
