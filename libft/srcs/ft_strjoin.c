/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:14:46 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/12 17:13:12 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char*)malloc(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < (ft_strlen(s1)))
	{
		new[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s2) + ft_strlen(s1)))
	{
		new[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	new[i] = '\0';
	return (new);
}
