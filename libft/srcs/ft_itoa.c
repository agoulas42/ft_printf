/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:34:46 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:01:54 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		ft_dizaine(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_conversion(int abs, int n, int index)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	if ((string = (char*)malloc(sizeof(char) * (index + 1))) == NULL)
		return (NULL);
	if (n < 0)
	{
		string[0] = '-';
		i++;
	}
	j = index - 1;
	while (i <= j)
	{
		string[j] = (abs % 10) + '0';
		abs = abs / 10;
		j--;
	}
	string[index] = '\0';
	return (string);
}

char			*ft_itoa(int n)
{
	int		abs;
	int		index;

	abs = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	index = ft_dizaine(n);
	if (n < 0)
	{
		abs = -n;
		index++;
	}
	else
		abs = n;
	return (ft_conversion(abs, n, index));
}
