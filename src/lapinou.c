/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lapinou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:56:34 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/02 14:56:35 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	lapinou_place(t_lapinou *lapinou, t_cell ***map, t_max *max)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < max->ym)
	{
		x = 0;
		while (x < max->xm)
		{
			if (map[y][x]->type == 2)
			{
				lapinou->x = x;
				lapinou->y = y;
			}
			x++;
		}
		y++;
	}
	lapinou->facing = 2;
	lapinou->nb_moves = 0;
}

void	lapinou_open_image(t_lapinou *lapinou, mlx_t *mlx)
{
	lapinou->in = open_image("assets/chars/idleN.png", mlx);
	lapinou->ie = open_image("assets/chars/idleE.png", mlx);
	lapinou->is = open_image("assets/chars/idleS.png", mlx);
	lapinou->iw = open_image("assets/chars/idleW.png", mlx);
}

void	lapinou_free(t_lapinou *lapinou, mlx_t *mlx)
{
	mlx_delete_image(mlx, lapinou->in);
	mlx_delete_image(mlx, lapinou->ie);
	mlx_delete_image(mlx, lapinou->is);
	mlx_delete_image(mlx, lapinou->iw);
}

void	lapinou_display(t_lapinou *lapinou, mlx_t *mlx)
{
	if (lapinou->facing == 0)
		lapinou->ci = lapinou->in;
	else if (lapinou->facing == 1)
		lapinou->ci = lapinou->ie;
	else if (lapinou->facing == 2)
		lapinou->ci = lapinou->is;
	else if (lapinou->facing == 3)
		lapinou->ci = lapinou->iw;
	mlx_image_to_window(mlx, lapinou->ci, lapinou->x * 64, lapinou->y * 64);
}

void	lapinou_init(t_lapinou *lapinou, t_param *param)
{
	lapinou_place(lapinou, param->map, param->max);
	lapinou_open_image(lapinou, param->mlx);
	lapinou->want = count_collectibles(param->map, param->max);
	lapinou->carrots = 0;
}
