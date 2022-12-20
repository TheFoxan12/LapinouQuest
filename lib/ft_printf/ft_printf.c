/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:31:05 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/08 11:11:23 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		nb_affiches;
	int		error;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	nb_affiches = 0;
	error = 0;
	while (format[i])
	{
		if (format[i] != '%')
			nb_affiches += printf_putchar(format[i], &error);
		else
			nb_affiches += printf_print(args, format[++i], &error);
		if (format[i])
			i++;
		if (error == -1)
			return (-1);
	}
	return ((nb_affiches * (error + 1)) + error);
}

int	printf_print(va_list args, char format, int *error)
{
	int	nb;

	nb = 0;
	if (format == 'c')
		nb = printf_putchar((char) va_arg(args, int), error);
	if (format == 's')
		nb = printf_putstr((char *) va_arg(args, char *), error);
	if (format == 'p')
	{
		nb += printf_putstr("0x", error);
		nb += printf_putptr((unsigned long long)
				va_arg(args, unsigned long long), error);
	}
	if (format == 'd' || format == 'i')
		nb = printf_putnbr((int) va_arg(args, int), error);
	if (format == 'u')
		nb = printf_putnbrp((unsigned int) va_arg(args, unsigned int), error);
	if (format == 'x')
		nb = printf_puthexmin((unsigned int)
				va_arg(args, unsigned int), error);
	if (format == 'X')
		nb = printf_puthexmax((unsigned int) va_arg(args, unsigned int), error);
	if (format == '%')
		nb = printf_putpurc(error);
	return (nb);
}

int	printf_verif(int n, int *error)
{
	if (n == -1)
		*error = -1;
	return (n);
}
