/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:28:15 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/12/02 14:28:16 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	len_str(const char *str);

int	verify_arguments(int argc, char **argv)
{
	int	len;

	if (argc < 3)
	{
		ft_printf("Error\nArgument Error Too Few Arguments\n");
		return (1);
	}
	else if (argc > 3)
	{
		ft_printf("Error\nArgument Error Too Many Arguments\n");
		return (1);
	}
	len = len_str(argv[1]);
	if (argv[1][len - 1] != 'r' || argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
	{
		ft_printf("Error\nArgument Error Not A Map\n");
		return (1);
	}
	return (0);
}

static int	len_str(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
