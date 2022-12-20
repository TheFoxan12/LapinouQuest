/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnrbs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:43:39 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/07 11:43:40 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	smallest_integer(int *error);

int	printf_putnbr(int n, int *error)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (smallest_integer(error));
	else if (n < 0)
	{
		count += printf_putchar('-', error);
		n = -n;
	}
	if (n / 10 != 0)
	{
		count += printf_putnbr(n / 10, error);
	}
	c = '0' + n % 10;
	count += printf_putchar(c, error);
	return (count);
}

static int	smallest_integer(int *error)
{
	int	e;

	e = printf_putstr("-2147483648", error);
	return (e);
}

int	printf_putnbrp(unsigned int un, int *error)
{
	int		nb;
	int		count;
	char	c;

	count = 0;
	nb = un / 10;
	if (nb != 0)
		count += printf_putnbr(nb, error);
	c = '0' + un % 10;
	count += printf_putchar(c, error);
	return (count);
}

int	printf_putpurc(int *error)
{
	int	n;

	n = printf_putchar('%', error);
	return (n);
}
