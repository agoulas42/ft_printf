/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_from_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:18:58 by agoulas           #+#    #+#             */
/*   Updated: 2018/06/25 19:04:15 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcpy_from_to(char *dest, char *src, int start, int length)
{
	int i;

	i = 0;
	if (src != NULL && dest != NULL)
	{
		while (dest[start + i] && src[i] && i < length)
		{
			dest[start + i] = src[i];
			i++;
		}
		return (dest);
	}
	return (dest);
}
