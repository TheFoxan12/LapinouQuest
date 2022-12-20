/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lapinou2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:16:18 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/05 12:16:20 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	lapinou_rotate(t_lapinou *lapinou, int direction)
{
	lapinou->facing = direction;
}

void	lapinou_move_n(t_lapinou *lapinou, t_param *param)
{
	if (lapinou->y - 1 >= 0)
	{
		if (param->map[lapinou->y - 1][lapinou->x]->type > 0)
		{
			lapinou->nb_moves++;
			refresh(param->mlx, param->map, lapinou->x, lapinou->y);
			lapinou->y -= 1;
			lapinou_rotate(lapinou, 0);
			lapinou_display(lapinou, param->mlx);
			display_count(param, lapinou->nb_moves, 0);
			display_nb_moves(lapinou->nb_moves, param);
			lapinou_eat(param);
			if (!lapinou_exit(param))
				lapinou_max_moves(param);
		}
	}
}

void	lapinou_move_e(t_lapinou *lapinou, t_param *param)
{
	if (lapinou->x + 1 < param->max->xm)
	{
		if (param->map[lapinou->y][lapinou->x + 1]->type > 0)
		{
			lapinou->nb_moves++;
			refresh(param->mlx, param->map, lapinou->x, lapinou->y);
			lapinou->x += 1;
			lapinou_rotate(lapinou, 1);
			lapinou_display(lapinou, param->mlx);
			display_count(param, lapinou->nb_moves, 0);
			display_nb_moves(lapinou->nb_moves, param);
			lapinou_eat(param);
			if (!lapinou_exit(param))
				lapinou_max_moves(param);
		}
	}
}

void	lapinou_move_s(t_lapinou *lapinou, t_param *param)
{
	if (lapinou->y + 1 < param->max->ym)
	{
		if (param->map[lapinou->y + 1][lapinou->x]->type > 0)
		{
			lapinou->nb_moves++;
			refresh(param->mlx, param->map, lapinou->x, lapinou->y);
			lapinou->y += 1;
			lapinou_rotate(lapinou, 2);
			lapinou_display(lapinou, param->mlx);
			display_count(param, lapinou->nb_moves, 0);
			display_nb_moves(lapinou->nb_moves, param);
			lapinou_eat(param);
			if (!lapinou_exit(param))
				lapinou_max_moves(param);
		}
	}
}

void	lapinou_move_w(t_lapinou *lapinou, t_param *param)
{
	if (lapinou->x - 1 >= 0)
	{
		if (param->map[lapinou->y][lapinou->x - 1]->type > 0)
		{
			lapinou->nb_moves++;
			refresh(param->mlx, param->map, lapinou->x, lapinou->y);
			lapinou->x -= 1;
			lapinou_rotate(lapinou, 3);
			lapinou_display(lapinou, param->mlx);
			display_count(param, lapinou->nb_moves, 0);
			display_nb_moves(lapinou->nb_moves, param);
			lapinou_eat(param);
			if (!lapinou_exit(param))
				lapinou_max_moves(param);
		}
	}
}
