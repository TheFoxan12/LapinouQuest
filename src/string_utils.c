/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:04:36 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/07 14:04:37 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_nb_moves(int nb_moves, t_param *param)
{
	char	*nb;
	char	*txt;
	char	*txt2;

	mlx_delete_image(param->mlx, param->count);
	nb = ft_itoa(nb_moves);
	txt = ft_strjoin("Lapinou a parcouru ", nb);
	txt2 = ft_strjoin(txt, " cases.");
	param->count = mlx_put_string(param->mlx, txt2, 10, 10);
	free(nb);
	free(txt);
	free(txt2);
}
