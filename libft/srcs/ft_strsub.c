/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:56:04 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:15:54 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tr;
	size_t	i;

	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	if ((tr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while ((i < (len)) && (s[start + i] != '\0'))
	{
		tr[i] = s[start + i];
		i++;
	}
	tr[i] = '\0';
	return (tr);
}
