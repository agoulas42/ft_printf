/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:42:46 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:15:26 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	i = i - 1;
	while (i > n)
	{
		tmp = str[i];
		str[i] = str[n];
		str[n] = tmp;
		i = i - 1;
		n = n + 1;
	}
	return (str);
}
