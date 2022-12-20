/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:24:19 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/29 13:24:21 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static mlx_image_t	*find_road_tile1(int type, mlx_t *mlx);
static mlx_image_t	*find_road_tile2(int type, mlx_t *mlx);

mlx_image_t	*find_tile_spe(int type, mlx_t *mlx)
{
	if (type == 0)
		return (NULL);
	else if (type == 3)
		return (open_image("assets/world/finish.png", mlx));
	else if (type == 1)
		return (open_image("assets/items/carrot.png", mlx));
	return (NULL);
}

mlx_image_t	*find_tile(int type, mlx_t *mlx)
{
	if (type == 0)
		return (open_image("assets/world/0.png", mlx));
	else
	{
		if (type > 0 && type < 15)
			return (find_road_tile1(type, mlx));
		else if (type >= 15 && type < 30)
			return (find_road_tile2(type, mlx));
	}
	return (NULL);
}

static mlx_image_t	*find_road_tile1(int type, mlx_t *mlx)
{
	if (type == 4)
		return (open_image("assets/world/4.png", mlx));
	else if (type == 5)
		return (open_image("assets/world/5.png", mlx));
	else if (type == 7)
		return (open_image("assets/world/7.png", mlx));
	else if (type == 8)
		return (open_image("assets/world/8.png", mlx));
	else if (type == 9)
		return (open_image("assets/world/9.png", mlx));
	else if (type == 10)
		return (open_image("assets/world/10.png", mlx));
	else if (type == 12)
		return (open_image("assets/world/12.png", mlx));
	else if (type == 13)
		return (open_image("assets/world/13.png", mlx));
	else if (type == 14)
		return (open_image("assets/world/14.png", mlx));
	else
		return (NULL);
}

static mlx_image_t	*find_road_tile2(int type, mlx_t *mlx)
{
	if (type == 15)
		return (open_image("assets/world/15.png", mlx));
	else if (type == 17)
		return (open_image("assets/world/17.png", mlx));
	else if (type == 18)
		return (open_image("assets/world/18.png", mlx));
	else if (type == 19)
		return (open_image("assets/world/19.png", mlx));
	else if (type == 20)
		return (open_image("assets/world/20.png", mlx));
	else if (type == 22)
		return (open_image("assets/world/22.png", mlx));
	else if (type == 23)
		return (open_image("assets/world/23.png", mlx));
	else
		return (NULL);
}
