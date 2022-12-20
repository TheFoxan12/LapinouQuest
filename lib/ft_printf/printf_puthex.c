/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_puthex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:13:26 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/08 11:11:27 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbrhexmin(unsigned int n, int *error);
static int	putnbrhexmax(unsigned int n, int *error);

int	printf_puthexmin(unsigned int n, int *error)
{
	int		nb;
	int		count;

	count = 0;
	nb = n / 16;
	if (nb != 0)
		count += printf_puthexmin(nb, error);
	putnbrhexmin(n, error);
	return (count + 1);
}

int	printf_puthexmax(unsigned int n, int *error)
{
	int		nb;
	int		count;

	count = 0;
	nb = n / 16;
	if (nb != 0)
		count += printf_puthexmax(nb, error);
	putnbrhexmax(n, error);
	return (count + 1);
}

int	printf_putptr(unsigned long long ptr, int *error)
{
	unsigned long long	nb;
	int					count;

	count = 0;
	nb = ptr / 16;
	if (nb != 0)
		count += printf_putptr(nb, error);
	putnbrhexmin(ptr, error);
	return (count + 1);
}

static int	putnbrhexmin(unsigned int n, int *error)
{
	unsigned char	c;
	int				e;

	n = n % 16;
	if (n < 10)
	{
		c = '0' + n;
		e = printf_putchar(c, error);
		return (e);
	}
	if (n == 10)
		e = printf_putchar('a', error);
	if (n == 11)
		e = printf_putchar('b', error);
	if (n == 12)
		e = printf_putchar('c', error);
	if (n == 13)
		e = printf_putchar('d', error);
	if (n == 14)
		e = printf_putchar('e', error);
	if (n == 15)
		e = printf_putchar('f', error);
	return (e);
}

static int	putnbrhexmax(unsigned int n, int *error)
{
	unsigned char	c;
	int				e;

	n = n % 16;
	if (n < 10)
	{
		c = '0' + n;
		e = printf_putchar(c, error);
		return (e);
	}
	if (n == 10)
		e = printf_putchar('A', error);
	if (n == 11)
		e = printf_putchar('B', error);
	if (n == 12)
		e = printf_putchar('C', error);
	if (n == 13)
		e = printf_putchar('D', error);
	if (n == 14)
		e = printf_putchar('E', error);
	if (n == 15)
		e = printf_putchar('F', error);
	return (e);
}
