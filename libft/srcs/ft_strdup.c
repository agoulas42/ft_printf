/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:07:28 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/20 16:09:19 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*c;
	int		l;
	int		i;

	l = ft_strlen(src);
	if (src == NULL || (c = (char *)ft_memalloc((l + 1))) == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (src && src[i] != '\0')
		{
			c[i] = src[i];
			i++;
		}
		c[i] = '\0';
		return (c);
	}
}
