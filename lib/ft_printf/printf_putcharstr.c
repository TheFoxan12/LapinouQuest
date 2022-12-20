/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putcharstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:29:42 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/07 11:29:44 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_putchar(char c, int *error)
{
	long long	n;

	n = 0;
	if (*error != -1)
	{
		n = write(1, &c, 1);
		printf_verif(n, error);
	}
	return (n);
}

int	printf_putstr(const char *str, int *error)
{
	int	i;
	int	n;

	if (str == NULL)
	{
		n = printf_putstr("(null)", error);
		return (n);
	}
	i = 0;
	while (str[i])
	{
		printf_putchar(str[i], error);
		i++;
	}
	return (i);
}
