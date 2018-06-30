/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:03:31 by agoulas           #+#    #+#             */
/*   Updated: 2018/04/24 15:14:09 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtolower(char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if ((str = ft_strnew(ft_strlen(s))) == NULL)
		return (0);
	while (s[i])
	{
		str[i] = ft_tolower(s[i]);
		i++;
	}
	return (str);
}
