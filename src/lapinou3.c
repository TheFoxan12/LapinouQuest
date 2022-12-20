/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lapinou3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:04 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/05 15:31:06 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	lapinou_eat(t_param *param)
{
	if (param->map[param->lapinou->y][param->lapinou->x]->type == 1)
	{
		param->lapinou->carrots++;
		param->map[param->lapinou->y][param->lapinou->x]->type = 4;
		if (param->lapinou->carrots != param->lapinou->want)
			ft_printf("Lapinou a deja mange %d carottes.\n",
				param->lapinou->carrots);
		else
			ft_printf("Lapinou a mange toutes les carottes (%d) "
				"!\nIl peut y aller.\n",
				param->lapinou->want);
	}
}

int lapinou_exit(t_param *param)
{
	if (param->map[param->lapinou->y][param->lapinou->x]->type == 3)
	{
		if (param->lapinou->carrots == param->lapinou->want)
		{
			ft_printf("gg!\n");
			mlx_close_window(param->mlx);
			return (1);
		}
		else
			ft_printf("Il faut manger toutes les carottes avant de sortir !\n");
	}
	return (0);
}

void	lapinou_max_moves(t_param *param)
{
	if (param->nb_moves == param->lapinou->nb_moves)
	{
		ft_printf("Trop de mouvements ! Lapinou est trop fatigué... Perdu !\n");
		mlx_close_window(param->mlx);
	}
}
