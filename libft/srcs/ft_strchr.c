/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:46:34 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:10:44 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	tmp;
	unsigned char	*st;

	i = 0;
	st = (unsigned char*)s;
	tmp = (unsigned char)c;
	while (st[i] != '\0')
	{
		if (st[i] == c)
			return ((char*)s + i);
		if (st[i] == '\0')
			return (NULL);
		i++;
	}
	if (c == '\0')
		return ((char*)s + i);
	return (NULL);
}
