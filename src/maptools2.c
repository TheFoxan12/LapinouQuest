/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:17:57 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/06 12:18:02 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	verify_path(t_param *param, int collectibles)
{
	int	x;
	int	y;

	y = 0;
	while (y < param->max->ym)
	{
		x = 0;
		while (x < param->max->xm)
		{
			if (param->map[y][x]->testing == 0 && param->map[y][x]->type == 2)
			{
				if (propagate(param, x, y, collectibles) == 1)
					return (1);
				else
				{
					ft_printf("Error\nMap Error Not Doable\n");
					return (0);
				}
			}
			x++;
		}
		y++;
	}
	ft_printf("Error\nMap Error No Spawnpoint\n");
	return (0);
}

int	propagate(t_param *param, int x, int y, int collectibles)
{
	static int	nb_collectibles = 0;
	static int	exit = 0;

	if (x < 0 || x > param->max->xm || y < 0 || y > param->max->ym)
		return (0);
	else if (param->map[y][x]->testing == 0)
	{
		param->map[y][x]->testing = 1;
		if (param->map[y][x]->type == 1)
			nb_collectibles++;
		if (param->map[y][x]->type == 3)
			exit++;
		propagate(param, x - 1, y, collectibles);
		propagate(param, x + 1, y, collectibles);
		propagate(param, x, y + 1, collectibles);
		propagate(param, x, y - 1, collectibles);
	}
	return (exit == 1 && nb_collectibles == collectibles);
}
