/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:41:52 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/29 14:41:53 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_map(mlx_t *mlx, t_cell ***map, t_max *max)
{
	int	x;
	int	y;

	y = 0;
	while (y < max->ym)
	{
		x = 0;
		while (x < max->xm)
		{
			mlx_image_to_window(mlx, map[y][x]->image, 64 * x, 64 * y);
			if (map[y][x]->type == 1 || map[y][x]->type == 3)
				mlx_image_to_window(mlx, map[y][x]->image_spe, (64 * x) + 16,
					(64 * y) + 16);
			x++;
		}
		y++;
	}
}

void	refresh(mlx_t *mlx, t_cell ***map, int x, int y)
{
	mlx_image_to_window(mlx, map[y][x]->image, 64 * x, 64 * y);
	if (map[y][x]->type == 1 || map[y][x]->type == 3)
		mlx_image_to_window(mlx, map[y][x]->image_spe, (64 * x) + 16,
			(64 * y) + 16);
}

void	update(void *param)
{
	t_param	*tmp;

	tmp = ((t_param *)param);
	lapinou_display(tmp->lapinou, tmp->mlx);
}
