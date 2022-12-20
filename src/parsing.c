/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:40:30 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/25 14:40:31 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_cell	***parse(int fd, t_cell ***map, t_max *mx)
{
	char	*line;

	mx->ym = 0;
	while (store_next_line(&line, fd), line)
	{
		map = extend_map(map, mx);
		if (map == NULL)
			return (NULL);
		map[mx->ym] = malloc(len_line(line) * sizeof(t_cell *));
		if (map[mx->ym] == NULL)
			return (free_map(map, mx, NULL));
		mx->xm = -1;
		while (line[++mx->xm] && line[mx->xm] != '\n')
		{
			if (new_cell(line[mx->xm], map, mx->ym, mx->xm) == NULL)
				return (free_map(map, mx, NULL));
		}
		(mx->ym)++;
		free(line);
	}
	close(fd);
	return (map);
}

int	len_line(const char *line)
{
	int			len;
	static int	last_len = 0;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (last_len != len && last_len != 0)
	{
		ft_printf("Error\nMap Error Inconsistent Length\n");
		return (-1);
	}
	last_len = len;
	return (len);
}

t_cell	*new_cell(char type, t_cell ***map, int i, int j)
{
	t_cell	*tmp;

	tmp = malloc(sizeof(t_cell));
	if (tmp == NULL)
		return (NULL);
	tmp->num = 0;
	tmp->type = 0;
	tmp->testing = 0;
	if (type == '0')
		tmp->type = 4;
	else if (type == 'C')
		tmp->type = 1;
	else if (type == 'P')
		tmp->type = 2;
	else if (type == 'E')
		tmp->type = 3;
	else if (type == '1')
		tmp->testing = 1;
	else
	{
		ft_printf("Error\nMap Error Unknown Character\n");
		return (NULL);
	}
	map[i][j] = tmp;
	return (tmp);
}

void	store_next_line(char **line, int fd)
{
	*line = get_next_line(fd);
}

t_cell	***extend_map(t_cell ***map, t_max *max)
{
	t_cell	***new_map;
	int		i;

	new_map = malloc((max->ym + 1) * sizeof(t_cell **));
	if (new_map == NULL)
		return (NULL);
	i = 0;
	while (i < max->ym)
	{
		new_map[i] = map[i];
		i++;
	}
	if (map != NULL)
		free(map);
	return (new_map);
}
