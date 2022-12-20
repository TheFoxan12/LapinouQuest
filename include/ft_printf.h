/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:40:24 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/07 10:40:26 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	printf_verif(int n, int *error);
int	printf_print(va_list args, char format, int *error);
int	printf_putchar(char c, int *error);
int	printf_putstr(const char *str, int *error);
int	printf_putptr(unsigned long long ptr, int *error);
int	printf_putnbr(int n, int *error);
int	printf_putnbrp(unsigned int un, int *error);
int	printf_puthexmin(unsigned int n, int *error);
int	printf_puthexmax(unsigned int n, int *error);
int	printf_putpurc(int *error);

#endif //FT_PRINTF_H
