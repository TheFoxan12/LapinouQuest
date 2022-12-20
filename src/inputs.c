/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:23:03 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/05 12:23:04 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	inputs(mlx_key_data_t keydata, void *param)
{
	t_param	*tmp;

	tmp = ((t_param *)param);
	if (keydata.action == 1 || keydata.action == 2)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(tmp->mlx);
		if (keydata.key == MLX_KEY_W)
			lapinou_move_n(tmp->lapinou, tmp);
		if (keydata.key == MLX_KEY_D)
			lapinou_move_e(tmp->lapinou, tmp);
		if (keydata.key == MLX_KEY_S)
			lapinou_move_s(tmp->lapinou, tmp);
		if (keydata.key == MLX_KEY_A)
			lapinou_move_w(tmp->lapinou, tmp);
	}
}
