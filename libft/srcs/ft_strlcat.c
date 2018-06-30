/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:27:59 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:13:20 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		lsrc;
	size_t		ldst;
	size_t		j;

	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	j = 0;
	if (size == 0)
		return (lsrc);
	if (size <= ldst)
		return (lsrc + size);
	if (size > 0)
		ft_strncat(dst, src, (size - ldst - 1));
	if (lsrc < (size - ldst))
		dst[ldst + lsrc] = '\0';
	return (ldst + lsrc);
}
