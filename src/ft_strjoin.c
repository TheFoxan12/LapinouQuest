/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ^@^ Foxan ^@^ <thibaut.unsinger@gmail.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:28:06 by ^@^ Foxan ^@^     #+#    #+#             */
/*   Updated: 2022/11/02 10:28:07 by ^@^ Foxan ^@^    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	lenstr(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = malloc((lenstr(s1) + lenstr(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		res[lenstr(s1) + i] = s2[i];
		i++;
	}
	res[lenstr(s1) + lenstr(s2)] = 0;
	return (res);
}

static int	lenstr(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}
