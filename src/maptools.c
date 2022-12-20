/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:58:17 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/30 11:58:21 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	verify_map(t_param *param)
{
	int	nb;

	nb = count_collectibles(param->map, param->max);
	if (!is_closed(param->map, param->max) || nb < 1)
	{
		free_map(param->map, param->max, NULL);
		if (nb >= 1)
			ft_printf("Error\nMap Error Not Closed\n");
		else
			ft_printf("Error\nNo Collectibles\n");
		return (0);
	}
	return (verify_path(param, nb));
}

void	*free_map(t_cell ***map, t_max *max, mlx_t *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < max->ym)
	{
		x = 0;
		while (x < max->xm)
		{
			if (mlx)
			{
				if (map[y][x]->image != NULL)
					mlx_delete_image(mlx, map[y][x]->image);
				if (map[y][x]->image_spe != NULL)
					mlx_delete_image(mlx, map[y][x]->image_spe);
			}
			free(map[y][x]);
			x++;
		}
		free(map[y]);
		y++;
	}
	free(map);
	return (NULL);
}

int	count_collectibles(t_cell ***map, t_max *max)
{
	int	x;
	int	y;
	int	nb_c;

	nb_c = 0;
	x = 0;
	while (x < max->ym)
	{
		y = 0;
		while (y < max->xm)
		{
			if (map[x][y]->type == 1)
				nb_c++;
			y++;
		}
		x++;
	}
	return (nb_c);
}

int	is_closed(t_cell ***map, t_max *max)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < max->ym)
	{
		if (map[y][0]->type != 0 || map[y][max->xm - 1]->type != 0)
			return (0);
		y++;
	}
	while (x < max->xm)
	{
		if (map[0][x]->type != 0 || map[max->ym - 1][x]->type != 0)
			return (0);
		x++;
	}
	return (1);
}

int	open_map(char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDWR);
	if (fd == -1)
		ft_printf("Error\nMap Error Couldn't Open The Map\n");
	return (fd);
}
