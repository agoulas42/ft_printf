/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 11:09:51 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:15:04 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] && (i + j) < len && hay[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char*)hay + i);
		i++;
	}
	return (NULL);
}
