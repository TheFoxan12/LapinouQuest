/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:04:02 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/01 13:04:03 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_cell		***map;
	t_max		max;
	t_lapinou	lapinou;
	t_param		param;

	map = map_init(argc, argv, &max);
	mlx = mlx_init(64 * max.xm, 64 * max.ym,
			"So long and thx for all the carrots", 1);
	param.max = &max;
	param.map = map;
	if (map == NULL || !verify_map(&param))
		return (1);
	param.mlx = mlx;
	lapinou_init(&lapinou, &param);
	param.lapinou = &lapinou;
	param.nb_moves = atoi(argv[2]);
	ft_printf("%d coups max pour celui là ^^\n");
	open_tiles(map, &max, mlx);
	display_map(mlx, map, &max);
	lapinou_display(&lapinou, mlx);
	loops(&param);
	free_map(map, &max, mlx);
	lapinou_free(&lapinou, mlx);
	mlx_terminate(mlx);
	return (0);
}

t_cell	***map_init(int argc, char **argv, t_max *max)
{
	t_cell	***map;
	int		fd;

	if (verify_arguments(argc, argv))
		return (NULL);
	map = NULL;
	fd = open_map(argv[1]);
	if (fd == -1)
		return (NULL);
	map = parse(fd, map, max);
	if (map == NULL)
	{
		ft_printf("Error\nMap Error Couldn't Parse The Map\n");
		return (NULL);
	}
	return (map);
}

void	loops(t_param *param)
{
	mlx_key_hook(param->mlx, inputs, param);
	mlx_loop_hook(param->mlx, update, param);
	mlx_loop(param->mlx);
}
