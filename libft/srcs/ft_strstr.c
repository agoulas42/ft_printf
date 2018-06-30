/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:44:31 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:15:43 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;

	i = 0;
	if ((ft_strcmp(haystack, "") == 0) && (ft_strcmp(needle, "") == 0))
		return ((char*)haystack);
	if (haystack)
	{
		if (ft_strcmp(needle, "") == 0)
			return ((char*)haystack);
		while ((char)haystack[i] != '\0')
		{
			j = 0;
			while ((char)haystack[i + j] == needle[j] && needle[j] != '\0')
			{
				if (needle[j + 1] == '\0')
					return ((char*)haystack + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
