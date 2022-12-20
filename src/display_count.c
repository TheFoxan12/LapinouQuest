/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:23:28 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/05 14:23:29 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_count(t_param *param, int count, int i)
{
	if (count > 0)
	{
		display_count(param, count / 10, i + 1);
		display_num(param, count % 10, i);
	}
}

void	display_num(t_param *param, int num, int i)
{
	mlx_image_t	*img;
	char		*path;

	(void)i;
	path = find_path(num);
	img = open_image(path, param->mlx);
	refresh(param->mlx, param->map,
		param->max->xm - i - 1, 0);
	mlx_image_to_window(param->mlx, img,
		((param->max->xm) * 64) - (i * 64) - 64, 0);
}

char	*find_path(int num)
{
	char	*path;

	if (num == 0)
		path = "assets/numbers/0.png";
	else if (num == 1)
		path = "assets/numbers/1.png";
	else if (num == 2)
		path = "assets/numbers/2.png";
	else if (num == 3)
		path = "assets/numbers/3.png";
	else if (num == 4)
		path = "assets/numbers/4.png";
	else if (num == 5)
		path = "assets/numbers/5.png";
	else if (num == 6)
		path = "assets/numbers/6.png";
	else if (num == 7)
		path = "assets/numbers/7.png";
	else if (num == 8)
		path = "assets/numbers/8.png";
	else if (num == 9)
		path = "assets/numbers/9.png";
	else
		path = NULL;
	return (path);
}
