/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:53:43 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:15:12 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*s1;
	unsigned char	d;
	int				i;

	s1 = (unsigned char*)s;
	d = (unsigned char)c;
	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (i >= 0)
	{
		if (s1[i] == d)
			return ((char*)s1 + i);
		i--;
	}
	if (c == '\0')
		return ((char*)s1 + i);
	return (NULL);
}
