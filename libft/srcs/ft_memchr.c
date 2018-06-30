/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:00:15 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:04:10 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*tmp;
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
		{
			tmp = &((char *)s)[i];
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
