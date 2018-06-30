/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:57:21 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:09:35 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	unsigned char		*csrc;
	unsigned char		*cdst;
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	csrc = (unsigned char*)src;
	cdst = (unsigned char*)dst;
	while (cdst[i])
		i++;
	while (src[j] != '\0')
	{
		cdst[i] = csrc[j];
		i++;
		j++;
	}
	cdst[i] = '\0';
	return (dst);
}
