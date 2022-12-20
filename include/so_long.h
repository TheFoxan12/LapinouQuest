/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:44:28 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/25 14:44:29 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*stucts*/
typedef struct s_cell {
	int			type;
	int			num;
	int			testing;
	mlx_image_t	*image;
	mlx_image_t	*image_spe;
}	t_cell;

typedef struct s_max {
	int	xm;
	int	ym;
}	t_max;

typedef struct s_lapinou {
	int			x;
	int			y;
	int			facing;
	int			nb_moves;
	int			carrots;
	int			want;
	mlx_image_t	*ci;
	mlx_image_t	*in;
	mlx_image_t	*ie;
	mlx_image_t	*is;
	mlx_image_t	*iw;
}	t_lapinou;

typedef struct s_param {
	t_lapinou	*lapinou;
	t_cell		***map;
	t_max		*max;
	mlx_t		*mlx;
	mlx_image_t	*count;
	int			nb_moves;
}	t_param;

/*map*/
int			open_map(char *map_path);
int			len_line(const char *line);
int			count_collectibles(t_cell ***map, t_max *max);
int			is_closed(t_cell ***map, t_max *max);
int			verify_map(t_param *param);
int			verify_path(t_param *param, int collectibles);
int			verify_arguments(int argc, char **argv);
int			propagate(t_param *param, int x, int y, int collectibles);
void		store_next_line(char **line, int fd);
void		open_tiles(t_cell ***map, t_max *max, mlx_t *mlx);
void		update_type(t_cell ***map, int x, int y, t_max *max);
void		display_map(mlx_t *mlx, t_cell ***map, t_max *max);
void		*free_map(t_cell ***map, t_max *max, mlx_t *mlx);
t_cell		***parse(int fd, t_cell ***map, t_max *mx);
t_cell		*new_cell(char type, t_cell ***map, int i, int j);
t_cell		***extend_map(t_cell ***map, t_max *max);
mlx_image_t	*find_tile(int type, mlx_t *mlx);
mlx_image_t	*find_tile_spe(int type, mlx_t *mlx);
t_cell		***map_init(int argc, char **argv, t_max *max);
void		loops(t_param *param);

/*lapinou*/
void		lapinou_place(t_lapinou *lapinou, t_cell ***map, t_max *max);
void		lapinou_open_image(t_lapinou *lapinou, mlx_t *mlx);
void		lapinou_free(t_lapinou *lapinou, mlx_t *mlx);
void		lapinou_display(t_lapinou *lapinou, mlx_t *mlx);
void		lapinou_init(t_lapinou *lapinou, t_param *param);
void		lapinou_rotate(t_lapinou *lapinou, int direction);
void		lapinou_move_n(t_lapinou *lapinou, t_param *param);
void		lapinou_move_e(t_lapinou *lapinou, t_param *param);
void		lapinou_move_s(t_lapinou *lapinou, t_param *param);
void		lapinou_move_w(t_lapinou *lapinou, t_param *param);
void		lapinou_eat(t_param *param);
int lapinou_exit(t_param *param);
void		lapinou_max_moves(t_param *param);

/*hooks*/
void		inputs(mlx_key_data_t keydata, void *param);
void		update(void *param);

/*count*/
void		display_count(t_param *param, int count, int i);
void		display_num(t_param *param, int num, int i);
char		*find_path(int num);

/*display*/
void		refresh(mlx_t *mlx, t_cell ***map, int x, int y);
mlx_image_t	*open_image(char *path, mlx_t *mlx);
void		display_nb_moves(int nb_moves, t_param *param);

/*strings*/
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);

#endif /* SO_LONG_H */
